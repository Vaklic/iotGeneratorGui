///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/radiobox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/dialog.h>

#include "callBenchmark.h"
#include "library.hpp"

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class infoDialog;

class mainAppFrame : public wxFrame {
	private:
	
	protected:
		wxMenuBar* m_mainMenuBar;
		wxMenu* m_mainMenu;
		wxMenu* m_appInfo;
		wxRadioBox* m_radioGenerationRule;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl2;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl3;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrl10;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrl11;
		wxRadioBox* m_radioNetworkInterface;
		wxStaticText* m_staticText6;
		wxTextCtrl* m_textCtrl5;
		wxStaticText* m_staticText7;
		wxTextCtrl* m_textCtrl6;
		wxStaticText* m_staticText8;
		wxTextCtrl* m_textCtrl7;
		wxStaticText* m_staticText9;
		wxTextCtrl* m_textCtrl8;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_textCtrl9;
		wxButton* m_buttonStart;
		wxButton* m_buttonStop;
		wxButton* m_buttonResrart;
		wxButton* m_buttonAccept;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onClickSubMenuRestart( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickSubMenuCapture( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickSubMenuExit( wxCommandEvent& event ); //{ Destroy(); }
		virtual void onClickProgrammInfo( wxCommandEvent& event );// { event.Skip(); }
		virtual void onClickGenerationRule( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickNetworkInterface( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickButtonStart( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickButtonStop( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickButtonResrart( wxCommandEvent& event ); //{ event.Skip(); }
		virtual void onClickButtonAccept( wxCommandEvent& event ); //{ event.Skip(); }
		void readValuesFromGUI(void);
		
	public:
		int16_t selectTrafficType; 
		int32_t iotDevNumber; 
		int64_t delayTime; 
		uint64_t antiDelayDuration; 
		uint64_t antiSendDuration; 
		int switchInterfaceType; 
		uint64_t quantityOfPackage; 
		int16_t dataFieldLength; 
		std::string srcNetAdr; 
		std::string desNetAdr; 
		std::string networkMask; 
		
		bool stopGeneratorFlag;
		std::thread stopGeneratorThread;
		
		callBenchmark* proceedBenchmark;
		infoDialog* infoWindow;
		
		std::thread startGeneratorThread;
		
		void startGeneratorFunction(callBenchmark** _proceedBenchmark);
		void stopGeneratorFunction(bool* _stopGeneratorFlag, callBenchmark** _proceedBenchmark);
		
		mainAppFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Генератор трафика Интернет Вещей"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,420 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~mainAppFrame();
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class infoDialog : public wxDialog {
	private:
	
	protected:
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
	
		void OnExitClick(wxCommandEvent& event);
		void OnCloseFrame(wxCloseEvent& event);
		
	public:
		
		infoDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("О программе"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 443,260 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~infoDialog();
	
};

#endif //__GUI_H__
