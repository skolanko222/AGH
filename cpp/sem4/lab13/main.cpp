// ZADANIE WYKONYWANE W TRYBIE ZDALNYM, NIE NA OCENE
// zachęcam do samodzielnego wykonywania! 
//
// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest napisanie pomocniczej klasy AccountState, ktora pozwala 
// na odwołanie operacji. Jak to jest wykonywane powinno być jasne po przeczytaniu
// definicji klasy Msg.
// 
// UWAGA: Proszę zauważyć że w tryFail() ostanią funkcją jest funkcja statyczna
// AccountState::AllOk() która nie jest wywoływana.  
// 
// UWAGA: KeepInt musi przechować zarówno wartość początkową jak i
// referencje do miejsca gdzie można odłozyć te wartość jeśli undo jest wywołane.
// Polecam wykonanie tego zadania dla KeepInt -> KeepValue w wersji szablonowej,
// dla różnych typów...
//
// Pliku main.cpp, nie wolno modyfikowac.
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny 
// i dobrze napisany kod), oraz powinna być spełniona zasada D.R.Y. 
// - Don't Repeat Yourself.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp) 
// należy wgrać do UPEL jako archiwum tar.gz, 
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab13/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include <stdexcept>
// #include "TransactionAction.h"
namespace Transaction 
{
	class UndoAction 
	{
		public:
			virtual ~UndoAction() {}
			virtual void Init() = 0;
			virtual void Ok() = 0;
			virtual void Fail() = 0;
	};

	class AccountState 
	{
		static AccountState* _current;
		UndoAction* _action;
		
		public:
			AccountState(UndoAction* action) : _action(action) 
			{
				_action->Init();
				_current = this;
			}
		~AccountState() {
			if ( _current == this ) 
			{
			_current = nullptr;
		}
	}
	static void AllOk() {
	  if ( _current ) {
		_current->_action->Ok();
	  }
	}
	static void AllFail() {
	  if ( _current ) {
		_current->_action->Fail();
	  }
	}
  };
  AccountState* AccountState::_current = nullptr;
	class KeepInt : public Transaction::UndoAction 
	{
		private:
			int& _value;
			int _oldValue;
		public:
			KeepInt(int& value) : _value(value), _oldValue(value) {}
			void Init() override {}
			void Ok() override {}
			void Fail() override {_value = _oldValue;}
	};

}



class Msg : public Transaction::UndoAction {
  void Init() override {
    std::cout << "Entering transaction" << std::endl;
  }
  void Ok() override {
    std::cout << "Finished transaction" << std::endl;
  }
  void Fail() override {
    std::cout << "Broken transaction" << std::endl;
  }
  
};

int konto1 = 100;
int konto2 = 20;

void tryOk() {
  Transaction::AccountState msg(new Msg());
  const int wartoscPrzelewu = 11;
  // Uwaga: trick w tym zadaniu jest tutaj, musimy przechowac referencje do int: 
  // konto1 aby, móc potencjalnie zmienić jego wartość gdy transakcja się nie powiedzie
  Transaction::AccountState k1(new Transaction::KeepInt(konto1)); 
  Transaction::AccountState k2(new Transaction::KeepInt(konto2));
  konto1 -= wartoscPrzelewu;
  konto2 += wartoscPrzelewu;
  Transaction::AccountState::AllOk();
}


void tryFail() {
  Transaction::AccountState msg(new Msg());
  const int wartoscPrzelewu = 14;
  Transaction::AccountState k1(new Transaction::KeepInt(konto1));
  Transaction::AccountState k2(new Transaction::KeepInt(konto2));
  konto1 -= wartoscPrzelewu;
  throw std::runtime_error("Tranzakcja przerwana z nieznanej przyczyny");
  konto2 += wartoscPrzelewu;  
  Transaction::AccountState::AllOk();
}


int main() {
  try {
    tryOk();
    std::cout  << "konto1 " << konto1 << " konto2 " << konto2 << "\n" << std::endl;
    tryFail();
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
    std::cout  << "konto1 " << konto1 << " konto2 " << konto2 << std::endl;
  }
  
}
/* wynik
Entering transaction
Finished transaction
konto1 89 konto2 31
Entering transaction
Broken transaction
Tranzakcja przerwana z nieznanej przyczyny
konto1 89 konto2 31
 */