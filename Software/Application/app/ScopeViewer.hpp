#pragma once


#include "Common.hpp"


class ScopeViewer: public QWidget
{
	Q_OBJECT
	public:
		QVBoxLayout* layout;
		
		//info panel
		QWidget* scopeInfoPanel;
		QHBoxLayout* scopeInfoPanelLayout;
		QLabel* positionInfoLabel;
		QLabel* heightInfoLabel;
		QLabel* biasInfoLabel;
		QLabel* tunnelingCurrentInfoLabel;
		
		//graphics 
		QGraphicsView* scopeGraphicsView;
		QGraphicsScene* scopeGraphicsScene;
		int scanWidth;
		int scanHeight;
		int scanTipX;
		int scanTipY;
		QPixmap* pixmap; 
		QGraphicsLineItem* xTipPositionLine; 
		QGraphicsLineItem* yTipPositionLine;
		QGraphicsPixmapItem* pixmapItem;
		
		ScopeViewer();
		
	public slots:
		void SetTipPosition(int x, int y);
		
};