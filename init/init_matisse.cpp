#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_matisse.h"

#ifndef BACKLIGHT_PATH
#define BACKLIGHT_PATH          "/sys/class/leds/lcd-backlight/brightness"
#endif
#define BACKLIGHT_ON_LEVEL      100

std::string bootloader;
std::string device;
char* devicename;

device_variant check_device_and_get_variant()
{
    bootloader = property_get("ro.bootloader");
    return match(bootloader);
}

void vendor_load_properties()
{
    device_variant variant = check_device_and_get_variant();

    switch (variant) {
        case T530NU:
            /* matissewifiue */
            property_set("ro.build.fingerprint", "samsung/matissewifiue/matissewifi:5.0.2/LRX22G/T530NUU1BOJ4:user/release-keys");
            property_set("ro.build.description", "matissewifiue-user 5.0.2 LRX22G T530NUU1BOJ4 release-keys");
            property_set("ro.product.model", "SM-T530NU");
            property_set("ro.product.device", "matissewifi");
            break;
        case T530XX:
            /* matissewifixx */
            property_set("ro.build.fingerprint", "samsung/matissewifixx/matissewifi:5.0.2/LRX22G/T530XXU1BOJ4:user/release-keys");
            property_set("ro.build.description", "matissewifixx-user 5.0.2 LRX22G T530XXU1BOJ4 release-keys");
            property_set("ro.product.model", "SM-T530");
            property_set("ro.product.device", "matissewifi");
            break;
        case T531XX:
            /* matisse3gxx */
            property_set("ro.build.fingerprint", "samsung/matisse3gxx/matisse3g:5.0.2/LRX22G/T531XXU1BOE6:user/release-keys");
            property_set("ro.build.description", "matisse3gxx-user 5.0.2 LRX22G T531XXU1BOE6 release-keys");
            property_set("ro.product.model", "SM-T531");
            property_set("ro.product.device", "matisse3g");
            break;
        case T535XX:
            /* matisseltexx */
            property_set("ro.build.fingerprint", "samsung/matisseltexx/matisselte:5.0.2/LRX22G/T535XXU1BOL1:user/release-keys");
            property_set("ro.build.description", "matisseltexx-user 5.0.2 LRX22G T535XXU1BOL1 release-keys");
            property_set("ro.product.model", "SM-T535");
            property_set("ro.product.device", "matisselte");
            break;
        default: /* T530 */
            /* matissewifi */
            property_set("ro.build.fingerprint", "samsung/matissewifixx/matissewifi:5.0.2/LRX22G/T530XXU1ANAI:user/release-keys");
            property_set("ro.build.description", "matissewifixx-user 5.0.2 LRX22G T530XXU1ANAI release-keys");
            property_set("ro.product.model", "SM-T530");
            property_set("ro.product.device", "matissewifi");
            break;
    }

    device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}
