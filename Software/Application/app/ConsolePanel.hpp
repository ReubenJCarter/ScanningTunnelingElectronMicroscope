#pragma once


#include "Common.hpp"


class ConsolePanel: public QDockWidget
{
	Q_OBJECT
	public:
		QScrollArea* scrollAreaBase;
		QWidget* widgetBase; 
		QVBoxLayout* layoutBase;
		QTextEdit* textEdit;
		QHBoxLayout* lineLayout; 
		QLineEdit* lineCommand;
		QPushButton* lineButton; 
	
		ConsolePanel();
		
	public slots:
		void SendCommand();
		void ReceiveData(QString textData);
		
	signals: 
		void Command(QString command); 
};