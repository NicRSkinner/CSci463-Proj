#include "buildingview.h"

BuildingView::BuildingView(QWidget *parent) : QGraphicsView(parent)
{
    floorScenes.append(new QGraphicsScene(-2000, -2000, 4000, 4000));
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setScene(&floorScenes.first());
    //rect->setBrush(brushAllClearUnlocked);
    setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    graphicsViewZoom = new Graphics_view_zoom(this);
    graphicsViewZoom->set_modifiers(Qt::NoModifier);
    setUpRooms();
    show();
}

void BuildingView::setUpRooms()
{
    floorScenes.first().addRect(QRectF(-50, -50, 100, 100));
}

