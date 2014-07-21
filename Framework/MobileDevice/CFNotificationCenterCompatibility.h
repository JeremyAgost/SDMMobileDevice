//
//  CFNotificationCenterCompatibility.h
//  SDMMobileDevice-Framework
//
//  Created by Jeremy Agostino on 6/14/14.
//
//

#ifndef _CFNotificationCenterCompatibility_h
#define _CFNotificationCenterCompatibility_h

#if __linux__

/*
 * CFNotificationCenter isn't available in CFLite.
 */

typedef void * CFNotificationCenterRef;

CF_EXPORT CFNotificationCenterRef CFNotificationCenterGetLocalCenter(void);

CF_EXPORT void CFNotificationCenterPostNotification(CFNotificationCenterRef center, CFStringRef name, const void *object, CFDictionaryRef userInfo, Boolean deliverImmediately);

#endif

#endif // _CFNotificationCenterCompatibility_h
