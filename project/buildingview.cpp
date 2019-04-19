#include "buildingview.h"

BuildingView::BuildingView(QWidget *parent) : QWidget(parent)
{
    graphicsViewMap = nullptr;
}

BuildingView::BuildingView(QGraphicsView *gv, QWidget *parent) : QWidget(parent)
{

    //graphicsViewMap = gv;
    sceneList.append(new QGraphicsScene(-2000, -2000, 4000, 4000));
    //graphicsViewMap->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    //graphicsViewMap->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    //graphicsViewMap->setScene(&sceneList.first());

    /*
    //rect.setBrush(blueBrush);
    graphicsViewMap->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    zoom = new Graphics_view_zoom(graphicsViewMap);
    zoom->set_modifiers(Qt::NoModifier);
    graphicsViewMap->show();
    */
}

