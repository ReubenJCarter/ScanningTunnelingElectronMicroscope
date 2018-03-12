#pragma once


#include "Common.hpp"


class DevicePanel: public QDockWidget
{
	Q_OBJECT
	public:
		QScrollArea* scrollAreaBase;
		QWidget* widgetBase; 
		QVBoxLayout* layoutBase;
		
		QLabel* labelDeviceConnection;
		
		QPushButton* buttonConnect;
		std::string buttonState; 
		
		DevicePanel();
		
	signals:
		void Connect(); 
		void CancelConnectionAttempt();
		void Disconnect();
		
	public slots:
		void OnConnected();
};