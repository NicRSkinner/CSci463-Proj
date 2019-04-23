#include "buildingview.h"

BuildingView::BuildingView(QWidget *parent) : QGraphicsView(parent)
{
    // Set up Scenes
    for (int i = 0; i < totalFloorCount; i++)
    {
        floorScenes.append(new QGraphicsScene(-2000, -2000, 4000, 4000));
        connect(floorScenes.at(i), SIGNAL(selectionChanged()), this, SLOT(SceneSelectionChanged())); //connect the signal from the scene for when a selection is changed and use it to update ours
    }
    doorsFloor1 = new QGraphicsItemGroup();
    doorsFloor2 = new QGraphicsItemGroup();

    currentSceneIndex = 0;
    currentScenePtr = floorScenes.first();
    setScene(currentScenePtr);

    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

    setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
    graphicsViewZoom = new Graphics_view_zoom(this);
    graphicsViewZoom->set_modifiers(Qt::NoModifier);


    setUpRooms();

    show();
}

void BuildingView::SceneSelectionChanged()
{
    int selectedCount = currentScenePtr->selectedItems().count();
    if (selectedCount == 1)
    {
        selectedItem = currentScenePtr->selectedItems().at(0);
    }
    else if (selectedCount == 0)
    {
        selectedItem = nullptr;
    }
    emit SelectionChanged();

}

Room* BuildingView::getSelectedRoom()
{
    // We're only able to select rooms on screen, so this cast should work
    if (selectedItem == nullptr)
        return nullptr;

    return dynamic_cast<Room *>(selectedItem);
}

void BuildingView::setUpRooms()
{
    zones.append(new Zone(this, 1));
    zones.append(new Zone(this, 2));
    zones.append(new Zone(this, 3));

    floorScenes.at(0)->addItem(doorsFloor1);
    floorScenes.at(1)->addItem(doorsFloor2);

}

void BuildingView::masterLockdown()
{
    zones.at(0)->lockAllDoors();
    zones.at(1)->lockAllDoors();
    zones.at(2)->lockAllDoors();
}

void BuildingView::masterUnlock()
{
    zones.at(0)->unlockDoors();
    zones.at(1)->unlockDoors();
    zones.at(2)->unlockDoors();
}

void BuildingView::clearAlarms()
{
    zones.at(0)->clearAlarms();
    zones.at(1)->clearAlarms();
    zones.at(2)->clearAlarms();
}

bool BuildingView::MapFloorUp()
{
    if (currentSceneIndex == totalFloorCount - 1)
    {
        return false;
    }
    currentScenePtr->clearSelection();
    currentSceneIndex += 1;
    currentScenePtr = floorScenes.at(currentSceneIndex);
    setScene(currentScenePtr);
    repaint();
    return true;
}

bool BuildingView::MapFloorDown()
{
    if (currentSceneIndex == 0)
    {
        return false;
    }
    currentScenePtr->clearSelection();
    currentSceneIndex -= 1;
    currentScenePtr = floorScenes.at(currentSceneIndex);
    setScene(currentScenePtr);
    repaint();
    return true;
}

QList<QGraphicsScene *> BuildingView::getMasterFloorScene()
{
    return floorScenes;
}

QGraphicsItemGroup *BuildingView::getFloor1()
{
    return doorsFloor1;
}

void BuildingView::AlarmActivated()
{
    emit activateAlarm();
}

QGraphicsItemGroup *BuildingView::getFloor2()
{
    return doorsFloor2;
}
