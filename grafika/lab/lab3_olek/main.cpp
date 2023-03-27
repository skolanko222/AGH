#include "Picture.h"
#include <memory>
class MyApp : public wxApp
{
public:
	virtual bool OnInit() {
		Picture* pic = new Picture();
		pic->Show(true);
		return true;
	}
};
wxIMPLEMENT_APP(MyApp);