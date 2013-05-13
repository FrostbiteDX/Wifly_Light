//
//  WCWiflyControlWrapper.h
//
//  Created by Bastian Kres on 16.04.13.
//  Copyright (c) 2013 Bastian Kres. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WCWiflyControlWrapper : NSObject

// Configuration
- (id)initWithIP:(uint32_t)ip port:(uint16_t)port;
- (void)configurateWlanModuleAsClient:(NSString *)ssid password:(NSString *)password name:(NSString *)name;
- (void)configurateWlanModuleAsSoftAP:(NSString *)ssid;
- (void)rebootWlanModul;

// Firmware methods
- (void)setColorDirect:(UIColor *)newColor;
- (void)setColorDirect:(const uint8_t*)pointerBuffer bufferLength:(size_t)length;
- (void)setWaitTimeInTenMilliSecondsIntervals:(uint16_t)time;
- (void)setFade:(uint32_t)colorInARGB;
- (void)setFade:(uint32_t)colorInARGB time:(uint16_t)timeValue;
- (void)setFade:(uint32_t)colorInARGB time:(uint16_t)timeValue address:(uint32_t)address;
- (void)setFade:(uint32_t)colorInARGB time:(uint16_t)timeValue address:(uint32_t)address parallelFade:(BOOL)parallel;
- (void)setGradientWithColor:(uint32_t)colorOneInARGB colorTwo:(uint32_t)colorTwoInARGB;
- (void)setGradientWithColor:(uint32_t)colorOneInARGB colorTwo:(uint32_t)colorTwoInARGB time:(uint16_t)timeValue;
- (void)setGradientWithColor:(uint32_t)colorOneInARGB colorTwo:(uint32_t)colorTwoInARGB time:(uint16_t)timeValue parallelFade:(BOOL)parallel;
- (void)setGradientWithColor:(uint32_t)colorOneInARGB colorTwo:(uint32_t)colorTwoInARGB time:(uint16_t)timeValue parallelFade:(BOOL)parallel gradientLength:(uint8_t)length;
- (void)setGradientWithColor:(uint32_t)colorOneInARGB colorTwo:(uint32_t)colorTwoInARGB time:(uint16_t)timeValue parallelFade:(BOOL)parallel gradientLength:(uint8_t)length startPosition:(uint8_t)offset;

- (void)loopOn;
- (void)loopOffAfterNumberOfRepeats:(uint8_t)repeats;
- (void)clearScript;
- (void)readRtcTime:(NSDate **)date;
- (void)writeRtcTime;
- (void)readCurrentFirmwareVersionFromFirmware:(NSString **)currentFirmwareVersionStringPlaceholder;

- (void)enterBootloader;

// Bootloader methods
- (void)readCurrentFirmwareVersionFromBootloder:(NSString **)currentFirmwareVersionStringPlaceholder;
- (void)programFlash;
- (void)leaveBootloader;

@end
