#include "ScopeViewer.hpp"


ScopeViewer::ScopeViewer()
{
	layout = new QVBoxLayout();
	setLayout(layout);
	
	//info panel
	scopeInfoPanel = new QWidget();
	layout->addWidget(scopeInfoPanel);
	scopeInfoPanelLayout = new QHBoxLayout();
	scopeInfoPanel->setLayout(scopeInfoPanelLayout);
	positionInfoLabel = new QLabel("position: 0, 0;");
	scopeInfoPanelLayout->addWidget(positionInfoLabel);
	heightInfoLabel = new QLabel("height: 0;");
	scopeInfoPanelLayout->addWidget(heightInfoLabel);
	biasInfoLabel = new QLabel("bias: 0;");
	scopeInfoPanelLayout->addWidget(biasInfoLabel);
	tunnelingCurrentInfoLabel = new QLabel("tun: 0;");
	scopeInfoPanelLayout->addWidget(tunnelingCurrentInfoLabel);
	
	//
	//graphics 
	//
	//setup
	scanWidth = 1024; 
	scanHeight = 1024;
	scanTipX = 0;
	scanTipY = 0;
	scopeGraphicsView = new QGraphicsView();
	scopeGraphicsScene = new QGraphicsScene();
	layout->addWidget(scopeGraphicsView);
	scopeGraphicsView->setScene(scopeGraphicsScene);
	scopeGraphicsView->resize(65536, 65536);
	//pixelmap
	pixmap = new QPixmap(scanWidth, scanHeight);
	pixmapItem = new QGraphicsPixmapItem(*pixmap);
	scopeGraphicsScene->addItem(pixmapItem);
	//position lines
	xTipPositionLine = new QGraphicsLineItem(scanTipX, 0, scanTipX, scanHeight);
	xTipPositionLine->setPen(QPen(Qt::green)); 
	yTipPositionLine = new QGraphicsLineItem(0, scanTipY, scanWidth, scanTipY);
	yTipPositionLine->setPen(QPen(Qt::red));
	scopeGraphicsScene->addItem(xTipPositionLine);
	scopeGraphicsScene->addItem(yTipPositionLine);
	//grid
	/*
	for (int x = 0; x < scanWidth; x += 16)
    	scopeGraphicsScene->addLine(x,0,x,scanHeight, QPen(Qt::gray));
	for (int y=0; y<scanHeight; y+=16)
		scopeGraphicsScene->addLine(0,y,scanWidth,y, QPen(Qt::gray));
	*/
}

void ScopeViewer::SetTipPosition(int x, int y)
{
	
}