#include "buildingview.h"

BuildingView::BuildingView(QWidget *parent) : QGraphicsView(parent)
{
    floorScenes.append(new QGraphicsScene(-2000, -2000, 4000, 4000));
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

    //rect->setBrush(brushAllClearUnlocked);
    setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    graphicsViewZoom = new Graphics_view_zoom(this);
    graphicsViewZoom->set_modifiers(Qt::NoModifier);

    currentScene = 0;
    setUpRooms();
    setScene(floorScenes.front());
    show();
}

void BuildingView::setUpRooms()
{
    QGraphicsRectItem *thisRect = floorScenes.at(currentScene)->addRect(QRectF(-50, -50, 100, 100));
    thisRect->setBrush(brushAllClearUnlocked);
}

