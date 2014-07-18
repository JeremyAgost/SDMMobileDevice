//
//  CFNotificationCenterCompatibility.c
//  SDMMobileDevice-Framework
//
//  Created by Jeremy Agostino on 6/14/14.
//
//

#include "CFNotificationCenterCompatibility.h"
#include <CoreFoundation/CoreFoundation.h>

#if __linux__

CFNotificationCenterRef CFNotificationCenterGetLocalCenter(void)
{
    return NULL;
}

void CFNotificationCenterPostNotification(CFNotificationCenterRef center, CFStringRef name, const void *object, CFDictionaryRef userInfo, Boolean deliverImmediately)
{
	
}

#endif
