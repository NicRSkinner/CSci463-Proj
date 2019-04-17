#include "zone.h"

   Zone::Zone()
   {
       masterAlarm = false;
   }

   bool Zone::setMasterAlarm(bool inAlarmState)
   {
       masterAlarm = inAlarmState;
       return true;
   }

