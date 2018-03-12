#include "DevicePanel.hpp"


DevicePanel::DevicePanel(): QDockWidget("Device Panel")
{
	scrollAreaBase = new QScrollArea();
	widgetBase = new QWidget();
	layoutBase = new QVBoxLayout();
	
	widgetBase->setLayout(layoutBase);
	scrollAreaBase->setWidget(widgetBase);
	scrollAreaBase->setWidgetResizable(true);
	setWidget(scrollAreaBase);
	
	layoutBase->setAlignment(Qt::AlignTop);
	
	labelDeviceConnection = new QLabel("Device Connection");
	labelDeviceConnection->setStyleSheet("font-weight: bold;");
	layoutBase->addWidget(labelDeviceConnection);
	
	buttonConnect = new QPushButton("Connect");
	buttonState = "connect";
	layoutBase->addWidget(buttonConnect);
	connect(buttonConnect, &QPushButton::clicked, [this]()
	{
		if(buttonState == "connect")
		{
			buttonConnect->setText("Cancel");
			emit Connect();
			buttonState = "attempt";
		}
		else if(buttonState == "attempt")
		{
			buttonConnect->setText("Connect");
			emit CancelConnectionAttempt();
			buttonState = "connect";
		}
		else if(buttonState == "disconnect")
		{
			buttonConnect->setText("Connect");
			emit Disconnect();
		}
	});
	
}

void DevicePanel::OnConnected()
{
	if(buttonState == "attempt")
	{
		buttonConnect->setText("Disconnect");
		buttonState = "disconnect";
	}
	else //somthing went wrong
	{
		emit Disconnect();
	}
}
