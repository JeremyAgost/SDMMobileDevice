//
//  main.m
//  PairingMaterialTest
//
//  Created by Jeremy Agostino on 4/23/14.
//
//

#import <Foundation/Foundation.h>
#import "SDMMobileDevice.h"
#import "SDMMD_Functions.h"

int main(int argc, const char * argv[])
{

	@autoreleasepool {
	    
		NSString * pubkeyString = @"-----BEGIN RSA PUBLIC KEY-----\
		MIGJAoGBAKesA8shuexF81ykLZ3Yr6CXlWorqZOeN/pkYNh7XDQh9f4xMKoQ7dlJ\
		RV7YTN14k95zIuHj97csCOiUhw3PKinqqy1CMOvDOmQb6Yx8rlYbhd0HIezqP8Xd\
		WXa6aT9WkyMJXHaqQE7jqJkzO9A2/RczLDMRl0W3gIyVCbyaZ3LfAgMBAAE=\
		-----END RSA PUBLIC KEY-----";
		NSData * pubkeyData = [pubkeyString dataUsingEncoding:NSUTF8StringEncoding];
		CFMutableDictionaryRef material = SDMMD__CreatePairingMaterial((__bridge CFDataRef)(pubkeyData));
		CFShow(material);
	    
	}
    return 0;
}

