#include "ConsolePanel.hpp"


ConsolePanel::ConsolePanel(): QDockWidget("Console")
{	
	scrollAreaBase = new QScrollArea();
	widgetBase = new QWidget();
	layoutBase = new QVBoxLayout();
	
	widgetBase->setLayout(layoutBase);
	scrollAreaBase->setWidget(widgetBase);
	scrollAreaBase->setWidgetResizable(true);
	setWidget(scrollAreaBase);
	
	textEdit = new QTextEdit();
	textEdit->document()->setMaximumBlockCount(100);
    QPalette p = textEdit->palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    textEdit->setPalette(p);
	
	layoutBase->addWidget(textEdit);
	textEdit->setMinimumWidth(200);
	textEdit->setMinimumHeight(200);
	textEdit->setReadOnly(true); 
	
	lineLayout = new QHBoxLayout; 
	lineCommand = new QLineEdit;
	lineButton = new QPushButton("Command"); 
	layoutBase->addLayout(lineLayout);
	lineLayout->addWidget(lineCommand);
	lineLayout->addWidget(lineButton);
	
	connect(lineCommand, &QLineEdit::returnPressed, this, &ConsolePanel::SendCommand);
	connect(lineButton, &QPushButton::clicked, this, &ConsolePanel::SendCommand);
	
}

void ConsolePanel::ReceiveData(QString textData)
{
	std::cout << "ConsolePanel:ReceiveData" << textData.toStdString() << std::endl; 
}

void ConsolePanel::SendCommand()
{	
	QString command = lineCommand->text();
	
	std::cout << "ConsolePanel:SendCommand" << command.toStdString() << std::endl; 
	
	textEdit->append(QString("Command:") + command + QString("\n"));
	
	emit Command(command);
	
	lineCommand->clear();
}
