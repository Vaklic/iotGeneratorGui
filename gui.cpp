///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  5 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

mainAppFrame::mainAppFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style ) {
	this->SetSizeHints( wxSize( 620,420 ), wxSize( 720,520 ) );
	
	m_mainMenuBar = new wxMenuBar( 0 );
	m_mainMenu = new wxMenu();
	wxMenuItem* m_menuRestart;
	m_menuRestart = new wxMenuItem( m_mainMenu, wxID_ANY, wxString( wxT("Перезапуск") ) , wxEmptyString, wxITEM_NORMAL );
	m_mainMenu->Append( m_menuRestart );
	
	wxMenuItem* m_menuCaptureTraffic;
	m_menuCaptureTraffic = new wxMenuItem( m_mainMenu, wxID_ANY, wxString( wxT("Захват трафика") ) , wxEmptyString, wxITEM_NORMAL );
	m_mainMenu->Append( m_menuCaptureTraffic );
	
	m_mainMenu->AppendSeparator();
	
	wxMenuItem* m_menuExit;
	m_menuExit = new wxMenuItem( m_mainMenu, wxID_ANY, wxString( wxT("Выход") ) , wxEmptyString, wxITEM_NORMAL );
	m_mainMenu->Append( m_menuExit );
	
	m_mainMenuBar->Append( m_mainMenu, wxT("Меню") ); 
	
	m_appInfo = new wxMenu();
	wxMenuItem* m_menuAppInfo;
	m_menuAppInfo = new wxMenuItem( m_appInfo, wxID_ANY, wxString( wxT("О программе") ) , wxEmptyString, wxITEM_NORMAL );
	m_appInfo->Append( m_menuAppInfo );
	
	m_mainMenuBar->Append( m_appInfo, wxT("Информация") ); 
	
	this->SetMenuBar( m_mainMenuBar );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxString m_radioGenerationRuleChoices[] = { wxT("Самоподобный"), wxT("Антиперсистентный") };
	int m_radioGenerationRuleNChoices = sizeof( m_radioGenerationRuleChoices ) / sizeof( wxString );
	m_radioGenerationRule = new wxRadioBox( this, wxID_ANY, wxT("Характер трафика"), wxDefaultPosition, wxSize( 240,75 ), m_radioGenerationRuleNChoices, m_radioGenerationRuleChoices, 1, wxRA_SPECIFY_COLS );
	m_radioGenerationRule->SetSelection( 0 );
	bSizer1->Add( m_radioGenerationRule, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Количество ИВ:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer2->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl2 = new wxTextCtrl( this, wxID_ANY, wxT("10000"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer2->Add( m_textCtrl2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer1->Add( gSizer2, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Интервал отправки:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer3->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxT("100000"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer3->Add( m_textCtrl3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer1->Add( gSizer3, 1, wxEXPAND, 5 );
	
	gSizer1->Add( bSizer1, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer10;
	gSizer10 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Период ожидания:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	gSizer10->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl10 = new wxTextCtrl( this, wxID_ANY, wxT("30000000"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer10->Add( m_textCtrl10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer2->Add( gSizer10, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Период отправки:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	gSizer11->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl11 = new wxTextCtrl( this, wxID_ANY, wxT("3000000"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer11->Add( m_textCtrl11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer2->Add( gSizer11, 1, wxEXPAND, 5 );
	
	wxString m_radioNetworkInterfaceChoices[] = { wxT("Ethernet 10/100/1000/10000BASE-T"), wxT("SFP/SFP+"), wxT("USB-LTE Modem") };
	int m_radioNetworkInterfaceNChoices = sizeof( m_radioNetworkInterfaceChoices ) / sizeof( wxString );
	m_radioNetworkInterface = new wxRadioBox( this, wxID_ANY, wxT("Сетевой интерфейс"), wxDefaultPosition, wxSize( 240,100 ), m_radioNetworkInterfaceNChoices, m_radioNetworkInterfaceChoices, 1, wxRA_SPECIFY_COLS );
	m_radioNetworkInterface->SetSelection( 0 );
	bSizer2->Add( m_radioNetworkInterface, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	gSizer1->Add( bSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer5;
	gSizer5 = new wxGridSizer( 1, 2, 0, 0 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Количество пакетов:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer5->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl5 = new wxTextCtrl( this, wxID_ANY, wxT("10000"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer5->Add( m_textCtrl5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer3->Add( gSizer5, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Размер поля данных:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	gSizer6->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer6->Add( m_textCtrl6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer3->Add( gSizer6, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer7;
	gSizer7 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("IP подсети источника:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer7->Add( m_staticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl7 = new wxTextCtrl( this, wxID_ANY, wxT("192.168.10.0"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer7->Add( m_textCtrl7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer3->Add( gSizer7, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer8;
	gSizer8 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("IP подсети назначения:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	gSizer8->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl8 = new wxTextCtrl( this, wxID_ANY, wxT("31.148.99.0"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer8->Add( m_textCtrl8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer3->Add( gSizer8, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer9;
	gSizer9 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Маска подсети:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	gSizer9->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxT("255.255.255.0"), wxDefaultPosition, wxSize( 120,20 ), 0 );
	gSizer9->Add( m_textCtrl9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 7 );
	
	bSizer3->Add( gSizer9, 1, wxEXPAND, 5 );
	
	gSizer1->Add( bSizer3, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonStart = new wxButton( this, wxID_ANY, wxT("Старт"), wxDefaultPosition, wxSize( 150,30 ), 0 );
	bSizer4->Add( m_buttonStart, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonStop = new wxButton( this, wxID_ANY, wxT("Стоп"), wxDefaultPosition, wxSize( 150,30 ), 0 );
	bSizer4->Add( m_buttonStop, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonResrart = new wxButton( this, wxID_ANY, wxT("Перезапуск"), wxDefaultPosition, wxSize( 150,30 ), 0 );
	bSizer4->Add( m_buttonResrart, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonAccept = new wxButton( this, wxID_ANY, wxT("Принять настройки"), wxDefaultPosition, wxSize( 150,30 ), 0 );
	bSizer4->Add( m_buttonAccept, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	gSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	this->SetSizer( gSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_menuRestart->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickSubMenuRestart ) );
	this->Connect( m_menuCaptureTraffic->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickSubMenuCapture ) );
	this->Connect( m_menuExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickSubMenuExit ) );
	this->Connect( m_menuAppInfo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickProgrammInfo ) );
	m_radioGenerationRule->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( mainAppFrame::onClickGenerationRule ), NULL, this );
	m_radioNetworkInterface->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( mainAppFrame::onClickNetworkInterface ), NULL, this );
	m_buttonStart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonStart ), NULL, this );
	m_buttonStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonStop ), NULL, this );
	m_buttonResrart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonResrart ), NULL, this );
	m_buttonAccept->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonAccept ), NULL, this );

	this->stopGeneratorFlag = 0;
	this->infoWindow = NULL;
	this->proceedBenchmark = new callBenchmark();
	
	//this->startGeneratorThread = std::thread(NULL);
	this->stopGeneratorThread = std::thread(&mainAppFrame::stopGeneratorFunction, this, &this->stopGeneratorFlag, &this->proceedBenchmark);
	this->stopGeneratorThread.detach();
}

mainAppFrame::~mainAppFrame() {
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickSubMenuRestart ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickSubMenuCapture ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickSubMenuExit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( mainAppFrame::onClickProgrammInfo ) );
	m_radioGenerationRule->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( mainAppFrame::onClickGenerationRule ), NULL, this );
	m_radioNetworkInterface->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( mainAppFrame::onClickNetworkInterface ), NULL, this );
	m_buttonStart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonStart ), NULL, this );
	m_buttonStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonStop ), NULL, this );
	m_buttonResrart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonResrart ), NULL, this );
	m_buttonAccept->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( mainAppFrame::onClickButtonAccept ), NULL, this );

	delete this->infoWindow;
	delete this->proceedBenchmark;
}

void mainAppFrame::stopGeneratorFunction(bool* _stopGeneratorFlag, callBenchmark** _proceedBenchmark) {
	while(*_stopGeneratorFlag != true) {}
	(*_proceedBenchmark)->setControlFlagCycle(true);
}

void mainAppFrame::startGeneratorFunction(callBenchmark** _proceedBenchmark) {
	(*_proceedBenchmark)->initFunction();
}

void mainAppFrame::onClickSubMenuRestart( wxCommandEvent& event ) { 
	event.Skip(); 
}

void mainAppFrame::onClickSubMenuCapture( wxCommandEvent& event ) { 
	event.Skip(); 
}

void mainAppFrame::onClickSubMenuExit( wxCommandEvent& event ) {
	this->stopGeneratorFlag = 1;
	Destroy(); 
}

void mainAppFrame::onClickProgrammInfo( wxCommandEvent& event ) { 
	infoWindow = new infoDialog(NULL);
	infoWindow->Show(true);
	event.Skip();
}

void mainAppFrame::onClickGenerationRule( wxCommandEvent& event ) { 
	event.Skip(); 
}

void mainAppFrame::onClickNetworkInterface( wxCommandEvent& event ) { 
	event.Skip(); 
}

void mainAppFrame::onClickButtonStart( wxCommandEvent& event ) { 
	this->readValuesFromGUI();
	
	this->startGeneratorThread = std::thread(&mainAppFrame::startGeneratorFunction, this, &this->proceedBenchmark);
	delete this->proceedBenchmark;
	this->proceedBenchmark = new callBenchmark(this->iotDevNumber, this->quantityOfPackage, this->selectTrafficType, 17, this->dataFieldLength, this->delayTime, this->antiDelayDuration, this->antiSendDuration, 4, this->srcNetAdr, this->desNetAdr, this->networkMask);
	this->startGeneratorThread.detach();
	
	event.Skip(); 
}

void mainAppFrame::onClickButtonStop( wxCommandEvent& event ) { 
	this->stopGeneratorFlag = 1;
	event.Skip();
}

void mainAppFrame::onClickButtonResrart( wxCommandEvent& event ) {
	event.Skip(); 
}

void mainAppFrame::onClickButtonAccept( wxCommandEvent& event ) { 
	this->readValuesFromGUI();
	
	event.Skip(); 
}

void mainAppFrame::readValuesFromGUI(void){
	if(m_radioGenerationRule->GetSelection() == 1)
		this->selectTrafficType = 2;
	else this->selectTrafficType = 1;
	
	this->switchInterfaceType = m_radioNetworkInterface->GetSelection();
	
	this->iotDevNumber = (int32_t) std::stoi(this->m_textCtrl2->GetValue().ToStdString());
	this->delayTime = (int64_t) std::stoi(this->m_textCtrl3->GetValue().ToStdString());
	this->quantityOfPackage = (uint64_t) std::stoi(this->m_textCtrl5->GetValue().ToStdString());
	this->dataFieldLength = (int16_t) std::stoi(this->m_textCtrl6->GetValue().ToStdString());
	this->srcNetAdr = this->m_textCtrl7->GetValue().ToStdString();
	this->desNetAdr = this->m_textCtrl8->GetValue().ToStdString();
	this->networkMask = this->m_textCtrl9->GetValue().ToStdString();
	this->antiDelayDuration = (uint64_t) std::stoi(this->m_textCtrl10->GetValue().ToStdString());
	this->antiSendDuration = (uint64_t) std::stoi(this->m_textCtrl11->GetValue().ToStdString());
}

infoDialog::infoDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style ){
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Генератор трафика устройств Интернет Вещей"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Sans") ) );
	
	bSizer5->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 10 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("\tГенератор трафика Интернета Вещей предназначен для нагрузочного тестирования современных сетей связи на устойчивость к трафику устройств Интернета Вещей."), wxDefaultPosition, wxSize( 350,70 ), 0 );
	m_staticText11->Wrap( -1 );
	bSizer5->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("\tПродукт разработан в лаборатории Интернет Вещей Санкт-Петербургского государственного университета телекоммуникаций им. проф. М.А.Бонч-Бруевича."), wxPoint( -1,-1 ), wxSize( 350,70 ), 0 );
	m_staticText12->Wrap( -1 );
	bSizer5->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

infoDialog::~infoDialog(){
}

void infoDialog::OnExitClick(wxCommandEvent& event) {
	Destroy();
}

void infoDialog::OnCloseFrame(wxCloseEvent& event) {
	Destroy();
}