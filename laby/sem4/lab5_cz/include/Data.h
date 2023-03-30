#ifndef Data_h
#define Data_h

#include "Visitor.h"

// Klasa abstrakcyjna definiująca interfejs do kontenerów na liczby
class Data {
  public:
    virtual ~Data(){}
    virtual void accept( const Visitor& v) = 0;
    virtual void accept( Visitor& v) = 0;
};

// wizytowalny konetener na liczbe typu int
class IntData : public Data {
  public:
    IntData( int d ) : m_d( d ){}

    // zmienia zawartosc kontenera
    void operator<<( int d ) { m_d = d; }

    // zawartosc kontenera
    int get() const { return m_d; }
    //
    void accept( const Visitor& v) override { v.visit( this ); };
    void accept( Visitor& v) override { v.visit( this ); };

  private:
    int m_d;
};

// see IntData
class FloatData : public Data {
  public:
    FloatData( float d ) : m_d( d ){}
    //
    void operator<<( float d ) { m_d = d; }

    // zawartosc kontenera
    float getValue() const { return m_d; }

    //
    void accept( const Visitor& v) override { v.visit( this ); };
    void accept( Visitor& v) override { v.visit( this ); };

  private:
    float m_d; 
};

#endif // Data_h