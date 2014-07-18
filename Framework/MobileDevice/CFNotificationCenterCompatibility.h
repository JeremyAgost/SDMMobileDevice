//
//  CFNotificationCenterCompatibility.h
//  SDMMobileDevice-Framework
//
//  Created by Jeremy Agostino on 6/14/14.
//
//

#if __linux__

/*
 * CFNotificationCenter isn't available in CFLite.
 * NSNotificationCenter is available through GNUStep, however.
 * This interface will allow CF code to use notification center by wrapping the 
 * NSNotificationCenter calls in C.
 */

typedef void * CFNotificationCenterRef;

CF_EXPORT CFNotificationCenterRef CFNotificationCenterGetLocalCenter(void);

CF_EXPORT void CFNotificationCenterPostNotification(CFNotificationCenterRef center, CFStringRef name, const void *object, CFDictionaryRef userInfo, Boolean deliverImmediately);

#endif
