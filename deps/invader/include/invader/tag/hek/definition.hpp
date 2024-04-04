// SPDX-License-Identifier: GPL-3.0-only

// This file was auto-generated.
// If you want to edit this, edit the .json definitions and rerun the generator script, instead.

#ifndef INVADER__TAG__HEK__CLASS__DEFINITION_HPP
#define INVADER__TAG__HEK__CLASS__DEFINITION_HPP

#include "../../hek/data_type.hpp"

namespace Invader::HEK {
    enum ActorType : TagEnum {
        ACTOR_TYPE_ELITE,
        ACTOR_TYPE_JACKAL,
        ACTOR_TYPE_GRUNT,
        ACTOR_TYPE_HUNTER,
        ACTOR_TYPE_ENGINEER,
        ACTOR_TYPE_ASSASSIN,
        ACTOR_TYPE_PLAYER,
        ACTOR_TYPE_MARINE,
        ACTOR_TYPE_CREW,
        ACTOR_TYPE_COMBAT_FORM,
        ACTOR_TYPE_INFECTION_FORM,
        ACTOR_TYPE_CARRIER_FORM,
        ACTOR_TYPE_MONITOR,
        ACTOR_TYPE_SENTINEL,
        ACTOR_TYPE_NONE,
        ACTOR_TYPE_MOUNTED_WEAPON,
        ACTOR_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorType_to_string(ActorType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorType_to_string_pretty(ActorType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorType ActorType_from_string(const char *value);

    enum ActorUnreachableDangerTrigger : TagEnum {
        ACTOR_UNREACHABLE_DANGER_TRIGGER_NEVER,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_VISIBLE,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_SHOOTING,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_SHOOTING_NEAR_US,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_DAMAGING_US,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_UNUSED,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_UNUSED1,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_UNUSED2,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_UNUSED3,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_UNUSED4,
        ACTOR_UNREACHABLE_DANGER_TRIGGER_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorUnreachableDangerTrigger_to_string(ActorUnreachableDangerTrigger value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorUnreachableDangerTrigger_to_string_pretty(ActorUnreachableDangerTrigger value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorUnreachableDangerTrigger ActorUnreachableDangerTrigger_from_string(const char *value);

    enum ActorDefensiveCrouchType : TagEnum {
        ACTOR_DEFENSIVE_CROUCH_TYPE_NEVER,
        ACTOR_DEFENSIVE_CROUCH_TYPE_DANGER,
        ACTOR_DEFENSIVE_CROUCH_TYPE_LOW_SHIELDS,
        ACTOR_DEFENSIVE_CROUCH_TYPE_HIDE_BEHIND_SHIELD,
        ACTOR_DEFENSIVE_CROUCH_TYPE_ANY_TARGET,
        ACTOR_DEFENSIVE_CROUCH_TYPE_FLOOD_SHAMBLE,
        ACTOR_DEFENSIVE_CROUCH_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorDefensiveCrouchType_to_string(ActorDefensiveCrouchType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorDefensiveCrouchType_to_string_pretty(ActorDefensiveCrouchType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorDefensiveCrouchType ActorDefensiveCrouchType_from_string(const char *value);

    enum ActorVariantMovementType : TagEnum {
        ACTOR_VARIANT_MOVEMENT_TYPE_ALWAYS_RUN,
        ACTOR_VARIANT_MOVEMENT_TYPE_ALWAYS_CROUCH,
        ACTOR_VARIANT_MOVEMENT_TYPE_SWITCH_TYPES,
        ACTOR_VARIANT_MOVEMENT_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorVariantMovementType_to_string(ActorVariantMovementType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorVariantMovementType_to_string_pretty(ActorVariantMovementType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorVariantMovementType ActorVariantMovementType_from_string(const char *value);

    enum ActorVariantSpecialFireMode : TagEnum {
        ACTOR_VARIANT_SPECIAL_FIRE_MODE_NONE,
        ACTOR_VARIANT_SPECIAL_FIRE_MODE_OVERCHARGE,
        ACTOR_VARIANT_SPECIAL_FIRE_MODE_SECONDARY_TRIGGER,
        ACTOR_VARIANT_SPECIAL_FIRE_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorVariantSpecialFireMode_to_string(ActorVariantSpecialFireMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorVariantSpecialFireMode_to_string_pretty(ActorVariantSpecialFireMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorVariantSpecialFireMode ActorVariantSpecialFireMode_from_string(const char *value);

    enum ActorVariantSpecialFireSituation : TagEnum {
        ACTOR_VARIANT_SPECIAL_FIRE_SITUATION_NEVER,
        ACTOR_VARIANT_SPECIAL_FIRE_SITUATION_ENEMY_VISIBLE,
        ACTOR_VARIANT_SPECIAL_FIRE_SITUATION_ENEMY_OUT_OF_SIGHT,
        ACTOR_VARIANT_SPECIAL_FIRE_SITUATION_STRAFING,
        ACTOR_VARIANT_SPECIAL_FIRE_SITUATION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorVariantSpecialFireSituation_to_string(ActorVariantSpecialFireSituation value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorVariantSpecialFireSituation_to_string_pretty(ActorVariantSpecialFireSituation value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorVariantSpecialFireSituation ActorVariantSpecialFireSituation_from_string(const char *value);

    enum ActorVariantTrajectoryType : TagEnum {
        ACTOR_VARIANT_TRAJECTORY_TYPE_TOSS,
        ACTOR_VARIANT_TRAJECTORY_TYPE_LOB,
        ACTOR_VARIANT_TRAJECTORY_TYPE_BOUNCE,
        ACTOR_VARIANT_TRAJECTORY_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorVariantTrajectoryType_to_string(ActorVariantTrajectoryType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorVariantTrajectoryType_to_string_pretty(ActorVariantTrajectoryType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorVariantTrajectoryType ActorVariantTrajectoryType_from_string(const char *value);

    enum ActorVariantGrenadeStimulus : TagEnum {
        ACTOR_VARIANT_GRENADE_STIMULUS_NEVER,
        ACTOR_VARIANT_GRENADE_STIMULUS_VISIBLE_TARGET,
        ACTOR_VARIANT_GRENADE_STIMULUS_SEEK_COVER,
        ACTOR_VARIANT_GRENADE_STIMULUS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorVariantGrenadeStimulus_to_string(ActorVariantGrenadeStimulus value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorVariantGrenadeStimulus_to_string_pretty(ActorVariantGrenadeStimulus value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorVariantGrenadeStimulus ActorVariantGrenadeStimulus_from_string(const char *value);

    enum BipedFunctionIn : TagEnum {
        BIPED_FUNCTION_IN_NONE,
        BIPED_FUNCTION_IN_FLYING_VELOCITY,
        BIPED_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BipedFunctionIn_to_string(BipedFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BipedFunctionIn_to_string_pretty(BipedFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BipedFunctionIn BipedFunctionIn_from_string(const char *value);

    enum BitmapDataType : TagEnum {
        BITMAP_DATA_TYPE_2D_TEXTURE,
        BITMAP_DATA_TYPE_3D_TEXTURE,
        BITMAP_DATA_TYPE_CUBE_MAP,
        BITMAP_DATA_TYPE_WHITE,
        BITMAP_DATA_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapDataType_to_string(BitmapDataType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapDataType_to_string_pretty(BitmapDataType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapDataType BitmapDataType_from_string(const char *value);

    enum BitmapDataFormat : TagEnum {
        BITMAP_DATA_FORMAT_A8,
        BITMAP_DATA_FORMAT_Y8,
        BITMAP_DATA_FORMAT_AY8,
        BITMAP_DATA_FORMAT_A8Y8,
        BITMAP_DATA_FORMAT_UNUSED1,
        BITMAP_DATA_FORMAT_UNUSED2,
        BITMAP_DATA_FORMAT_R5G6B5,
        BITMAP_DATA_FORMAT_UNUSED3,
        BITMAP_DATA_FORMAT_A1R5G5B5,
        BITMAP_DATA_FORMAT_A4R4G4B4,
        BITMAP_DATA_FORMAT_X8R8G8B8,
        BITMAP_DATA_FORMAT_A8R8G8B8,
        BITMAP_DATA_FORMAT_UNUSED4,
        BITMAP_DATA_FORMAT_UNUSED5,
        BITMAP_DATA_FORMAT_DXT1,
        BITMAP_DATA_FORMAT_DXT3,
        BITMAP_DATA_FORMAT_DXT5,
        BITMAP_DATA_FORMAT_P8_BUMP,
        BITMAP_DATA_FORMAT_BC7,
        BITMAP_DATA_FORMAT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapDataFormat_to_string(BitmapDataFormat value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapDataFormat_to_string_pretty(BitmapDataFormat value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapDataFormat BitmapDataFormat_from_string(const char *value);

    enum BitmapType : TagEnum {
        BITMAP_TYPE_2D_TEXTURES,
        BITMAP_TYPE_3D_TEXTURES,
        BITMAP_TYPE_CUBE_MAPS,
        BITMAP_TYPE_SPRITES,
        BITMAP_TYPE_INTERFACE_BITMAPS,
        BITMAP_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapType_to_string(BitmapType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapType_to_string_pretty(BitmapType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapType BitmapType_from_string(const char *value);

    enum BitmapFormat : TagEnum {
        BITMAP_FORMAT_DXT1,
        BITMAP_FORMAT_DXT3,
        BITMAP_FORMAT_DXT5,
        BITMAP_FORMAT_16_BIT,
        BITMAP_FORMAT_32_BIT,
        BITMAP_FORMAT_MONOCHROME,
        BITMAP_FORMAT_BC7,
        BITMAP_FORMAT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapFormat_to_string(BitmapFormat value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapFormat_to_string_pretty(BitmapFormat value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapFormat BitmapFormat_from_string(const char *value);

    enum BitmapUsage : TagEnum {
        BITMAP_USAGE_ALPHA_BLEND,
        BITMAP_USAGE_DEFAULT,
        BITMAP_USAGE_HEIGHT_MAP,
        BITMAP_USAGE_DETAIL_MAP,
        BITMAP_USAGE_LIGHT_MAP,
        BITMAP_USAGE_VECTOR_MAP,
        BITMAP_USAGE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapUsage_to_string(BitmapUsage value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapUsage_to_string_pretty(BitmapUsage value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapUsage BitmapUsage_from_string(const char *value);

    enum BitmapSpriteBudgetSize : TagEnum {
        BITMAP_SPRITE_BUDGET_SIZE_32X32,
        BITMAP_SPRITE_BUDGET_SIZE_64X64,
        BITMAP_SPRITE_BUDGET_SIZE_128X128,
        BITMAP_SPRITE_BUDGET_SIZE_256X256,
        BITMAP_SPRITE_BUDGET_SIZE_512X512,
        BITMAP_SPRITE_BUDGET_SIZE_1024X1024,
        BITMAP_SPRITE_BUDGET_SIZE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapSpriteBudgetSize_to_string(BitmapSpriteBudgetSize value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapSpriteBudgetSize_to_string_pretty(BitmapSpriteBudgetSize value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapSpriteBudgetSize BitmapSpriteBudgetSize_from_string(const char *value);

    enum BitmapSpriteUsage : TagEnum {
        BITMAP_SPRITE_USAGE_BLEND_ADD_SUBTRACT_MAX,
        BITMAP_SPRITE_USAGE_MULTIPLY_MIN,
        BITMAP_SPRITE_USAGE_DOUBLE_MULTIPLY,
        BITMAP_SPRITE_USAGE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapSpriteUsage_to_string(BitmapSpriteUsage value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapSpriteUsage_to_string_pretty(BitmapSpriteUsage value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapSpriteUsage BitmapSpriteUsage_from_string(const char *value);

    enum ContrailRenderType : TagEnum {
        CONTRAIL_RENDER_TYPE_VERTICAL_ORIENTATION,
        CONTRAIL_RENDER_TYPE_HORIZONTAL_ORIENTATION,
        CONTRAIL_RENDER_TYPE_MEDIA_MAPPED,
        CONTRAIL_RENDER_TYPE_GROUND_MAPPED,
        CONTRAIL_RENDER_TYPE_VIEWER_FACING,
        CONTRAIL_RENDER_TYPE_DOUBLE_MARKER_LINKED,
        CONTRAIL_RENDER_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ContrailRenderType_to_string(ContrailRenderType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ContrailRenderType_to_string_pretty(ContrailRenderType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ContrailRenderType ContrailRenderType_from_string(const char *value);

    enum DamageEffectScreenFlashType : TagEnum {
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_NONE,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_LIGHTEN,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_DARKEN,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_MAX,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_MIN,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_INVERT,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_TINT,
        DAMAGE_EFFECT_SCREEN_FLASH_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DamageEffectScreenFlashType_to_string(DamageEffectScreenFlashType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DamageEffectScreenFlashType_to_string_pretty(DamageEffectScreenFlashType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DamageEffectScreenFlashType DamageEffectScreenFlashType_from_string(const char *value);

    enum DamageEffectScreenFlashPriority : TagEnum {
        DAMAGE_EFFECT_SCREEN_FLASH_PRIORITY_LOW,
        DAMAGE_EFFECT_SCREEN_FLASH_PRIORITY_MEDIUM,
        DAMAGE_EFFECT_SCREEN_FLASH_PRIORITY_HIGH,
        DAMAGE_EFFECT_SCREEN_FLASH_PRIORITY_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DamageEffectScreenFlashPriority_to_string(DamageEffectScreenFlashPriority value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DamageEffectScreenFlashPriority_to_string_pretty(DamageEffectScreenFlashPriority value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DamageEffectScreenFlashPriority DamageEffectScreenFlashPriority_from_string(const char *value);

    enum DamageEffectSideEffect : TagEnum {
        DAMAGE_EFFECT_SIDE_EFFECT_NONE,
        DAMAGE_EFFECT_SIDE_EFFECT_HARMLESS,
        DAMAGE_EFFECT_SIDE_EFFECT_LETHAL_TO_THE_UNSUSPECTING,
        DAMAGE_EFFECT_SIDE_EFFECT_EMP,
        DAMAGE_EFFECT_SIDE_EFFECT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DamageEffectSideEffect_to_string(DamageEffectSideEffect value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DamageEffectSideEffect_to_string_pretty(DamageEffectSideEffect value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DamageEffectSideEffect DamageEffectSideEffect_from_string(const char *value);

    enum DamageEffectCategory : TagEnum {
        DAMAGE_EFFECT_CATEGORY_NONE,
        DAMAGE_EFFECT_CATEGORY_FALLING,
        DAMAGE_EFFECT_CATEGORY_BULLET,
        DAMAGE_EFFECT_CATEGORY_GRENADE,
        DAMAGE_EFFECT_CATEGORY_HIGH_EXPLOSIVE,
        DAMAGE_EFFECT_CATEGORY_SNIPER,
        DAMAGE_EFFECT_CATEGORY_MELEE,
        DAMAGE_EFFECT_CATEGORY_FLAME,
        DAMAGE_EFFECT_CATEGORY_MOUNTED_WEAPON,
        DAMAGE_EFFECT_CATEGORY_VEHICLE,
        DAMAGE_EFFECT_CATEGORY_PLASMA,
        DAMAGE_EFFECT_CATEGORY_NEEDLE,
        DAMAGE_EFFECT_CATEGORY_SHOTGUN,
        DAMAGE_EFFECT_CATEGORY_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DamageEffectCategory_to_string(DamageEffectCategory value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DamageEffectCategory_to_string_pretty(DamageEffectCategory value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DamageEffectCategory DamageEffectCategory_from_string(const char *value);

    enum DecalType : TagEnum {
        DECAL_TYPE_SCRATCH,
        DECAL_TYPE_SPLATTER,
        DECAL_TYPE_BURN,
        DECAL_TYPE_PAINTED_SIGN,
        DECAL_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DecalType_to_string(DecalType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DecalType_to_string_pretty(DecalType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DecalType DecalType_from_string(const char *value);

    enum DecalLayer : TagEnum {
        DECAL_LAYER_PRIMARY,
        DECAL_LAYER_SECONDARY,
        DECAL_LAYER_LIGHT,
        DECAL_LAYER_ALPHA_TESTED,
        DECAL_LAYER_WATER,
        DECAL_LAYER_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DecalLayer_to_string(DecalLayer value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DecalLayer_to_string_pretty(DecalLayer value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DecalLayer DecalLayer_from_string(const char *value);

    enum DetailObjectCollectionType : TagEnum {
        DETAIL_OBJECT_COLLECTION_TYPE_SCREEN_FACING,
        DETAIL_OBJECT_COLLECTION_TYPE_VIEWER_FACING,
        DETAIL_OBJECT_COLLECTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DetailObjectCollectionType_to_string(DetailObjectCollectionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DetailObjectCollectionType_to_string_pretty(DetailObjectCollectionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DetailObjectCollectionType DetailObjectCollectionType_from_string(const char *value);

    enum DeviceIn : TagEnum {
        DEVICE_IN_NONE,
        DEVICE_IN_POWER,
        DEVICE_IN_CHANGE_IN_POWER,
        DEVICE_IN_POSITION,
        DEVICE_IN_CHANGE_IN_POSITION,
        DEVICE_IN_LOCKED,
        DEVICE_IN_DELAY,
        DEVICE_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DeviceIn_to_string(DeviceIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DeviceIn_to_string_pretty(DeviceIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DeviceIn DeviceIn_from_string(const char *value);

    enum DeviceType : TagEnum {
        DEVICE_TYPE_TOGGLE_SWITCH,
        DEVICE_TYPE_ON_BUTTON,
        DEVICE_TYPE_OFF_BUTTON,
        DEVICE_TYPE_CALL_BUTTON,
        DEVICE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DeviceType_to_string(DeviceType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DeviceType_to_string_pretty(DeviceType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DeviceType DeviceType_from_string(const char *value);

    enum DeviceTriggersWhen : TagEnum {
        DEVICE_TRIGGERS_WHEN_TOUCHED_BY_PLAYER,
        DEVICE_TRIGGERS_WHEN_DESTROYED,
        DEVICE_TRIGGERS_WHEN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DeviceTriggersWhen_to_string(DeviceTriggersWhen value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DeviceTriggersWhen_to_string_pretty(DeviceTriggersWhen value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DeviceTriggersWhen DeviceTriggersWhen_from_string(const char *value);

    enum MachineType : TagEnum {
        MACHINE_TYPE_DOOR,
        MACHINE_TYPE_PLATFORM,
        MACHINE_TYPE_GEAR,
        MACHINE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MachineType_to_string(MachineType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MachineType_to_string_pretty(MachineType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MachineType MachineType_from_string(const char *value);

    enum MachineCollisionResponse : TagEnum {
        MACHINE_COLLISION_RESPONSE_PAUSE_UNTIL_CRUSHED,
        MACHINE_COLLISION_RESPONSE_REVERSE_DIRECTIONS,
        MACHINE_COLLISION_RESPONSE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MachineCollisionResponse_to_string(MachineCollisionResponse value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MachineCollisionResponse_to_string_pretty(MachineCollisionResponse value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MachineCollisionResponse MachineCollisionResponse_from_string(const char *value);

    enum EffectCreateIn : TagEnum {
        EFFECT_CREATE_IN_ANY_ENVIRONMENT,
        EFFECT_CREATE_IN_AIR_ONLY,
        EFFECT_CREATE_IN_WATER_ONLY,
        EFFECT_CREATE_IN_SPACE_ONLY,
        EFFECT_CREATE_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectCreateIn_to_string(EffectCreateIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectCreateIn_to_string_pretty(EffectCreateIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectCreateIn EffectCreateIn_from_string(const char *value);

    enum EffectViolenceMode : TagEnum {
        EFFECT_VIOLENCE_MODE_EITHER_MODE,
        EFFECT_VIOLENCE_MODE_VIOLENT_MODE_ONLY,
        EFFECT_VIOLENCE_MODE_NONVIOLENT_MODE_ONLY,
        EFFECT_VIOLENCE_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectViolenceMode_to_string(EffectViolenceMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectViolenceMode_to_string_pretty(EffectViolenceMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectViolenceMode EffectViolenceMode_from_string(const char *value);

    enum EffectCreate : TagEnum {
        EFFECT_CREATE_INDEPENDENT_OF_CAMERA_MODE,
        EFFECT_CREATE_ONLY_IN_FIRST_PERSON,
        EFFECT_CREATE_ONLY_IN_THIRD_PERSON,
        EFFECT_CREATE_IN_FIRST_PERSON_IF_POSSIBLE,
        EFFECT_CREATE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectCreate_to_string(EffectCreate value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectCreate_to_string_pretty(EffectCreate value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectCreate EffectCreate_from_string(const char *value);

    enum EffectDistributionFunction : TagEnum {
        EFFECT_DISTRIBUTION_FUNCTION_START,
        EFFECT_DISTRIBUTION_FUNCTION_END,
        EFFECT_DISTRIBUTION_FUNCTION_CONSTANT,
        EFFECT_DISTRIBUTION_FUNCTION_BUILDUP,
        EFFECT_DISTRIBUTION_FUNCTION_FALLOFF,
        EFFECT_DISTRIBUTION_FUNCTION_BUILDUP_AND_FALLOFF,
        EFFECT_DISTRIBUTION_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectDistributionFunction_to_string(EffectDistributionFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectDistributionFunction_to_string_pretty(EffectDistributionFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectDistributionFunction EffectDistributionFunction_from_string(const char *value);

    enum FramebufferBlendFunction : TagEnum {
        FRAMEBUFFER_BLEND_FUNCTION_ALPHA_BLEND,
        FRAMEBUFFER_BLEND_FUNCTION_MULTIPLY,
        FRAMEBUFFER_BLEND_FUNCTION_DOUBLE_MULTIPLY,
        FRAMEBUFFER_BLEND_FUNCTION_ADD,
        FRAMEBUFFER_BLEND_FUNCTION_SUBTRACT,
        FRAMEBUFFER_BLEND_FUNCTION_COMPONENT_MIN,
        FRAMEBUFFER_BLEND_FUNCTION_COMPONENT_MAX,
        FRAMEBUFFER_BLEND_FUNCTION_ALPHA_MULTIPLY_ADD,
        FRAMEBUFFER_BLEND_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FramebufferBlendFunction_to_string(FramebufferBlendFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FramebufferBlendFunction_to_string_pretty(FramebufferBlendFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FramebufferBlendFunction FramebufferBlendFunction_from_string(const char *value);

    enum FramebufferFadeMode : TagEnum {
        FRAMEBUFFER_FADE_MODE_NONE,
        FRAMEBUFFER_FADE_MODE_FADE_WHEN_PERPENDICULAR,
        FRAMEBUFFER_FADE_MODE_FADE_WHEN_PARALLEL,
        FRAMEBUFFER_FADE_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FramebufferFadeMode_to_string(FramebufferFadeMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FramebufferFadeMode_to_string_pretty(FramebufferFadeMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FramebufferFadeMode FramebufferFadeMode_from_string(const char *value);

    enum FunctionOut : TagEnum {
        FUNCTION_OUT_NONE,
        FUNCTION_OUT_A_OUT,
        FUNCTION_OUT_B_OUT,
        FUNCTION_OUT_C_OUT,
        FUNCTION_OUT_D_OUT,
        FUNCTION_OUT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FunctionOut_to_string(FunctionOut value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FunctionOut_to_string_pretty(FunctionOut value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FunctionOut FunctionOut_from_string(const char *value);

    enum WaveFunction : TagEnum {
        WAVE_FUNCTION_ONE,
        WAVE_FUNCTION_ZERO,
        WAVE_FUNCTION_COSINE,
        WAVE_FUNCTION_COSINE_VARIABLE_PERIOD,
        WAVE_FUNCTION_DIAGONAL_WAVE,
        WAVE_FUNCTION_DIAGONAL_WAVE_VARIABLE_PERIOD,
        WAVE_FUNCTION_SLIDE,
        WAVE_FUNCTION_SLIDE_VARIABLE_PERIOD,
        WAVE_FUNCTION_NOISE,
        WAVE_FUNCTION_JITTER,
        WAVE_FUNCTION_WANDER,
        WAVE_FUNCTION_SPARK,
        WAVE_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WaveFunction_to_string(WaveFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WaveFunction_to_string_pretty(WaveFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WaveFunction WaveFunction_from_string(const char *value);

    enum MaterialType : TagEnum {
        MATERIAL_TYPE_DIRT,
        MATERIAL_TYPE_SAND,
        MATERIAL_TYPE_STONE,
        MATERIAL_TYPE_SNOW,
        MATERIAL_TYPE_WOOD,
        MATERIAL_TYPE_METAL_HOLLOW,
        MATERIAL_TYPE_METAL_THIN,
        MATERIAL_TYPE_METAL_THICK,
        MATERIAL_TYPE_RUBBER,
        MATERIAL_TYPE_GLASS,
        MATERIAL_TYPE_FORCE_FIELD,
        MATERIAL_TYPE_GRUNT,
        MATERIAL_TYPE_HUNTER_ARMOR,
        MATERIAL_TYPE_HUNTER_SKIN,
        MATERIAL_TYPE_ELITE,
        MATERIAL_TYPE_JACKAL,
        MATERIAL_TYPE_JACKAL_ENERGY_SHIELD,
        MATERIAL_TYPE_ENGINEER_SKIN,
        MATERIAL_TYPE_ENGINEER_FORCE_FIELD,
        MATERIAL_TYPE_FLOOD_COMBAT_FORM,
        MATERIAL_TYPE_FLOOD_CARRIER_FORM,
        MATERIAL_TYPE_CYBORG_ARMOR,
        MATERIAL_TYPE_CYBORG_ENERGY_SHIELD,
        MATERIAL_TYPE_HUMAN_ARMOR,
        MATERIAL_TYPE_HUMAN_SKIN,
        MATERIAL_TYPE_SENTINEL,
        MATERIAL_TYPE_MONITOR,
        MATERIAL_TYPE_PLASTIC,
        MATERIAL_TYPE_WATER,
        MATERIAL_TYPE_LEAVES,
        MATERIAL_TYPE_ELITE_ENERGY_SHIELD,
        MATERIAL_TYPE_ICE,
        MATERIAL_TYPE_HUNTER_SHIELD,
        MATERIAL_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MaterialType_to_string(MaterialType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MaterialType_to_string_pretty(MaterialType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MaterialType MaterialType_from_string(const char *value);

    enum FunctionType : TagEnum {
        FUNCTION_TYPE_LINEAR,
        FUNCTION_TYPE_EARLY,
        FUNCTION_TYPE_VERY_EARLY,
        FUNCTION_TYPE_LATE,
        FUNCTION_TYPE_VERY_LATE,
        FUNCTION_TYPE_COSINE,
        FUNCTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FunctionType_to_string(FunctionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FunctionType_to_string_pretty(FunctionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FunctionType FunctionType_from_string(const char *value);

    enum FunctionBoundsMode : TagEnum {
        FUNCTION_BOUNDS_MODE_CLIP,
        FUNCTION_BOUNDS_MODE_CLIP_AND_NORMALIZE,
        FUNCTION_BOUNDS_MODE_SCALE_TO_FIT,
        FUNCTION_BOUNDS_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FunctionBoundsMode_to_string(FunctionBoundsMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FunctionBoundsMode_to_string_pretty(FunctionBoundsMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FunctionBoundsMode FunctionBoundsMode_from_string(const char *value);

    enum FunctionScaleBy : TagEnum {
        FUNCTION_SCALE_BY_NONE,
        FUNCTION_SCALE_BY_A_IN,
        FUNCTION_SCALE_BY_B_IN,
        FUNCTION_SCALE_BY_C_IN,
        FUNCTION_SCALE_BY_D_IN,
        FUNCTION_SCALE_BY_A_OUT,
        FUNCTION_SCALE_BY_B_OUT,
        FUNCTION_SCALE_BY_C_OUT,
        FUNCTION_SCALE_BY_D_OUT,
        FUNCTION_SCALE_BY_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FunctionScaleBy_to_string(FunctionScaleBy value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FunctionScaleBy_to_string_pretty(FunctionScaleBy value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FunctionScaleBy FunctionScaleBy_from_string(const char *value);

    enum FunctionNameNullable : TagEnum {
        FUNCTION_NAME_NULLABLE_NONE,
        FUNCTION_NAME_NULLABLE_A,
        FUNCTION_NAME_NULLABLE_B,
        FUNCTION_NAME_NULLABLE_C,
        FUNCTION_NAME_NULLABLE_D,
        FUNCTION_NAME_NULLABLE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FunctionNameNullable_to_string(FunctionNameNullable value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FunctionNameNullable_to_string_pretty(FunctionNameNullable value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FunctionNameNullable FunctionNameNullable_from_string(const char *value);

    enum GrenadeType : TagEnum {
        GRENADE_TYPE_HUMAN_FRAGMENTATION,
        GRENADE_TYPE_COVENANT_PLASMA,
        GRENADE_TYPE_GRENADE_TYPE_2,
        GRENADE_TYPE_GRENADE_TYPE_3,
        GRENADE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GrenadeType_to_string(GrenadeType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GrenadeType_to_string_pretty(GrenadeType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GrenadeType GrenadeType_from_string(const char *value);

    enum VertexType : TagEnum {
        VERTEX_TYPE_STRUCTURE_BSP_UNCOMPRESSED_RENDERED_VERTICES,
        VERTEX_TYPE_STRUCTURE_BSP_COMPRESSED_RENDERED_VERTICES,
        VERTEX_TYPE_STRUCTURE_BSP_UNCOMPRESSED_LIGHTMAP_VERTICES,
        VERTEX_TYPE_STRUCTURE_BSP_COMPRESSED_LIGHTMAP_VERTICES,
        VERTEX_TYPE_MODEL_UNCOMPRESSED,
        VERTEX_TYPE_MODEL_COMPRESSED,
        VERTEX_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *VertexType_to_string(VertexType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *VertexType_to_string_pretty(VertexType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    VertexType VertexType_from_string(const char *value);

    enum TriangleBufferType : TagEnum {
        TRIANGLE_BUFFER_TYPE_TRIANGLE_LIST,
        TRIANGLE_BUFFER_TYPE_TRIANGLE_STRIP,
        TRIANGLE_BUFFER_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *TriangleBufferType_to_string(TriangleBufferType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *TriangleBufferType_to_string_pretty(TriangleBufferType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    TriangleBufferType TriangleBufferType_from_string(const char *value);

    enum EquipmentPowerupType : TagEnum {
        EQUIPMENT_POWERUP_TYPE_NONE,
        EQUIPMENT_POWERUP_TYPE_DOUBLE_SPEED,
        EQUIPMENT_POWERUP_TYPE_OVER_SHIELD,
        EQUIPMENT_POWERUP_TYPE_ACTIVE_CAMOUFLAGE,
        EQUIPMENT_POWERUP_TYPE_FULL_SPECTRUM_VISION,
        EQUIPMENT_POWERUP_TYPE_HEALTH,
        EQUIPMENT_POWERUP_TYPE_GRENADE,
        EQUIPMENT_POWERUP_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EquipmentPowerupType_to_string(EquipmentPowerupType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EquipmentPowerupType_to_string_pretty(EquipmentPowerupType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EquipmentPowerupType EquipmentPowerupType_from_string(const char *value);

    enum FlagTrailingEdgeShape : TagEnum {
        FLAG_TRAILING_EDGE_SHAPE_FLAT,
        FLAG_TRAILING_EDGE_SHAPE_CONCAVE_TRIANGULAR,
        FLAG_TRAILING_EDGE_SHAPE_CONVEX_TRIANGULAR,
        FLAG_TRAILING_EDGE_SHAPE_TRAPEZOID_SHORT_TOP,
        FLAG_TRAILING_EDGE_SHAPE_TRAPEZOID_SHORT_BOTTOM,
        FLAG_TRAILING_EDGE_SHAPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FlagTrailingEdgeShape_to_string(FlagTrailingEdgeShape value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FlagTrailingEdgeShape_to_string_pretty(FlagTrailingEdgeShape value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FlagTrailingEdgeShape FlagTrailingEdgeShape_from_string(const char *value);

    enum FlagAttachedEdgeShape : TagEnum {
        FLAG_ATTACHED_EDGE_SHAPE_FLAT,
        FLAG_ATTACHED_EDGE_SHAPE_CONCAVE_TRIANGULAR,
        FLAG_ATTACHED_EDGE_SHAPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FlagAttachedEdgeShape_to_string(FlagAttachedEdgeShape value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FlagAttachedEdgeShape_to_string_pretty(FlagAttachedEdgeShape value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FlagAttachedEdgeShape FlagAttachedEdgeShape_from_string(const char *value);

    enum MultiplayerInformationSound : TagEnum {
        MULTIPLAYER_INFORMATION_SOUND_PLAY_BALL,
        MULTIPLAYER_INFORMATION_SOUND_GAME_OVER,
        MULTIPLAYER_INFORMATION_SOUND_ONE_MINUTE_TO_WIN,
        MULTIPLAYER_INFORMATION_SOUND_30_SECONDS_TO_WIN,
        MULTIPLAYER_INFORMATION_SOUND_RED_TEAM_MINUTE_TO_WIN,
        MULTIPLAYER_INFORMATION_SOUND_RED_TEAM_30_TO_WIN,
        MULTIPLAYER_INFORMATION_SOUND_BLUE_TEAM_MINUTE_TO_WIN,
        MULTIPLAYER_INFORMATION_SOUND_BLUE_TEAM_30_TO_WIN,
        MULTIPLAYER_INFORMATION_SOUND_BLUE_TEAM_HAS_THE_FLAG,
        MULTIPLAYER_INFORMATION_SOUND_BLUE_TEAM_FLAG_RETURNED,
        MULTIPLAYER_INFORMATION_SOUND_BLUE_TEAM_SCORE,
        MULTIPLAYER_INFORMATION_SOUND_RED_TEAM_HAS_THE_FLAG,
        MULTIPLAYER_INFORMATION_SOUND_RED_TEAM_FLAG_RETURNED,
        MULTIPLAYER_INFORMATION_SOUND_RED_TEAM_SCORE,
        MULTIPLAYER_INFORMATION_SOUND_DOUBLE_KILL,
        MULTIPLAYER_INFORMATION_SOUND_TRIPLE_KILL,
        MULTIPLAYER_INFORMATION_SOUND_KILLTACULAR,
        MULTIPLAYER_INFORMATION_SOUND_RUNNING_RIOT,
        MULTIPLAYER_INFORMATION_SOUND_KILLING_SPREE,
        MULTIPLAYER_INFORMATION_SOUND_ODDBALL,
        MULTIPLAYER_INFORMATION_SOUND_RACE,
        MULTIPLAYER_INFORMATION_SOUND_SLAYER,
        MULTIPLAYER_INFORMATION_SOUND_CAPTURE_THE_FLAG,
        MULTIPLAYER_INFORMATION_SOUND_WARTHOG,
        MULTIPLAYER_INFORMATION_SOUND_GHOST,
        MULTIPLAYER_INFORMATION_SOUND_SCORPION,
        MULTIPLAYER_INFORMATION_SOUND_COUNTDOWN_TIMER,
        MULTIPLAYER_INFORMATION_SOUND_TELEPORTER_ACTIVATE,
        MULTIPLAYER_INFORMATION_SOUND_FLAG_FAILURE,
        MULTIPLAYER_INFORMATION_SOUND_COUNTDOWN_FOR_RESPAWN,
        MULTIPLAYER_INFORMATION_SOUND_HILL_MOVE,
        MULTIPLAYER_INFORMATION_SOUND_PLAYER_RESPAWN,
        MULTIPLAYER_INFORMATION_SOUND_TEAM_KING_OF_THE_HILL,
        MULTIPLAYER_INFORMATION_SOUND_TEAM_ODDBALL,
        MULTIPLAYER_INFORMATION_SOUND_TEAM_RACE,
        MULTIPLAYER_INFORMATION_SOUND_TEAM_SLAYER,
        MULTIPLAYER_INFORMATION_SOUND_KING_OF_THE_HILL,
        MULTIPLAYER_INFORMATION_SOUND_BLUE_TEAM_CTF,
        MULTIPLAYER_INFORMATION_SOUND_RED_TEAM_CTF,
        MULTIPLAYER_INFORMATION_SOUND_HILL_CONTESTED,
        MULTIPLAYER_INFORMATION_SOUND_HILL_CONTROLLED,
        MULTIPLAYER_INFORMATION_SOUND_HILL_OCCUPIED,
        MULTIPLAYER_INFORMATION_SOUND_COUNTDOWN_TIMER_END,
        MULTIPLAYER_INFORMATION_SOUND_TING,
        MULTIPLAYER_INFORMATION_SOUND_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MultiplayerInformationSound_to_string(MultiplayerInformationSound value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MultiplayerInformationSound_to_string_pretty(MultiplayerInformationSound value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MultiplayerInformationSound MultiplayerInformationSound_from_string(const char *value);

    enum GlowBoundaryEffect : TagEnum {
        GLOW_BOUNDARY_EFFECT_BOUNCE,
        GLOW_BOUNDARY_EFFECT_WRAP,
        GLOW_BOUNDARY_EFFECT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GlowBoundaryEffect_to_string(GlowBoundaryEffect value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GlowBoundaryEffect_to_string_pretty(GlowBoundaryEffect value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GlowBoundaryEffect GlowBoundaryEffect_from_string(const char *value);

    enum GlowNormalParticleDistribution : TagEnum {
        GLOW_NORMAL_PARTICLE_DISTRIBUTION_DISTRIBUTED_RANDOMLY,
        GLOW_NORMAL_PARTICLE_DISTRIBUTION_DISTRIBUTED_UNIFORMLY,
        GLOW_NORMAL_PARTICLE_DISTRIBUTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GlowNormalParticleDistribution_to_string(GlowNormalParticleDistribution value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GlowNormalParticleDistribution_to_string_pretty(GlowNormalParticleDistribution value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GlowNormalParticleDistribution GlowNormalParticleDistribution_from_string(const char *value);

    enum GlowTrailingParticleDistribution : TagEnum {
        GLOW_TRAILING_PARTICLE_DISTRIBUTION_EMIT_VERTICALLY,
        GLOW_TRAILING_PARTICLE_DISTRIBUTION_EMIT_NORMAL_UP,
        GLOW_TRAILING_PARTICLE_DISTRIBUTION_EMIT_RANDOMLY,
        GLOW_TRAILING_PARTICLE_DISTRIBUTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GlowTrailingParticleDistribution_to_string(GlowTrailingParticleDistribution value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GlowTrailingParticleDistribution_to_string_pretty(GlowTrailingParticleDistribution value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GlowTrailingParticleDistribution GlowTrailingParticleDistribution_from_string(const char *value);

    enum HUDGlobalsAnniversaryRemapTargetLanguage : TagEnum {
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_ENGLISH,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_FRENCH,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_SPANISH,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_ITALIAN,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_GERMAN,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_TRADITIONAL_CHINESE,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_JAPANESE,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_KOREAN,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_PORTUGUESE,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_LATAM_SPANISH,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_POLISH,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_RUSSIAN,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_SIMPLIFIED_CHINESE,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_LANGUAGE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDGlobalsAnniversaryRemapTargetLanguage_to_string(HUDGlobalsAnniversaryRemapTargetLanguage value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDGlobalsAnniversaryRemapTargetLanguage_to_string_pretty(HUDGlobalsAnniversaryRemapTargetLanguage value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDGlobalsAnniversaryRemapTargetLanguage HUDGlobalsAnniversaryRemapTargetLanguage_from_string(const char *value);

    enum HUDInterfaceDestinationType : TagEnum {
        HUD_INTERFACE_DESTINATION_TYPE_TINT_0_1,
        HUD_INTERFACE_DESTINATION_TYPE_HORIZONTAL_OFFSET,
        HUD_INTERFACE_DESTINATION_TYPE_VERTICAL_OFFSET,
        HUD_INTERFACE_DESTINATION_TYPE_FADE_0_1,
        HUD_INTERFACE_DESTINATION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceDestinationType_to_string(HUDInterfaceDestinationType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceDestinationType_to_string_pretty(HUDInterfaceDestinationType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceDestinationType HUDInterfaceDestinationType_from_string(const char *value);

    enum HUDInterfaceDestination : TagEnum {
        HUD_INTERFACE_DESTINATION_GEOMETRY_OFFSET,
        HUD_INTERFACE_DESTINATION_PRIMARY_MAP,
        HUD_INTERFACE_DESTINATION_SECONDARY_MAP,
        HUD_INTERFACE_DESTINATION_TERTIARY_MAP,
        HUD_INTERFACE_DESTINATION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceDestination_to_string(HUDInterfaceDestination value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceDestination_to_string_pretty(HUDInterfaceDestination value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceDestination HUDInterfaceDestination_from_string(const char *value);

    enum HUDInterfaceSource : TagEnum {
        HUD_INTERFACE_SOURCE_PLAYER_PITCH,
        HUD_INTERFACE_SOURCE_PLAYER_PITCH_TANGENT,
        HUD_INTERFACE_SOURCE_PLAYER_YAW,
        HUD_INTERFACE_SOURCE_WEAPON_AMMO_TOTAL,
        HUD_INTERFACE_SOURCE_WEAPON_AMMO_LOADED,
        HUD_INTERFACE_SOURCE_WEAPON_HEAT,
        HUD_INTERFACE_SOURCE_EXPLICIT_USES_LOW_BOUND,
        HUD_INTERFACE_SOURCE_WEAPON_ZOOM_LEVEL,
        HUD_INTERFACE_SOURCE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceSource_to_string(HUDInterfaceSource value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceSource_to_string_pretty(HUDInterfaceSource value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceSource HUDInterfaceSource_from_string(const char *value);

    enum HUDInterfaceMultitextureOverlayAnchor : TagEnum {
        HUD_INTERFACE_MULTITEXTURE_OVERLAY_ANCHOR_TEXTURE,
        HUD_INTERFACE_MULTITEXTURE_OVERLAY_ANCHOR_SCREEN,
        HUD_INTERFACE_MULTITEXTURE_OVERLAY_ANCHOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceMultitextureOverlayAnchor_to_string(HUDInterfaceMultitextureOverlayAnchor value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceMultitextureOverlayAnchor_to_string_pretty(HUDInterfaceMultitextureOverlayAnchor value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceMultitextureOverlayAnchor HUDInterfaceMultitextureOverlayAnchor_from_string(const char *value);

    enum HUDInterfaceZeroToOneBlendFunction : TagEnum {
        HUD_INTERFACE_ZERO_TO_ONE_BLEND_FUNCTION_ADD,
        HUD_INTERFACE_ZERO_TO_ONE_BLEND_FUNCTION_SUBTRACT,
        HUD_INTERFACE_ZERO_TO_ONE_BLEND_FUNCTION_MULTIPLY,
        HUD_INTERFACE_ZERO_TO_ONE_BLEND_FUNCTION_MULTIPLY2X,
        HUD_INTERFACE_ZERO_TO_ONE_BLEND_FUNCTION_DOT,
        HUD_INTERFACE_ZERO_TO_ONE_BLEND_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceZeroToOneBlendFunction_to_string(HUDInterfaceZeroToOneBlendFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceZeroToOneBlendFunction_to_string_pretty(HUDInterfaceZeroToOneBlendFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceZeroToOneBlendFunction HUDInterfaceZeroToOneBlendFunction_from_string(const char *value);

    enum HUDInterfaceWrapMode : TagEnum {
        HUD_INTERFACE_WRAP_MODE_CLAMP,
        HUD_INTERFACE_WRAP_MODE_WRAP,
        HUD_INTERFACE_WRAP_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceWrapMode_to_string(HUDInterfaceWrapMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceWrapMode_to_string_pretty(HUDInterfaceWrapMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceWrapMode HUDInterfaceWrapMode_from_string(const char *value);

    enum HUDInterfaceAnchor : TagEnum {
        HUD_INTERFACE_ANCHOR_TOP_LEFT,
        HUD_INTERFACE_ANCHOR_TOP_RIGHT,
        HUD_INTERFACE_ANCHOR_BOTTOM_LEFT,
        HUD_INTERFACE_ANCHOR_BOTTOM_RIGHT,
        HUD_INTERFACE_ANCHOR_CENTER,
        HUD_INTERFACE_ANCHOR_TOP_CENTER,
        HUD_INTERFACE_ANCHOR_BOTTOM_CENTER,
        HUD_INTERFACE_ANCHOR_LEFT_CENTER,
        HUD_INTERFACE_ANCHOR_RIGHT_CENTER,
        HUD_INTERFACE_ANCHOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceAnchor_to_string(HUDInterfaceAnchor value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceAnchor_to_string_pretty(HUDInterfaceAnchor value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceAnchor HUDInterfaceAnchor_from_string(const char *value);

    enum HUDInterfaceChildAnchor : TagEnum {
        HUD_INTERFACE_CHILD_ANCHOR_FROM_PARENT,
        HUD_INTERFACE_CHILD_ANCHOR_TOP_LEFT,
        HUD_INTERFACE_CHILD_ANCHOR_TOP_RIGHT,
        HUD_INTERFACE_CHILD_ANCHOR_BOTTOM_LEFT,
        HUD_INTERFACE_CHILD_ANCHOR_BOTTOM_RIGHT,
        HUD_INTERFACE_CHILD_ANCHOR_CENTER,
        HUD_INTERFACE_CHILD_ANCHOR_TOP_CENTER,
        HUD_INTERFACE_CHILD_ANCHOR_BOTTOM_CENTER,
        HUD_INTERFACE_CHILD_ANCHOR_LEFT_CENTER,
        HUD_INTERFACE_CHILD_ANCHOR_RIGHT_CENTER,
        HUD_INTERFACE_CHILD_ANCHOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceChildAnchor_to_string(HUDInterfaceChildAnchor value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceChildAnchor_to_string_pretty(HUDInterfaceChildAnchor value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceChildAnchor HUDInterfaceChildAnchor_from_string(const char *value);

    enum InputDeviceDefaultsDeviceType : TagEnum {
        INPUT_DEVICE_DEFAULTS_DEVICE_TYPE_MOUSE_AND_KEYBOARD,
        INPUT_DEVICE_DEFAULTS_DEVICE_TYPE_JOYSTICKS_GAMEPADS_ETC,
        INPUT_DEVICE_DEFAULTS_DEVICE_TYPE_FULL_PROFILE_DEFINITION,
        INPUT_DEVICE_DEFAULTS_DEVICE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *InputDeviceDefaultsDeviceType_to_string(InputDeviceDefaultsDeviceType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *InputDeviceDefaultsDeviceType_to_string_pretty(InputDeviceDefaultsDeviceType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    InputDeviceDefaultsDeviceType InputDeviceDefaultsDeviceType_from_string(const char *value);

    enum ItemFunctionIn : TagEnum {
        ITEM_FUNCTION_IN_NONE,
        ITEM_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ItemFunctionIn_to_string(ItemFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ItemFunctionIn_to_string_pretty(ItemFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ItemFunctionIn ItemFunctionIn_from_string(const char *value);

    enum LensFlareRadiusScaledBy : TagEnum {
        LENS_FLARE_RADIUS_SCALED_BY_NONE,
        LENS_FLARE_RADIUS_SCALED_BY_ROTATION,
        LENS_FLARE_RADIUS_SCALED_BY_ROTATION_AND_STRAFING,
        LENS_FLARE_RADIUS_SCALED_BY_DISTANCE_FROM_CENTER,
        LENS_FLARE_RADIUS_SCALED_BY_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LensFlareRadiusScaledBy_to_string(LensFlareRadiusScaledBy value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LensFlareRadiusScaledBy_to_string_pretty(LensFlareRadiusScaledBy value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LensFlareRadiusScaledBy LensFlareRadiusScaledBy_from_string(const char *value);

    enum LensFlareOcclusionOffsetDirection : TagEnum {
        LENS_FLARE_OCCLUSION_OFFSET_DIRECTION_TOWARD_VIEWER,
        LENS_FLARE_OCCLUSION_OFFSET_DIRECTION_MARKER_FORWARD,
        LENS_FLARE_OCCLUSION_OFFSET_DIRECTION_NONE,
        LENS_FLARE_OCCLUSION_OFFSET_DIRECTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LensFlareOcclusionOffsetDirection_to_string(LensFlareOcclusionOffsetDirection value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LensFlareOcclusionOffsetDirection_to_string_pretty(LensFlareOcclusionOffsetDirection value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LensFlareOcclusionOffsetDirection LensFlareOcclusionOffsetDirection_from_string(const char *value);

    enum LensFlareRotationFunction : TagEnum {
        LENS_FLARE_ROTATION_FUNCTION_NONE,
        LENS_FLARE_ROTATION_FUNCTION_ROTATION_A,
        LENS_FLARE_ROTATION_FUNCTION_ROTATION_B,
        LENS_FLARE_ROTATION_FUNCTION_ROTATION_TRANSLATION,
        LENS_FLARE_ROTATION_FUNCTION_TRANSLATION,
        LENS_FLARE_ROTATION_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LensFlareRotationFunction_to_string(LensFlareRotationFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LensFlareRotationFunction_to_string_pretty(LensFlareRotationFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LensFlareRotationFunction LensFlareRotationFunction_from_string(const char *value);

    enum MeterInterpolateColors : TagEnum {
        METER_INTERPOLATE_COLORS_LINEARLY,
        METER_INTERPOLATE_COLORS_FASTER_NEAR_EMPTY,
        METER_INTERPOLATE_COLORS_FASTER_NEAR_FULL,
        METER_INTERPOLATE_COLORS_THROUGH_RANDOM_NOISE,
        METER_INTERPOLATE_COLORS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MeterInterpolateColors_to_string(MeterInterpolateColors value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MeterInterpolateColors_to_string_pretty(MeterInterpolateColors value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MeterInterpolateColors MeterInterpolateColors_from_string(const char *value);

    enum MeterAnchorColors : TagEnum {
        METER_ANCHOR_COLORS_AT_BOTH_ENDS,
        METER_ANCHOR_COLORS_AT_EMPTY,
        METER_ANCHOR_COLORS_AT_FULL,
        METER_ANCHOR_COLORS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MeterAnchorColors_to_string(MeterAnchorColors value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MeterAnchorColors_to_string_pretty(MeterAnchorColors value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MeterAnchorColors MeterAnchorColors_from_string(const char *value);

    enum AnimationFunction : TagEnum {
        ANIMATION_FUNCTION_A_OUT,
        ANIMATION_FUNCTION_B_OUT,
        ANIMATION_FUNCTION_C_OUT,
        ANIMATION_FUNCTION_D_OUT,
        ANIMATION_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *AnimationFunction_to_string(AnimationFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *AnimationFunction_to_string_pretty(AnimationFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    AnimationFunction AnimationFunction_from_string(const char *value);

    enum AnimationFunctionControls : TagEnum {
        ANIMATION_FUNCTION_CONTROLS_FRAME,
        ANIMATION_FUNCTION_CONTROLS_SCALE,
        ANIMATION_FUNCTION_CONTROLS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *AnimationFunctionControls_to_string(AnimationFunctionControls value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *AnimationFunctionControls_to_string_pretty(AnimationFunctionControls value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    AnimationFunctionControls AnimationFunctionControls_from_string(const char *value);

    enum AnimationType : TagEnum {
        ANIMATION_TYPE_BASE,
        ANIMATION_TYPE_OVERLAY,
        ANIMATION_TYPE_REPLACEMENT,
        ANIMATION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *AnimationType_to_string(AnimationType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *AnimationType_to_string_pretty(AnimationType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    AnimationType AnimationType_from_string(const char *value);

    enum AnimationFrameInfoType : TagEnum {
        ANIMATION_FRAME_INFO_TYPE_NONE,
        ANIMATION_FRAME_INFO_TYPE_DX_DY,
        ANIMATION_FRAME_INFO_TYPE_DX_DY_DYAW,
        ANIMATION_FRAME_INFO_TYPE_DX_DY_DZ_DYAW,
        ANIMATION_FRAME_INFO_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *AnimationFrameInfoType_to_string(AnimationFrameInfoType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *AnimationFrameInfoType_to_string_pretty(AnimationFrameInfoType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    AnimationFrameInfoType AnimationFrameInfoType_from_string(const char *value);

    enum PredictedResourceType : TagEnum {
        PREDICTED_RESOURCE_TYPE_BITMAP,
        PREDICTED_RESOURCE_TYPE_SOUND,
        PREDICTED_RESOURCE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *PredictedResourceType_to_string(PredictedResourceType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *PredictedResourceType_to_string_pretty(PredictedResourceType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    PredictedResourceType PredictedResourceType_from_string(const char *value);

    enum ObjectNoise : TagEnum {
        OBJECT_NOISE_SILENT,
        OBJECT_NOISE_MEDIUM,
        OBJECT_NOISE_LOUD,
        OBJECT_NOISE_SHOUT,
        OBJECT_NOISE_QUIET,
        OBJECT_NOISE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ObjectNoise_to_string(ObjectNoise value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ObjectNoise_to_string_pretty(ObjectNoise value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ObjectNoise ObjectNoise_from_string(const char *value);

    enum ObjectFunctionIn : TagEnum {
        OBJECT_FUNCTION_IN_NONE,
        OBJECT_FUNCTION_IN_BODY_VITALITY,
        OBJECT_FUNCTION_IN_SHIELD_VITALITY,
        OBJECT_FUNCTION_IN_RECENT_BODY_DAMAGE,
        OBJECT_FUNCTION_IN_RECENT_SHIELD_DAMAGE,
        OBJECT_FUNCTION_IN_RANDOM_CONSTANT,
        OBJECT_FUNCTION_IN_UMBRELLA_SHIELD_VITALITY,
        OBJECT_FUNCTION_IN_SHIELD_STUN,
        OBJECT_FUNCTION_IN_RECENT_UMBRELLA_SHIELD_VITALITY,
        OBJECT_FUNCTION_IN_UMBRELLA_SHIELD_STUN,
        OBJECT_FUNCTION_IN_REGION,
        OBJECT_FUNCTION_IN_REGION_1,
        OBJECT_FUNCTION_IN_REGION_2,
        OBJECT_FUNCTION_IN_REGION_3,
        OBJECT_FUNCTION_IN_REGION_4,
        OBJECT_FUNCTION_IN_REGION_5,
        OBJECT_FUNCTION_IN_REGION_6,
        OBJECT_FUNCTION_IN_REGION_7,
        OBJECT_FUNCTION_IN_ALIVE,
        OBJECT_FUNCTION_IN_COMPASS,
        OBJECT_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ObjectFunctionIn_to_string(ObjectFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ObjectFunctionIn_to_string_pretty(ObjectFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ObjectFunctionIn ObjectFunctionIn_from_string(const char *value);

    enum ObjectType : TagEnum {
        OBJECT_TYPE_BIPED,
        OBJECT_TYPE_VEHICLE,
        OBJECT_TYPE_WEAPON,
        OBJECT_TYPE_EQUIPMENT,
        OBJECT_TYPE_GARBAGE,
        OBJECT_TYPE_PROJECTILE,
        OBJECT_TYPE_SCENERY,
        OBJECT_TYPE_DEVICE_MACHINE,
        OBJECT_TYPE_DEVICE_CONTROL,
        OBJECT_TYPE_DEVICE_LIGHT_FIXTURE,
        OBJECT_TYPE_PLACEHOLDER,
        OBJECT_TYPE_SOUND_SCENERY,
        OBJECT_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ObjectType_to_string(ObjectType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ObjectType_to_string_pretty(ObjectType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ObjectType ObjectType_from_string(const char *value);

    enum ParticleOrientation : TagEnum {
        PARTICLE_ORIENTATION_SCREEN_FACING,
        PARTICLE_ORIENTATION_PARALLEL_TO_DIRECTION,
        PARTICLE_ORIENTATION_PERPENDICULAR_TO_DIRECTION,
        PARTICLE_ORIENTATION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleOrientation_to_string(ParticleOrientation value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleOrientation_to_string_pretty(ParticleOrientation value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleOrientation ParticleOrientation_from_string(const char *value);

    enum ParticleAnchor : TagEnum {
        PARTICLE_ANCHOR_WITH_PRIMARY,
        PARTICLE_ANCHOR_WITH_SCREEN_SPACE,
        PARTICLE_ANCHOR_ZSPRITE,
        PARTICLE_ANCHOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleAnchor_to_string(ParticleAnchor value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleAnchor_to_string_pretty(ParticleAnchor value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleAnchor ParticleAnchor_from_string(const char *value);

    enum ParticleSystemParticleCreationPhysics : TagEnum {
        PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_DEFAULT,
        PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_EXPLOSION,
        PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_JET,
        PARTICLE_SYSTEM_PARTICLE_CREATION_PHYSICS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleSystemParticleCreationPhysics_to_string(ParticleSystemParticleCreationPhysics value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleSystemParticleCreationPhysics_to_string_pretty(ParticleSystemParticleCreationPhysics value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleSystemParticleCreationPhysics ParticleSystemParticleCreationPhysics_from_string(const char *value);

    enum ParticleSystemParticleUpdatePhysics : TagEnum {
        PARTICLE_SYSTEM_PARTICLE_UPDATE_PHYSICS_DEFAULT,
        PARTICLE_SYSTEM_PARTICLE_UPDATE_PHYSICS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleSystemParticleUpdatePhysics_to_string(ParticleSystemParticleUpdatePhysics value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleSystemParticleUpdatePhysics_to_string_pretty(ParticleSystemParticleUpdatePhysics value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleSystemParticleUpdatePhysics ParticleSystemParticleUpdatePhysics_from_string(const char *value);

    enum ParticleSystemComplexSpriteRenderMode : TagEnum {
        PARTICLE_SYSTEM_COMPLEX_SPRITE_RENDER_MODE_SIMPLE,
        PARTICLE_SYSTEM_COMPLEX_SPRITE_RENDER_MODE_ROTATIONAL,
        PARTICLE_SYSTEM_COMPLEX_SPRITE_RENDER_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleSystemComplexSpriteRenderMode_to_string(ParticleSystemComplexSpriteRenderMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleSystemComplexSpriteRenderMode_to_string_pretty(ParticleSystemComplexSpriteRenderMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleSystemComplexSpriteRenderMode ParticleSystemComplexSpriteRenderMode_from_string(const char *value);

    enum ParticleSystemSystemUpdatePhysics : TagEnum {
        PARTICLE_SYSTEM_SYSTEM_UPDATE_PHYSICS_DEFAULT,
        PARTICLE_SYSTEM_SYSTEM_UPDATE_PHYSICS_EXPLOSION,
        PARTICLE_SYSTEM_SYSTEM_UPDATE_PHYSICS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleSystemSystemUpdatePhysics_to_string(ParticleSystemSystemUpdatePhysics value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleSystemSystemUpdatePhysics_to_string_pretty(ParticleSystemSystemUpdatePhysics value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleSystemSystemUpdatePhysics ParticleSystemSystemUpdatePhysics_from_string(const char *value);

    enum PhysicsFrictionType : TagEnum {
        PHYSICS_FRICTION_TYPE_POINT,
        PHYSICS_FRICTION_TYPE_FORWARD,
        PHYSICS_FRICTION_TYPE_LEFT,
        PHYSICS_FRICTION_TYPE_UP,
        PHYSICS_FRICTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *PhysicsFrictionType_to_string(PhysicsFrictionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *PhysicsFrictionType_to_string_pretty(PhysicsFrictionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    PhysicsFrictionType PhysicsFrictionType_from_string(const char *value);

    enum ProjectileResponse : TagEnum {
        PROJECTILE_RESPONSE_DISAPPEAR,
        PROJECTILE_RESPONSE_DETONATE,
        PROJECTILE_RESPONSE_REFLECT,
        PROJECTILE_RESPONSE_OVERPENETRATE,
        PROJECTILE_RESPONSE_ATTACH,
        PROJECTILE_RESPONSE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileResponse_to_string(ProjectileResponse value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileResponse_to_string_pretty(ProjectileResponse value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileResponse ProjectileResponse_from_string(const char *value);

    enum ProjectileScaleEffectsBy : TagEnum {
        PROJECTILE_SCALE_EFFECTS_BY_DAMAGE,
        PROJECTILE_SCALE_EFFECTS_BY_ANGLE,
        PROJECTILE_SCALE_EFFECTS_BY_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileScaleEffectsBy_to_string(ProjectileScaleEffectsBy value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileScaleEffectsBy_to_string_pretty(ProjectileScaleEffectsBy value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileScaleEffectsBy ProjectileScaleEffectsBy_from_string(const char *value);

    enum ProjectileDetonationTimerStarts : TagEnum {
        PROJECTILE_DETONATION_TIMER_STARTS_IMMEDIATELY,
        PROJECTILE_DETONATION_TIMER_STARTS_AFTER_FIRST_BOUNCE,
        PROJECTILE_DETONATION_TIMER_STARTS_WHEN_AT_REST,
        PROJECTILE_DETONATION_TIMER_STARTS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileDetonationTimerStarts_to_string(ProjectileDetonationTimerStarts value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileDetonationTimerStarts_to_string_pretty(ProjectileDetonationTimerStarts value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileDetonationTimerStarts ProjectileDetonationTimerStarts_from_string(const char *value);

    enum ProjectileFunctionIn : TagEnum {
        PROJECTILE_FUNCTION_IN_NONE,
        PROJECTILE_FUNCTION_IN_RANGE_REMAINING,
        PROJECTILE_FUNCTION_IN_TIME_REMAINING,
        PROJECTILE_FUNCTION_IN_TRACER,
        PROJECTILE_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileFunctionIn_to_string(ProjectileFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileFunctionIn_to_string_pretty(ProjectileFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileFunctionIn ProjectileFunctionIn_from_string(const char *value);

    enum ScenarioType : TagEnum {
        SCENARIO_TYPE_SINGLEPLAYER,
        SCENARIO_TYPE_MULTIPLAYER,
        SCENARIO_TYPE_USER_INTERFACE,
        SCENARIO_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioType_to_string(ScenarioType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioType_to_string_pretty(ScenarioType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioType ScenarioType_from_string(const char *value);

    enum ScenarioSpawnType : TagEnum {
        SCENARIO_SPAWN_TYPE_NONE,
        SCENARIO_SPAWN_TYPE_CTF,
        SCENARIO_SPAWN_TYPE_SLAYER,
        SCENARIO_SPAWN_TYPE_ODDBALL,
        SCENARIO_SPAWN_TYPE_KING_OF_THE_HILL,
        SCENARIO_SPAWN_TYPE_RACE,
        SCENARIO_SPAWN_TYPE_TERMINATOR,
        SCENARIO_SPAWN_TYPE_STUB,
        SCENARIO_SPAWN_TYPE_IGNORED1,
        SCENARIO_SPAWN_TYPE_IGNORED2,
        SCENARIO_SPAWN_TYPE_IGNORED3,
        SCENARIO_SPAWN_TYPE_IGNORED4,
        SCENARIO_SPAWN_TYPE_ALL_GAMES,
        SCENARIO_SPAWN_TYPE_ALL_EXCEPT_CTF,
        SCENARIO_SPAWN_TYPE_ALL_EXCEPT_RACE_AND_CTF,
        SCENARIO_SPAWN_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioSpawnType_to_string(ScenarioSpawnType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioSpawnType_to_string_pretty(ScenarioSpawnType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioSpawnType ScenarioSpawnType_from_string(const char *value);

    enum ScenarioNetgameFlagType : TagEnum {
        SCENARIO_NETGAME_FLAG_TYPE_CTF_FLAG,
        SCENARIO_NETGAME_FLAG_TYPE_CTF_VEHICLE,
        SCENARIO_NETGAME_FLAG_TYPE_ODDBALL_BALL_SPAWN,
        SCENARIO_NETGAME_FLAG_TYPE_RACE_TRACK,
        SCENARIO_NETGAME_FLAG_TYPE_RACE_VEHICLE,
        SCENARIO_NETGAME_FLAG_TYPE_VEGAS_BANK,
        SCENARIO_NETGAME_FLAG_TYPE_TELEPORT_FROM,
        SCENARIO_NETGAME_FLAG_TYPE_TELEPORT_TO,
        SCENARIO_NETGAME_FLAG_TYPE_HILL_FLAG,
        SCENARIO_NETGAME_FLAG_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioNetgameFlagType_to_string(ScenarioNetgameFlagType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioNetgameFlagType_to_string_pretty(ScenarioNetgameFlagType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioNetgameFlagType ScenarioNetgameFlagType_from_string(const char *value);

    enum ScenarioReturnState : TagEnum {
        SCENARIO_RETURN_STATE_NONE,
        SCENARIO_RETURN_STATE_SLEEPING,
        SCENARIO_RETURN_STATE_ALERT,
        SCENARIO_RETURN_STATE_MOVING_REPEAT_SAME_POSITION,
        SCENARIO_RETURN_STATE_MOVING_LOOP,
        SCENARIO_RETURN_STATE_MOVING_LOOP_BACK_AND_FORTH,
        SCENARIO_RETURN_STATE_MOVING_LOOP_RANDOMLY,
        SCENARIO_RETURN_STATE_MOVING_RANDOMLY,
        SCENARIO_RETURN_STATE_GUARDING,
        SCENARIO_RETURN_STATE_GUARDING_AT_GUARD_POSITION,
        SCENARIO_RETURN_STATE_SEARCHING,
        SCENARIO_RETURN_STATE_FLEEING,
        SCENARIO_RETURN_STATE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioReturnState_to_string(ScenarioReturnState value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioReturnState_to_string_pretty(ScenarioReturnState value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioReturnState ScenarioReturnState_from_string(const char *value);

    enum ScenarioUniqueLeaderType : TagEnum {
        SCENARIO_UNIQUE_LEADER_TYPE_NORMAL,
        SCENARIO_UNIQUE_LEADER_TYPE_NONE,
        SCENARIO_UNIQUE_LEADER_TYPE_RANDOM,
        SCENARIO_UNIQUE_LEADER_TYPE_SGT_JOHNSON,
        SCENARIO_UNIQUE_LEADER_TYPE_SGT_LEHTO,
        SCENARIO_UNIQUE_LEADER_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioUniqueLeaderType_to_string(ScenarioUniqueLeaderType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioUniqueLeaderType_to_string_pretty(ScenarioUniqueLeaderType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioUniqueLeaderType ScenarioUniqueLeaderType_from_string(const char *value);

    enum ScenarioMajorUpgrade : TagEnum {
        SCENARIO_MAJOR_UPGRADE_NORMAL,
        SCENARIO_MAJOR_UPGRADE_FEW,
        SCENARIO_MAJOR_UPGRADE_MANY,
        SCENARIO_MAJOR_UPGRADE_NONE,
        SCENARIO_MAJOR_UPGRADE_ALL,
        SCENARIO_MAJOR_UPGRADE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioMajorUpgrade_to_string(ScenarioMajorUpgrade value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioMajorUpgrade_to_string_pretty(ScenarioMajorUpgrade value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioMajorUpgrade ScenarioMajorUpgrade_from_string(const char *value);

    enum ScenarioChangeAttackingDefendingStateWhen : TagEnum {
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_NEVER,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_75_STRENGTH,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_50_STRENGTH,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_25_STRENGTH,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_ANYBODY_DEAD,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_25_DEAD,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_50_DEAD,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_75_DEAD,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_ALL_BUT_ONE_DEAD,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_ALL_DEAD,
        SCENARIO_CHANGE_ATTACKING_DEFENDING_STATE_WHEN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioChangeAttackingDefendingStateWhen_to_string(ScenarioChangeAttackingDefendingStateWhen value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioChangeAttackingDefendingStateWhen_to_string_pretty(ScenarioChangeAttackingDefendingStateWhen value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioChangeAttackingDefendingStateWhen ScenarioChangeAttackingDefendingStateWhen_from_string(const char *value);

    enum ScenarioGroupIndex : TagEnum {
        SCENARIO_GROUP_INDEX_A,
        SCENARIO_GROUP_INDEX_B,
        SCENARIO_GROUP_INDEX_C,
        SCENARIO_GROUP_INDEX_D,
        SCENARIO_GROUP_INDEX_E,
        SCENARIO_GROUP_INDEX_F,
        SCENARIO_GROUP_INDEX_G,
        SCENARIO_GROUP_INDEX_H,
        SCENARIO_GROUP_INDEX_I,
        SCENARIO_GROUP_INDEX_J,
        SCENARIO_GROUP_INDEX_K,
        SCENARIO_GROUP_INDEX_L,
        SCENARIO_GROUP_INDEX_M,
        SCENARIO_GROUP_INDEX_N,
        SCENARIO_GROUP_INDEX_O,
        SCENARIO_GROUP_INDEX_P,
        SCENARIO_GROUP_INDEX_Q,
        SCENARIO_GROUP_INDEX_R,
        SCENARIO_GROUP_INDEX_S,
        SCENARIO_GROUP_INDEX_T,
        SCENARIO_GROUP_INDEX_U,
        SCENARIO_GROUP_INDEX_V,
        SCENARIO_GROUP_INDEX_W,
        SCENARIO_GROUP_INDEX_X,
        SCENARIO_GROUP_INDEX_Y,
        SCENARIO_GROUP_INDEX_Z,
        SCENARIO_GROUP_INDEX_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioGroupIndex_to_string(ScenarioGroupIndex value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioGroupIndex_to_string_pretty(ScenarioGroupIndex value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioGroupIndex ScenarioGroupIndex_from_string(const char *value);

    enum ScenarioTeamIndex : TagEnum {
        SCENARIO_TEAM_INDEX_DEFAULT_BY_UNIT,
        SCENARIO_TEAM_INDEX_PLAYER,
        SCENARIO_TEAM_INDEX_HUMAN,
        SCENARIO_TEAM_INDEX_COVENANT,
        SCENARIO_TEAM_INDEX_FLOOD,
        SCENARIO_TEAM_INDEX_SENTINEL,
        SCENARIO_TEAM_INDEX_UNUSED6,
        SCENARIO_TEAM_INDEX_UNUSED7,
        SCENARIO_TEAM_INDEX_UNUSED8,
        SCENARIO_TEAM_INDEX_UNUSED9,
        SCENARIO_TEAM_INDEX_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioTeamIndex_to_string(ScenarioTeamIndex value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioTeamIndex_to_string_pretty(ScenarioTeamIndex value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioTeamIndex ScenarioTeamIndex_from_string(const char *value);

    enum ScenarioSearchBehavior : TagEnum {
        SCENARIO_SEARCH_BEHAVIOR_NORMAL,
        SCENARIO_SEARCH_BEHAVIOR_NEVER,
        SCENARIO_SEARCH_BEHAVIOR_TENACIOUS,
        SCENARIO_SEARCH_BEHAVIOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioSearchBehavior_to_string(ScenarioSearchBehavior value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioSearchBehavior_to_string_pretty(ScenarioSearchBehavior value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioSearchBehavior ScenarioSearchBehavior_from_string(const char *value);

    enum ScenarioAtomType : TagEnum {
        SCENARIO_ATOM_TYPE_PAUSE,
        SCENARIO_ATOM_TYPE_GO_TO,
        SCENARIO_ATOM_TYPE_GO_TO_AND_FACE,
        SCENARIO_ATOM_TYPE_MOVE_IN_DIRECTION,
        SCENARIO_ATOM_TYPE_LOOK,
        SCENARIO_ATOM_TYPE_ANIMATION_MODE,
        SCENARIO_ATOM_TYPE_CROUCH,
        SCENARIO_ATOM_TYPE_SHOOT,
        SCENARIO_ATOM_TYPE_GRENADE,
        SCENARIO_ATOM_TYPE_VEHICLE,
        SCENARIO_ATOM_TYPE_RUNNING_JUMP,
        SCENARIO_ATOM_TYPE_TARGETED_JUMP,
        SCENARIO_ATOM_TYPE_SCRIPT,
        SCENARIO_ATOM_TYPE_ANIMATE,
        SCENARIO_ATOM_TYPE_RECORDING,
        SCENARIO_ATOM_TYPE_ACTION,
        SCENARIO_ATOM_TYPE_VOCALIZE,
        SCENARIO_ATOM_TYPE_TARGETING,
        SCENARIO_ATOM_TYPE_INITIATIVE,
        SCENARIO_ATOM_TYPE_WAIT,
        SCENARIO_ATOM_TYPE_LOOP,
        SCENARIO_ATOM_TYPE_DIE,
        SCENARIO_ATOM_TYPE_MOVE_IMMEDIATE,
        SCENARIO_ATOM_TYPE_LOOK_RANDOM,
        SCENARIO_ATOM_TYPE_LOOK_PLAYER,
        SCENARIO_ATOM_TYPE_LOOK_OBJECT,
        SCENARIO_ATOM_TYPE_SET_RADIUS,
        SCENARIO_ATOM_TYPE_TELEPORT,
        SCENARIO_ATOM_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioAtomType_to_string(ScenarioAtomType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioAtomType_to_string_pretty(ScenarioAtomType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioAtomType ScenarioAtomType_from_string(const char *value);

    enum ScenarioSelectionType : TagEnum {
        SCENARIO_SELECTION_TYPE_FRIENDLY_ACTOR,
        SCENARIO_SELECTION_TYPE_DISEMBODIED,
        SCENARIO_SELECTION_TYPE_IN_PLAYER_S_VEHICLE,
        SCENARIO_SELECTION_TYPE_NOT_IN_A_VEHICLE,
        SCENARIO_SELECTION_TYPE_PREFER_SERGEANT,
        SCENARIO_SELECTION_TYPE_ANY_ACTOR,
        SCENARIO_SELECTION_TYPE_RADIO_UNIT,
        SCENARIO_SELECTION_TYPE_RADIO_SERGEANT,
        SCENARIO_SELECTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioSelectionType_to_string(ScenarioSelectionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioSelectionType_to_string_pretty(ScenarioSelectionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioSelectionType ScenarioSelectionType_from_string(const char *value);

    enum ScenarioAddressee : TagEnum {
        SCENARIO_ADDRESSEE_NONE,
        SCENARIO_ADDRESSEE_PLAYER,
        SCENARIO_ADDRESSEE_PARTICIPANT,
        SCENARIO_ADDRESSEE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioAddressee_to_string(ScenarioAddressee value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioAddressee_to_string_pretty(ScenarioAddressee value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioAddressee ScenarioAddressee_from_string(const char *value);

    enum ScenarioScriptType : TagEnum {
        SCENARIO_SCRIPT_TYPE_STARTUP,
        SCENARIO_SCRIPT_TYPE_DORMANT,
        SCENARIO_SCRIPT_TYPE_CONTINUOUS,
        SCENARIO_SCRIPT_TYPE_STATIC,
        SCENARIO_SCRIPT_TYPE_STUB,
        SCENARIO_SCRIPT_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioScriptType_to_string(ScenarioScriptType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioScriptType_to_string_pretty(ScenarioScriptType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioScriptType ScenarioScriptType_from_string(const char *value);

    enum ScenarioScriptValueType : TagEnum {
        SCENARIO_SCRIPT_VALUE_TYPE_UNPARSED,
        SCENARIO_SCRIPT_VALUE_TYPE_SPECIAL_FORM,
        SCENARIO_SCRIPT_VALUE_TYPE_FUNCTION_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_PASSTHROUGH,
        SCENARIO_SCRIPT_VALUE_TYPE_VOID,
        SCENARIO_SCRIPT_VALUE_TYPE_BOOLEAN,
        SCENARIO_SCRIPT_VALUE_TYPE_REAL,
        SCENARIO_SCRIPT_VALUE_TYPE_SHORT,
        SCENARIO_SCRIPT_VALUE_TYPE_LONG,
        SCENARIO_SCRIPT_VALUE_TYPE_STRING,
        SCENARIO_SCRIPT_VALUE_TYPE_SCRIPT,
        SCENARIO_SCRIPT_VALUE_TYPE_TRIGGER_VOLUME,
        SCENARIO_SCRIPT_VALUE_TYPE_CUTSCENE_FLAG,
        SCENARIO_SCRIPT_VALUE_TYPE_CUTSCENE_CAMERA_POINT,
        SCENARIO_SCRIPT_VALUE_TYPE_CUTSCENE_TITLE,
        SCENARIO_SCRIPT_VALUE_TYPE_CUTSCENE_RECORDING,
        SCENARIO_SCRIPT_VALUE_TYPE_DEVICE_GROUP,
        SCENARIO_SCRIPT_VALUE_TYPE_AI,
        SCENARIO_SCRIPT_VALUE_TYPE_AI_COMMAND_LIST,
        SCENARIO_SCRIPT_VALUE_TYPE_STARTING_PROFILE,
        SCENARIO_SCRIPT_VALUE_TYPE_CONVERSATION,
        SCENARIO_SCRIPT_VALUE_TYPE_NAVPOINT,
        SCENARIO_SCRIPT_VALUE_TYPE_HUD_MESSAGE,
        SCENARIO_SCRIPT_VALUE_TYPE_OBJECT_LIST,
        SCENARIO_SCRIPT_VALUE_TYPE_SOUND,
        SCENARIO_SCRIPT_VALUE_TYPE_EFFECT,
        SCENARIO_SCRIPT_VALUE_TYPE_DAMAGE,
        SCENARIO_SCRIPT_VALUE_TYPE_LOOPING_SOUND,
        SCENARIO_SCRIPT_VALUE_TYPE_ANIMATION_GRAPH,
        SCENARIO_SCRIPT_VALUE_TYPE_ACTOR_VARIANT,
        SCENARIO_SCRIPT_VALUE_TYPE_DAMAGE_EFFECT,
        SCENARIO_SCRIPT_VALUE_TYPE_OBJECT_DEFINITION,
        SCENARIO_SCRIPT_VALUE_TYPE_GAME_DIFFICULTY,
        SCENARIO_SCRIPT_VALUE_TYPE_TEAM,
        SCENARIO_SCRIPT_VALUE_TYPE_AI_DEFAULT_STATE,
        SCENARIO_SCRIPT_VALUE_TYPE_ACTOR_TYPE,
        SCENARIO_SCRIPT_VALUE_TYPE_HUD_CORNER,
        SCENARIO_SCRIPT_VALUE_TYPE_OBJECT,
        SCENARIO_SCRIPT_VALUE_TYPE_UNIT,
        SCENARIO_SCRIPT_VALUE_TYPE_VEHICLE,
        SCENARIO_SCRIPT_VALUE_TYPE_WEAPON,
        SCENARIO_SCRIPT_VALUE_TYPE_DEVICE,
        SCENARIO_SCRIPT_VALUE_TYPE_SCENERY,
        SCENARIO_SCRIPT_VALUE_TYPE_OBJECT_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_UNIT_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_VEHICLE_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_WEAPON_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_DEVICE_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_SCENERY_NAME,
        SCENARIO_SCRIPT_VALUE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioScriptValueType_to_string(ScenarioScriptValueType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioScriptValueType_to_string_pretty(ScenarioScriptValueType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioScriptValueType ScenarioScriptValueType_from_string(const char *value);

    enum ScenarioTextStyle : TagEnum {
        SCENARIO_TEXT_STYLE_PLAIN,
        SCENARIO_TEXT_STYLE_BOLD,
        SCENARIO_TEXT_STYLE_ITALIC,
        SCENARIO_TEXT_STYLE_CONDENSE,
        SCENARIO_TEXT_STYLE_UNDERLINE,
        SCENARIO_TEXT_STYLE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioTextStyle_to_string(ScenarioTextStyle value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioTextStyle_to_string_pretty(ScenarioTextStyle value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioTextStyle ScenarioTextStyle_from_string(const char *value);

    enum ScenarioJustification : TagEnum {
        SCENARIO_JUSTIFICATION_LEFT,
        SCENARIO_JUSTIFICATION_RIGHT,
        SCENARIO_JUSTIFICATION_CENTER,
        SCENARIO_JUSTIFICATION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioJustification_to_string(ScenarioJustification value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioJustification_to_string_pretty(ScenarioJustification value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioJustification ScenarioJustification_from_string(const char *value);

    enum ShaderDetailLevel : TagEnum {
        SHADER_DETAIL_LEVEL_HIGH,
        SHADER_DETAIL_LEVEL_MEDIUM,
        SHADER_DETAIL_LEVEL_LOW,
        SHADER_DETAIL_LEVEL_TURD,
        SHADER_DETAIL_LEVEL_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderDetailLevel_to_string(ShaderDetailLevel value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderDetailLevel_to_string_pretty(ShaderDetailLevel value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderDetailLevel ShaderDetailLevel_from_string(const char *value);

    enum ShaderColorFunctionType : TagEnum {
        SHADER_COLOR_FUNCTION_TYPE_CURRENT,
        SHADER_COLOR_FUNCTION_TYPE_NEXT_MAP,
        SHADER_COLOR_FUNCTION_TYPE_MULTIPLY,
        SHADER_COLOR_FUNCTION_TYPE_DOUBLE_MULTIPLY,
        SHADER_COLOR_FUNCTION_TYPE_ADD,
        SHADER_COLOR_FUNCTION_TYPE_ADD_SIGNED_CURRENT,
        SHADER_COLOR_FUNCTION_TYPE_ADD_SIGNED_NEXT_MAP,
        SHADER_COLOR_FUNCTION_TYPE_SUBTRACT_CURRENT,
        SHADER_COLOR_FUNCTION_TYPE_SUBTRACT_NEXT_MAP,
        SHADER_COLOR_FUNCTION_TYPE_BLEND_CURRENT_ALPHA,
        SHADER_COLOR_FUNCTION_TYPE_BLEND_CURRENT_ALPHA_INVERSE,
        SHADER_COLOR_FUNCTION_TYPE_BLEND_NEXT_MAP_ALPHA,
        SHADER_COLOR_FUNCTION_TYPE_BLEND_NEXT_MAP_ALPHA_INVERSE,
        SHADER_COLOR_FUNCTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderColorFunctionType_to_string(ShaderColorFunctionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderColorFunctionType_to_string_pretty(ShaderColorFunctionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderColorFunctionType ShaderColorFunctionType_from_string(const char *value);

    enum ShaderFirstMapType : TagEnum {
        SHADER_FIRST_MAP_TYPE_2D_MAP,
        SHADER_FIRST_MAP_TYPE_FIRST_MAP_IS_REFLECTION_CUBE_MAP,
        SHADER_FIRST_MAP_TYPE_FIRST_MAP_IS_OBJECT_CENTERED_CUBE_MAP,
        SHADER_FIRST_MAP_TYPE_FIRST_MAP_IS_VIEWER_CENTERED_CUBE_MAP,
        SHADER_FIRST_MAP_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderFirstMapType_to_string(ShaderFirstMapType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderFirstMapType_to_string_pretty(ShaderFirstMapType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderFirstMapType ShaderFirstMapType_from_string(const char *value);

    enum ShaderType : TagEnum {
        SHADER_TYPE_UNUSED,
        SHADER_TYPE_UNUSED1,
        SHADER_TYPE_UNUSED2,
        SHADER_TYPE_SHADER_ENVIRONMENT,
        SHADER_TYPE_SHADER_MODEL,
        SHADER_TYPE_SHADER_TRANSPARENT_GENERIC,
        SHADER_TYPE_SHADER_TRANSPARENT_CHICAGO,
        SHADER_TYPE_SHADER_TRANSPARENT_CHICAGO_EXTENDED,
        SHADER_TYPE_SHADER_TRANSPARENT_WATER,
        SHADER_TYPE_SHADER_TRANSPARENT_GLASS,
        SHADER_TYPE_SHADER_TRANSPARENT_METER,
        SHADER_TYPE_SHADER_TRANSPARENT_PLASMA,
        SHADER_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderType_to_string(ShaderType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderType_to_string_pretty(ShaderType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderType ShaderType_from_string(const char *value);

    enum ShaderDetailFunction : TagEnum {
        SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_MULTIPLY,
        SHADER_DETAIL_FUNCTION_MULTIPLY,
        SHADER_DETAIL_FUNCTION_DOUBLE_BIASED_ADD,
        SHADER_DETAIL_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderDetailFunction_to_string(ShaderDetailFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderDetailFunction_to_string_pretty(ShaderDetailFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderDetailFunction ShaderDetailFunction_from_string(const char *value);

    enum ShaderEnvironmentType : TagEnum {
        SHADER_ENVIRONMENT_TYPE_NORMAL,
        SHADER_ENVIRONMENT_TYPE_BLENDED,
        SHADER_ENVIRONMENT_TYPE_BLENDED_BASE_SPECULAR,
        SHADER_ENVIRONMENT_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderEnvironmentType_to_string(ShaderEnvironmentType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderEnvironmentType_to_string_pretty(ShaderEnvironmentType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderEnvironmentType ShaderEnvironmentType_from_string(const char *value);

    enum ShaderEnvironmentReflectionType : TagEnum {
        SHADER_ENVIRONMENT_REFLECTION_TYPE_BUMPED_CUBE_MAP,
        SHADER_ENVIRONMENT_REFLECTION_TYPE_FLAT_CUBE_MAP,
        SHADER_ENVIRONMENT_REFLECTION_TYPE_BUMPED_RADIOSITY,
        SHADER_ENVIRONMENT_REFLECTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderEnvironmentReflectionType_to_string(ShaderEnvironmentReflectionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderEnvironmentReflectionType_to_string_pretty(ShaderEnvironmentReflectionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderEnvironmentReflectionType ShaderEnvironmentReflectionType_from_string(const char *value);

    enum ShaderModelDetailMask : TagEnum {
        SHADER_MODEL_DETAIL_MASK_NONE,
        SHADER_MODEL_DETAIL_MASK_REFLECTION_MASK_INVERSE,
        SHADER_MODEL_DETAIL_MASK_REFLECTION_MASK,
        SHADER_MODEL_DETAIL_MASK_SELF_ILLUMINATION_MASK_INVERSE,
        SHADER_MODEL_DETAIL_MASK_SELF_ILLUMINATION_MASK,
        SHADER_MODEL_DETAIL_MASK_CHANGE_COLOR_MASK_INVERSE,
        SHADER_MODEL_DETAIL_MASK_CHANGE_COLOR_MASK,
        SHADER_MODEL_DETAIL_MASK_AUXILIARY_MASK_INVERSE,
        SHADER_MODEL_DETAIL_MASK_AUXILIARY_MASK,
        SHADER_MODEL_DETAIL_MASK_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderModelDetailMask_to_string(ShaderModelDetailMask value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderModelDetailMask_to_string_pretty(ShaderModelDetailMask value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderModelDetailMask ShaderModelDetailMask_from_string(const char *value);

    enum ShaderTransparentGenericStageInputColor : TagEnum {
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_ZERO,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_ONE,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_ONE_HALF,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_NEGATIVE_ONE,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_NEGATIVE_ONE_HALF,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_COLOR_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_COLOR_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_COLOR_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_COLOR_3,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_VERTEX_COLOR_0_DIFFUSE_LIGHT,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_VERTEX_COLOR_1_FADE_PERPENDICULAR,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_SCRATCH_COLOR_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_SCRATCH_COLOR_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_CONSTANT_COLOR_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_CONSTANT_COLOR_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_ALPHA_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_MAP_ALPHA_3,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_VERTEX_ALPHA_0_FADE_NONE,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_VERTEX_ALPHA_1_FADE_PERPENDICULAR,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_SCRATCH_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_SCRATCH_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_CONSTANT_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_CONSTANT_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_COLOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageInputColor_to_string(ShaderTransparentGenericStageInputColor value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageInputColor_to_string_pretty(ShaderTransparentGenericStageInputColor value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageInputColor ShaderTransparentGenericStageInputColor_from_string(const char *value);

    enum ShaderTransparentGenericStageInputAlpha : TagEnum {
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_ZERO,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_ONE,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_ONE_HALF,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_NEGATIVE_ONE,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_NEGATIVE_ONE_HALF,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_ALPHA_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_ALPHA_3,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_VERTEX_ALPHA_0_FADE_NONE,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_VERTEX_ALPHA_1_FADE_PERPENDICULAR,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_SCRATCH_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_SCRATCH_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_CONSTANT_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_CONSTANT_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_BLUE_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_BLUE_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_BLUE_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_MAP_BLUE_3,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_VERTEX_BLUE_0_BLUE_LIGHT,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_VERTEX_BLUE_1_FADE_PARALLEL,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_SCRATCH_BLUE_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_SCRATCH_BLUE_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_CONSTANT_BLUE_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_CONSTANT_BLUE_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_ALPHA_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageInputAlpha_to_string(ShaderTransparentGenericStageInputAlpha value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageInputAlpha_to_string_pretty(ShaderTransparentGenericStageInputAlpha value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageInputAlpha ShaderTransparentGenericStageInputAlpha_from_string(const char *value);

    enum ShaderTransparentGenericStageInputMappingColor : TagEnum {
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_CLAMP_X,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_1_CLAMP_X,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_1_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_CLAMP_X_1_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_1_2_CLAMP_X,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_X,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_X_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_INPUT_MAPPING_COLOR_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageInputMappingColor_to_string(ShaderTransparentGenericStageInputMappingColor value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageInputMappingColor_to_string_pretty(ShaderTransparentGenericStageInputMappingColor value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageInputMappingColor ShaderTransparentGenericStageInputMappingColor_from_string(const char *value);

    enum ShaderTransparentGenericStageOutputFunction : TagEnum {
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_FUNCTION_MULTIPLY,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_FUNCTION_DOT_PRODUCT,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageOutputFunction_to_string(ShaderTransparentGenericStageOutputFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageOutputFunction_to_string_pretty(ShaderTransparentGenericStageOutputFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageOutputFunction ShaderTransparentGenericStageOutputFunction_from_string(const char *value);

    enum ShaderTransparentGenericStageOutputMapping : TagEnum {
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_COLOR_IDENTITY,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_COLOR_SCALE_BY_1_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_COLOR_SCALE_BY_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_COLOR_SCALE_BY_4,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_COLOR_BIAS_BY_1_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_COLOR_EXPAND_NORMAL,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_MAPPING_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageOutputMapping_to_string(ShaderTransparentGenericStageOutputMapping value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageOutputMapping_to_string_pretty(ShaderTransparentGenericStageOutputMapping value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageOutputMapping ShaderTransparentGenericStageOutputMapping_from_string(const char *value);

    enum ShaderTransparentGenericStageOutput : TagEnum {
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_DISCARD,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_SCRATCH_ALPHA_0_FINAL_ALPHA,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_SCRATCH_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_VERTEX_ALPHA_0_FOG,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_VERTEX_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_MAP_ALPHA_0,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_MAP_ALPHA_1,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_MAP_ALPHA_2,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ALPHA_MAP_ALPHA_3,
        SHADER_TRANSPARENT_GENERIC_STAGE_OUTPUT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageOutput_to_string(ShaderTransparentGenericStageOutput value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageOutput_to_string_pretty(ShaderTransparentGenericStageOutput value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageOutput ShaderTransparentGenericStageOutput_from_string(const char *value);

    enum ShaderTransparentGlassReflectionType : TagEnum {
        SHADER_TRANSPARENT_GLASS_REFLECTION_TYPE_BUMPED_CUBE_MAP,
        SHADER_TRANSPARENT_GLASS_REFLECTION_TYPE_FLAT_CUBE_MAP,
        SHADER_TRANSPARENT_GLASS_REFLECTION_TYPE_DYNAMIC_MIRROR,
        SHADER_TRANSPARENT_GLASS_REFLECTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGlassReflectionType_to_string(ShaderTransparentGlassReflectionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGlassReflectionType_to_string_pretty(ShaderTransparentGlassReflectionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGlassReflectionType ShaderTransparentGlassReflectionType_from_string(const char *value);

    enum SoundFormat : TagEnum {
        SOUND_FORMAT_16_BIT_PCM,
        SOUND_FORMAT_XBOX_ADPCM,
        SOUND_FORMAT_IMA_ADPCM,
        SOUND_FORMAT_OGG_VORBIS,
        SOUND_FORMAT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundFormat_to_string(SoundFormat value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundFormat_to_string_pretty(SoundFormat value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundFormat SoundFormat_from_string(const char *value);

    enum SoundClass : TagEnum {
        SOUND_CLASS_PROJECTILE_IMPACT,
        SOUND_CLASS_PROJECTILE_DETONATION,
        SOUND_CLASS_UNUSED,
        SOUND_CLASS_UNUSED1,
        SOUND_CLASS_WEAPON_FIRE,
        SOUND_CLASS_WEAPON_READY,
        SOUND_CLASS_WEAPON_RELOAD,
        SOUND_CLASS_WEAPON_EMPTY,
        SOUND_CLASS_WEAPON_CHARGE,
        SOUND_CLASS_WEAPON_OVERHEAT,
        SOUND_CLASS_WEAPON_IDLE,
        SOUND_CLASS_UNUSED2,
        SOUND_CLASS_UNUSED3,
        SOUND_CLASS_OBJECT_IMPACTS,
        SOUND_CLASS_PARTICLE_IMPACTS,
        SOUND_CLASS_SLOW_PARTICLE_IMPACTS,
        SOUND_CLASS_UNUSED4,
        SOUND_CLASS_UNUSED5,
        SOUND_CLASS_UNIT_FOOTSTEPS,
        SOUND_CLASS_UNIT_DIALOG,
        SOUND_CLASS_UNUSED6,
        SOUND_CLASS_UNUSED7,
        SOUND_CLASS_VEHICLE_COLLISION,
        SOUND_CLASS_VEHICLE_ENGINE,
        SOUND_CLASS_UNUSED8,
        SOUND_CLASS_UNUSED9,
        SOUND_CLASS_DEVICE_DOOR,
        SOUND_CLASS_DEVICE_FORCE_FIELD,
        SOUND_CLASS_DEVICE_MACHINERY,
        SOUND_CLASS_DEVICE_NATURE,
        SOUND_CLASS_DEVICE_COMPUTERS,
        SOUND_CLASS_UNUSED10,
        SOUND_CLASS_MUSIC,
        SOUND_CLASS_AMBIENT_NATURE,
        SOUND_CLASS_AMBIENT_MACHINERY,
        SOUND_CLASS_AMBIENT_COMPUTERS,
        SOUND_CLASS_UNUSED11,
        SOUND_CLASS_UNUSED12,
        SOUND_CLASS_UNUSED13,
        SOUND_CLASS_FIRST_PERSON_DAMAGE,
        SOUND_CLASS_UNUSED14,
        SOUND_CLASS_UNUSED15,
        SOUND_CLASS_UNUSED16,
        SOUND_CLASS_UNUSED17,
        SOUND_CLASS_SCRIPTED_DIALOG_PLAYER,
        SOUND_CLASS_SCRIPTED_EFFECT,
        SOUND_CLASS_SCRIPTED_DIALOG_OTHER,
        SOUND_CLASS_SCRIPTED_DIALOG_FORCE_UNSPATIALIZED,
        SOUND_CLASS_UNUSED18,
        SOUND_CLASS_UNUSED19,
        SOUND_CLASS_GAME_EVENT,
        SOUND_CLASS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundClass_to_string(SoundClass value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundClass_to_string_pretty(SoundClass value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundClass SoundClass_from_string(const char *value);

    enum SoundSampleRate : TagEnum {
        SOUND_SAMPLE_RATE_22050_HZ,
        SOUND_SAMPLE_RATE_44100_HZ,
        SOUND_SAMPLE_RATE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundSampleRate_to_string(SoundSampleRate value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundSampleRate_to_string_pretty(SoundSampleRate value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundSampleRate SoundSampleRate_from_string(const char *value);

    enum SoundChannelCount : TagEnum {
        SOUND_CHANNEL_COUNT_MONO,
        SOUND_CHANNEL_COUNT_STEREO,
        SOUND_CHANNEL_COUNT_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundChannelCount_to_string(SoundChannelCount value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundChannelCount_to_string_pretty(SoundChannelCount value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundChannelCount SoundChannelCount_from_string(const char *value);

    enum UIGameDataInputReferenceFunction : TagEnum {
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_NULL,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_PLAYER_SETTINGS_MENU_UPDATE_DESC,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_UNUSED,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_PLAYLIST_SETTINGS_MENU_UPDATE_DESC,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GAMETYPE_SELECT_MENU_UPDATE_DESC,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MULTIPLAYER_TYPE_MENU_UPDATE_DESC,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SOLO_LEVEL_SELECT_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_DIFFICULTY_MENU_UPDATE_DESC,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_BUILD_NUMBER_TEXTBOX_ONLY,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SERVER_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_NETWORK_PREGAME_STATUS_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SPLITSCREEN_PREGAME_STATUS_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_NET_SPLITSCREEN_PREJOIN_PLAYERS,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_PROFILE_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_3WIDE_PLAYER_PROFILE_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_PLYR_PROF_EDIT_SELECT_MENU_UPD8,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_PLAYER_PROFILE_SMALL_MENU_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GAME_SETTINGS_LISTS_TEXT_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SOLO_GAME_OBJECTIVE_TEXT,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_COLOR_PICKER_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GAME_SETTINGS_LISTS_PIC_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MAIN_MENU_FAKE_ANIMATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_LEVEL_SELECT_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GET_ACTIVE_PLYR_PROFILE_NAME,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GET_EDIT_PLYR_PROFILE_NAME,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GET_EDIT_GAME_SETTINGS_NAME,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GET_ACTIVE_PLYR_PROFILE_COLOR,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_TEXTBOX_MAP_NAME,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_TEXTBOX_GAME_RULESET,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_TEXTBOX_TEAMS_NOTEAMS,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_TEXTBOX_SCORE_LIMIT,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_TEXTBOX_SCORE_LIMIT_TYPE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_BITMAP_FOR_MAP,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_BITMAP_FOR_RULESET,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_SET_TEXTBOX,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_EDIT_PROFILE_SET_RULE_TEXT,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SYSTEM_LINK_STATUS_CHECK,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_GAME_DIRECTIONS,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_TEAMS_NO_TEAMS_BITMAP_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_WARN_IF_DIFF_WILL_NUKE_SAVED_GAME,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_DIM_IF_NO_NET_CABLE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_PAUSE_GAME_SET_TEXTBOX_INVERTED,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_DIM_UNLESS_TWO_CONTROLLERS,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_CONTROLS_UPDATE_MENU,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_VIDEO_MENU_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GAMESPY_SCREEN_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_COMMON_BUTTON_BAR_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GAMEPAD_UPDATE_MENU,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SERVER_SETTINGS_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_AUDIO_MENU_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_PROF_VEHICLES_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_SOLO_MAP_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_MP_MAP_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GT_SELECT_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_GT_EDIT_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_LOAD_GAME_LIST_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_CHECKING_FOR_UPDATES,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_DIRECT_IP_CONNECT_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_NETWORK_SETTINGS_UPDATE,
        UI_GAME_DATA_INPUT_REFERENCE_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIGameDataInputReferenceFunction_to_string(UIGameDataInputReferenceFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIGameDataInputReferenceFunction_to_string_pretty(UIGameDataInputReferenceFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIGameDataInputReferenceFunction UIGameDataInputReferenceFunction_from_string(const char *value);

    enum UIEventType : TagEnum {
        UI_EVENT_TYPE_A_BUTTON,
        UI_EVENT_TYPE_B_BUTTON,
        UI_EVENT_TYPE_X_BUTTON,
        UI_EVENT_TYPE_Y_BUTTON,
        UI_EVENT_TYPE_BLACK_BUTTON,
        UI_EVENT_TYPE_WHITE_BUTTON,
        UI_EVENT_TYPE_LEFT_TRIGGER,
        UI_EVENT_TYPE_RIGHT_TRIGGER,
        UI_EVENT_TYPE_DPAD_UP,
        UI_EVENT_TYPE_DPAD_DOWN,
        UI_EVENT_TYPE_DPAD_LEFT,
        UI_EVENT_TYPE_DPAD_RIGHT,
        UI_EVENT_TYPE_START_BUTTON,
        UI_EVENT_TYPE_BACK_BUTTON,
        UI_EVENT_TYPE_LEFT_THUMB,
        UI_EVENT_TYPE_RIGHT_THUMB,
        UI_EVENT_TYPE_LEFT_ANALOG_STICK_UP,
        UI_EVENT_TYPE_LEFT_ANALOG_STICK_DOWN,
        UI_EVENT_TYPE_LEFT_ANALOG_STICK_LEFT,
        UI_EVENT_TYPE_LEFT_ANALOG_STICK_RIGHT,
        UI_EVENT_TYPE_LEFT_ANALOG_STICK_UP_1,
        UI_EVENT_TYPE_RIGHT_ANALOG_STICK_DOWN,
        UI_EVENT_TYPE_RIGHT_ANALOG_STICK_LEFT,
        UI_EVENT_TYPE_RIGHT_ANALOG_STICK_RIGHT,
        UI_EVENT_TYPE_CREATED,
        UI_EVENT_TYPE_DELETED,
        UI_EVENT_TYPE_GET_FOCUS,
        UI_EVENT_TYPE_LOSE_FOCUS,
        UI_EVENT_TYPE_LEFT_MOUSE,
        UI_EVENT_TYPE_MIDDLE_MOUSE,
        UI_EVENT_TYPE_RIGHT_MOUSE,
        UI_EVENT_TYPE_DOUBLE_CLICK,
        UI_EVENT_TYPE_CUSTOM_ACTIVATION,
        UI_EVENT_TYPE_POST_RENDER,
        UI_EVENT_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIEventType_to_string(UIEventType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIEventType_to_string_pretty(UIEventType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIEventType UIEventType_from_string(const char *value);

    enum UIEventHandlerReferenceFunction : TagEnum {
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NULL,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LIST_GOTO_NEXT_ITEM,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LIST_GOTO_PREVIOUS_ITEM,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_UNUSED,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_UNUSED1,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_INITIALIZE_SP_LEVEL_LIST_SOLO,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_INITIALIZE_SP_LEVEL_LIST_COOP,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DISPOSE_SP_LEVEL_LIST,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SOLO_LEVEL_SET_MAP,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SET_DIFFICULTY,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_START_NEW_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PAUSE_GAME_RESTART_AT_CHECKPOINT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PAUSE_GAME_RESTART_LEVEL,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PAUSE_GAME_RETURN_TO_MAIN_MENU,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CLEAR_MULTIPLAYER_PLAYER_JOINS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_JOIN_CONTROLLER_TO_MP_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_INITIALIZE_NET_GAME_SERVER_LIST,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_START_NETWORK_GAME_SERVER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DISPOSE_NET_GAME_SERVER_LIST,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SHUTDOWN_NETWORK_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_GAME_JOIN_FROM_SERVER_LIST,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SPLIT_SCREEN_GAME_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_COOP_GAME_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MAIN_MENU_INTIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_TYPE_MENU_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PICK_PLAY_STAGE_FOR_QUICK_START,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_LEVEL_LIST_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_LEVEL_LIST_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_LEVEL_SELECT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILES_LIST_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILES_LIST_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_FOR_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SWAP_PLAYER_TEAM,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_GAME_JOIN_PLAYER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLAYER_PROFILE_LIST_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLAYER_PROFILE_LIST_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_3WIDE_PLYR_PROF_SET_FOR_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_1WIDE_PLYR_PROF_SET_FOR_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_BEGIN_EDITING,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_END_EDITING,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_GAME_ENGINE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_CHANGE_NAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_CTF_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_KOTH_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_SLAYER_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_ODDBALL_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_RACING_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_PLAYER_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_ITEM_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SET_INDICATOR_OPTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_GAME_ENGINE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_NAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_CTF_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_KOTH_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_SLAYER_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_ODDBALL_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_RACING_RULES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_PLAYER_OPTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_ITEM_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_INIT_INDICATOR_OPTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROFILE_SAVE_CHANGES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_COLOR_PICKER_MENU_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_COLOR_PICKER_MENU_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_COLOR_PICKER_SELECT_COLOR,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLAYER_PROFILE_BEGIN_EDITING,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLAYER_PROFILE_END_EDITING,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLAYER_PROFILE_CHANGE_NAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLAYER_PROFILE_SAVE_CHANGES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLYR_PRF_INIT_CNTL_SETTINGS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLYR_PRF_INIT_ADV_CNTL_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLYR_PRF_SAVE_CNTL_SETTINGS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLYR_PRF_SAVE_ADV_CNTL_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_GAME_PLAYER_QUIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MAIN_MENU_SWITCH_TO_SOLO_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_REQUEST_DEL_PLAYER_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_REQUEST_DEL_PLAYLIST_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_FINAL_DEL_PLAYER_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_FINAL_DEL_PLAYLIST_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CANCEL_PROFILE_DELETE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CREATE_EDIT_PLAYLIST_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CREATE_EDIT_PLAYER_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_GAME_SPEED_START,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_GAME_DELAY_START,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_SERVER_ACCEPT_CONX,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_SERVER_DEFER_START,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_SERVER_ALLOW_START,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DISABLE_IF_NO_XDEMOS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_RUN_XDEMOS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SP_RESET_CONTROLLER_CHOICES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SP_SET_P1_CONTROLLER_CHOICE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SP_SET_P2_CONTROLLER_CHOICE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_ERROR_IF_NO_NETWORK_CONNECTION,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_START_SERVER_IF_NONE_ADVERTISED,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NET_GAME_UNJOIN_PLAYER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CLOSE_IF_NOT_EDITING_PROFILE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_EXIT_TO_XBOX_DASHBOARD,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NEW_CAMPAIGN_CHOSEN,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NEW_CAMPAIGN_DECISION,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_POP_HISTORY_STACK_ONCE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DIFFICULTY_MENU_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_BEGIN_MUSIC_FADE_OUT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NEW_GAME_IF_NO_PLYR_PROFILES,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_EXIT_GRACEFULLY_TO_XBOX_DASHBOARD,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PAUSE_GAME_INVERT_PITCH,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_START_NEW_COOP_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PAUSE_GAME_INVERT_SPINNER_GET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PAUSE_GAME_INVERT_SPINNER_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MAIN_MENU_QUIT_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_EMIT_ACCEPT_EVENT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_EMIT_BACK_EVENT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_EMIT_DPAD_LEFT_EVENT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_EMIT_DPAD_RIGHT_EVENT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_SPINNER_3WIDE_CLICK,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_SCREEN_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_VIDEO_SCREEN_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_BEGIN_BINDING,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_SCREEN_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_SCREEN_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_SELECT_HEADER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_SELECT_ITEM,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_SELECT_BUTTON,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_INIT_MOUSE_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_CHANGE_MOUSE_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_INIT_AUDIO_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_CHANGE_AUDIO_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_CHANGE_VIDEO_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_SCREEN_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_SCREEN_CHANGE_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_EMIT_X_EVENT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMEPAD_SCREEN_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMEPAD_SCREEN_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMEPAD_SCREEN_CHANGE_GAMEPADS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMEPAD_SCREEN_SELECT_ITEM,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_SCREEN_DEFAULTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_AUDIO_SCREEN_DEFAULTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_VIDEO_SCREEN_DEFAULTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_SCREEN_DEFAULTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PROFILE_SET_EDIT_BEGIN,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PROFILE_MANAGER_DELETE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PROFILE_MANAGER_SELECT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_DISMISS_ERROR,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SERVER_SETTINGS_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SS_EDIT_SERVER_NAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SS_EDIT_SERVER_PASSWORD,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SS_START_GAME,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_VIDEO_TEST_DIALOG_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_VIDEO_TEST_DIALOG_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_VIDEO_TEST_DIALOG_ACCEPT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_DISMISS_FILTERS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_UPDATE_FILTER_SETTINGS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_BACK_HANDLER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MOUSE_SPINNER_1WIDE_CLICK,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_BACK_HANDLER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_ADVANCED_LAUNCH,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CONTROLS_ADVANCED_OK,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PAUSE_MENU_OPEN,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_GAME_OPTIONS_OPEN,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_CHOOSE_TEAM,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROF_INIT_VEHICLE_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROF_SAVE_VEHICLE_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SINGLE_PREV_CL_ITEM_ACTIVATED,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROF_INIT_TEAMPLAY_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_PROF_SAVE_TEAMPLAY_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_GAME_OPTIONS_CHOOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_EMIT_CUSTOM_ACTIVATION_EVENT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_CANCEL_AUDIO_SET,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_INIT_NETWORK_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_PLR_PROF_SAVE_NETWORK_OPTIONS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CREDITS_POST_RENDER,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DIFFICULTY_ITEM_SELECT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CREDITS_INITIALIZE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CREDITS_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_GAMESPY_GET_PATCH,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_VIDEO_SCREEN_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CAMPAIGN_MENU_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CAMPAIGN_MENU_CONTINUE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LOAD_GAME_MENU_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LOAD_GAME_MENU_DISPOSE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LOAD_GAME_MENU_ACTIVATED,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_SOLO_MENU_SAVE_CHECKPOINT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_MP_TYPE_SET_MODE,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CHECKING_FOR_UPDATES_OK,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_CHECKING_FOR_UPDATES_DISMISS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DIRECT_IP_CONNECT_INIT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DIRECT_IP_CONNECT_GO,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_DIRECT_IP_EDIT_FIELD,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NETWORK_SETTINGS_EDIT_A_PORT,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_NETWORK_SETTINGS_DEFAULTS,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LOAD_GAME_MENU_DELETE_REQUEST,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_LOAD_GAME_MENU_DELETE_FINISH,
        UI_EVENT_HANDLER_REFERENCE_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIEventHandlerReferenceFunction_to_string(UIEventHandlerReferenceFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIEventHandlerReferenceFunction_to_string_pretty(UIEventHandlerReferenceFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIEventHandlerReferenceFunction UIEventHandlerReferenceFunction_from_string(const char *value);

    enum UIReplaceFunction : TagEnum {
        UI_REPLACE_FUNCTION_NULL,
        UI_REPLACE_FUNCTION_WIDGET_S_CONTROLLER,
        UI_REPLACE_FUNCTION_BUILD_NUMBER,
        UI_REPLACE_FUNCTION_PID,
        UI_REPLACE_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIReplaceFunction_to_string(UIReplaceFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIReplaceFunction_to_string_pretty(UIReplaceFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIReplaceFunction UIReplaceFunction_from_string(const char *value);

    enum UIWidgetType : TagEnum {
        UI_WIDGET_TYPE_CONTAINER,
        UI_WIDGET_TYPE_TEXT_BOX,
        UI_WIDGET_TYPE_SPINNER_LIST,
        UI_WIDGET_TYPE_COLUMN_LIST,
        UI_WIDGET_TYPE_GAME_MODEL_NOT_IMPLEMENTED,
        UI_WIDGET_TYPE_MOVIE_NOT_IMPLEMENTED,
        UI_WIDGET_TYPE_CUSTOM_NOT_IMPLEMENTED,
        UI_WIDGET_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIWidgetType_to_string(UIWidgetType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIWidgetType_to_string_pretty(UIWidgetType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIWidgetType UIWidgetType_from_string(const char *value);

    enum UIControllerIndex : TagEnum {
        UI_CONTROLLER_INDEX_PLAYER_1,
        UI_CONTROLLER_INDEX_PLAYER_2,
        UI_CONTROLLER_INDEX_PLAYER_3,
        UI_CONTROLLER_INDEX_PLAYER_4,
        UI_CONTROLLER_INDEX_ANY_PLAYER,
        UI_CONTROLLER_INDEX_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIControllerIndex_to_string(UIControllerIndex value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIControllerIndex_to_string_pretty(UIControllerIndex value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIControllerIndex UIControllerIndex_from_string(const char *value);

    enum UIJustification : TagEnum {
        UI_JUSTIFICATION_LEFT_JUSTIFY,
        UI_JUSTIFICATION_RIGHT_JUSTIFY,
        UI_JUSTIFICATION_CENTER_JUSTIFY,
        UI_JUSTIFICATION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIJustification_to_string(UIJustification value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIJustification_to_string_pretty(UIJustification value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIJustification UIJustification_from_string(const char *value);

    enum UnitFunctionIn : TagEnum {
        UNIT_FUNCTION_IN_NONE,
        UNIT_FUNCTION_IN_DRIVER_SEAT_POWER,
        UNIT_FUNCTION_IN_GUNNER_SEAT_POWER,
        UNIT_FUNCTION_IN_AIMING_CHANGE,
        UNIT_FUNCTION_IN_MOUTH_APERTURE,
        UNIT_FUNCTION_IN_INTEGRATED_LIGHT_POWER,
        UNIT_FUNCTION_IN_CAN_BLINK,
        UNIT_FUNCTION_IN_SHIELD_SAPPING,
        UNIT_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitFunctionIn_to_string(UnitFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitFunctionIn_to_string_pretty(UnitFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitFunctionIn UnitFunctionIn_from_string(const char *value);

    enum UnitDefaultTeam : TagEnum {
        UNIT_DEFAULT_TEAM_NONE,
        UNIT_DEFAULT_TEAM_PLAYER,
        UNIT_DEFAULT_TEAM_HUMAN,
        UNIT_DEFAULT_TEAM_COVENANT,
        UNIT_DEFAULT_TEAM_FLOOD,
        UNIT_DEFAULT_TEAM_SENTINEL,
        UNIT_DEFAULT_TEAM_UNUSED6,
        UNIT_DEFAULT_TEAM_UNUSED7,
        UNIT_DEFAULT_TEAM_UNUSED8,
        UNIT_DEFAULT_TEAM_UNUSED9,
        UNIT_DEFAULT_TEAM_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitDefaultTeam_to_string(UnitDefaultTeam value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitDefaultTeam_to_string_pretty(UnitDefaultTeam value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitDefaultTeam UnitDefaultTeam_from_string(const char *value);

    enum UnitMotionSensorBlipSize : TagEnum {
        UNIT_MOTION_SENSOR_BLIP_SIZE_MEDIUM,
        UNIT_MOTION_SENSOR_BLIP_SIZE_SMALL,
        UNIT_MOTION_SENSOR_BLIP_SIZE_LARGE,
        UNIT_MOTION_SENSOR_BLIP_SIZE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitMotionSensorBlipSize_to_string(UnitMotionSensorBlipSize value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitMotionSensorBlipSize_to_string_pretty(UnitMotionSensorBlipSize value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitMotionSensorBlipSize UnitMotionSensorBlipSize_from_string(const char *value);

    enum MetagameType : TagEnum {
        METAGAME_TYPE_BRUTE,
        METAGAME_TYPE_GRUNT,
        METAGAME_TYPE_JACKAL,
        METAGAME_TYPE_SKIRMISHER,
        METAGAME_TYPE_MARINE,
        METAGAME_TYPE_SPARTAN,
        METAGAME_TYPE_BUGGER,
        METAGAME_TYPE_HUNTER,
        METAGAME_TYPE_FLOOD_INFECTION,
        METAGAME_TYPE_FLOOD_CARRIER,
        METAGAME_TYPE_FLOOD_COMBAT,
        METAGAME_TYPE_FLOOD_PURE,
        METAGAME_TYPE_SENTINEL,
        METAGAME_TYPE_ELITE,
        METAGAME_TYPE_ENGINEER,
        METAGAME_TYPE_MULE,
        METAGAME_TYPE_TURRET,
        METAGAME_TYPE_MONGOOSE,
        METAGAME_TYPE_WARTHOG,
        METAGAME_TYPE_SCORPION,
        METAGAME_TYPE_HORNET,
        METAGAME_TYPE_PELICAN,
        METAGAME_TYPE_REVENANT,
        METAGAME_TYPE_SERAPH,
        METAGAME_TYPE_SHADE,
        METAGAME_TYPE_WATCHTOWER,
        METAGAME_TYPE_GHOST,
        METAGAME_TYPE_CHOPPER,
        METAGAME_TYPE_MAULER,
        METAGAME_TYPE_WRAITH,
        METAGAME_TYPE_BANSHEE,
        METAGAME_TYPE_PHANTOM,
        METAGAME_TYPE_SCARAB,
        METAGAME_TYPE_GUNTOWER,
        METAGAME_TYPE_TUNING_FORK,
        METAGAME_TYPE_BROADSWORD,
        METAGAME_TYPE_MAMMOTH,
        METAGAME_TYPE_LICH,
        METAGAME_TYPE_MANTIS,
        METAGAME_TYPE_WASP,
        METAGAME_TYPE_PHAETON,
        METAGAME_TYPE_BISHOP,
        METAGAME_TYPE_KNIGHT,
        METAGAME_TYPE_PAWN,
        METAGAME_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MetagameType_to_string(MetagameType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MetagameType_to_string_pretty(MetagameType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MetagameType MetagameType_from_string(const char *value);

    enum MetagameClass : TagEnum {
        METAGAME_CLASS_INFANTRY,
        METAGAME_CLASS_LEADER,
        METAGAME_CLASS_HERO,
        METAGAME_CLASS_SPECIALIST,
        METAGAME_CLASS_LIGHT_VEHICLE,
        METAGAME_CLASS_HEAVY_VEHICLE,
        METAGAME_CLASS_GIANT_VEHICLE,
        METAGAME_CLASS_STANDARD_VEHICLE,
        METAGAME_CLASS_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MetagameClass_to_string(MetagameClass value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MetagameClass_to_string_pretty(MetagameClass value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MetagameClass MetagameClass_from_string(const char *value);

    enum UnitHUDInterfacePanelType : TagEnum {
        UNIT_HUD_INTERFACE_PANEL_TYPE_INTEGRATED_LIGHT,
        UNIT_HUD_INTERFACE_PANEL_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitHUDInterfacePanelType_to_string(UnitHUDInterfacePanelType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitHUDInterfacePanelType_to_string_pretty(UnitHUDInterfacePanelType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitHUDInterfacePanelType UnitHUDInterfacePanelType_from_string(const char *value);

    enum VehicleType : TagEnum {
        VEHICLE_TYPE_HUMAN_TANK,
        VEHICLE_TYPE_HUMAN_JEEP,
        VEHICLE_TYPE_HUMAN_BOAT,
        VEHICLE_TYPE_HUMAN_PLANE,
        VEHICLE_TYPE_ALIEN_SCOUT,
        VEHICLE_TYPE_ALIEN_FIGHTER,
        VEHICLE_TYPE_TURRET,
        VEHICLE_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *VehicleType_to_string(VehicleType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *VehicleType_to_string_pretty(VehicleType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    VehicleType VehicleType_from_string(const char *value);

    enum VehicleFunctionIn : TagEnum {
        VEHICLE_FUNCTION_IN_NONE,
        VEHICLE_FUNCTION_IN_SPEED_ABSOLUTE,
        VEHICLE_FUNCTION_IN_SPEED_FORWARD,
        VEHICLE_FUNCTION_IN_SPEED_BACKWARD,
        VEHICLE_FUNCTION_IN_SLIDE_ABSOLUTE,
        VEHICLE_FUNCTION_IN_SLIDE_LEFT,
        VEHICLE_FUNCTION_IN_SLIDE_RIGHT,
        VEHICLE_FUNCTION_IN_SPEED_SLIDE_MAXIMUM,
        VEHICLE_FUNCTION_IN_TURN_ABSOLUTE,
        VEHICLE_FUNCTION_IN_TURN_LEFT,
        VEHICLE_FUNCTION_IN_TURN_RIGHT,
        VEHICLE_FUNCTION_IN_CROUCH,
        VEHICLE_FUNCTION_IN_JUMP,
        VEHICLE_FUNCTION_IN_WALK,
        VEHICLE_FUNCTION_IN_VELOCITY_AIR,
        VEHICLE_FUNCTION_IN_VELOCITY_WATER,
        VEHICLE_FUNCTION_IN_VELOCITY_GROUND,
        VEHICLE_FUNCTION_IN_VELOCITY_FORWARD,
        VEHICLE_FUNCTION_IN_VELOCITY_LEFT,
        VEHICLE_FUNCTION_IN_VELOCITY_UP,
        VEHICLE_FUNCTION_IN_LEFT_TREAD_POSITION,
        VEHICLE_FUNCTION_IN_RIGHT_TREAD_POSITION,
        VEHICLE_FUNCTION_IN_LEFT_TREAD_VELOCITY,
        VEHICLE_FUNCTION_IN_RIGHT_TREAD_VELOCITY,
        VEHICLE_FUNCTION_IN_FRONT_LEFT_TIRE_POSITION,
        VEHICLE_FUNCTION_IN_FRONT_RIGHT_TIRE_POSITION,
        VEHICLE_FUNCTION_IN_BACK_LEFT_TIRE_POSITION,
        VEHICLE_FUNCTION_IN_BACK_RIGHT_TIRE_POSITION,
        VEHICLE_FUNCTION_IN_FRONT_LEFT_TIRE_VELOCITY,
        VEHICLE_FUNCTION_IN_FRONT_RIGHT_TIRE_VELOCITY,
        VEHICLE_FUNCTION_IN_BACK_LEFT_TIRE_VELOCITY,
        VEHICLE_FUNCTION_IN_BACK_RIGHT_TIRE_VELOCITY,
        VEHICLE_FUNCTION_IN_WINGTIP_CONTRAIL,
        VEHICLE_FUNCTION_IN_HOVER,
        VEHICLE_FUNCTION_IN_THRUST,
        VEHICLE_FUNCTION_IN_ENGINE_HACK,
        VEHICLE_FUNCTION_IN_WINGTIP_CONTRAIL_NEW,
        VEHICLE_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *VehicleFunctionIn_to_string(VehicleFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *VehicleFunctionIn_to_string_pretty(VehicleFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    VehicleFunctionIn VehicleFunctionIn_from_string(const char *value);

    enum VirtualKeyboardKeyboardKey : TagEnum {
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_1,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_2,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_3,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_4,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_5,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_6,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_7,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_8,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_9,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_0,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_A,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_B,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_C,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_D,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_E,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_F,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_G,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_H,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_I,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_J,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_K,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_L,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_M,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_N,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_O,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_P,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_Q,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_R,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_S,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_T,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_U,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_V,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_W,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_X,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_Y,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_Z,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_DONE,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_SHIFT,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_CAPS_LOCK,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_SYMBOLS,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_BACKSPACE,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_LEFT,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_RIGHT,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_SPACE,
        VIRTUAL_KEYBOARD_KEYBOARD_KEY_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *VirtualKeyboardKeyboardKey_to_string(VirtualKeyboardKeyboardKey value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *VirtualKeyboardKeyboardKey_to_string_pretty(VirtualKeyboardKeyboardKey value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    VirtualKeyboardKeyboardKey VirtualKeyboardKeyboardKey_from_string(const char *value);

    enum WeaponSecondaryTriggerMode : TagEnum {
        WEAPON_SECONDARY_TRIGGER_MODE_NORMAL,
        WEAPON_SECONDARY_TRIGGER_MODE_SLAVED_TO_PRIMARY,
        WEAPON_SECONDARY_TRIGGER_MODE_INHIBITS_PRIMARY,
        WEAPON_SECONDARY_TRIGGER_MODE_LOADS_ALTERATE_AMMUNITION,
        WEAPON_SECONDARY_TRIGGER_MODE_LOADS_MULTIPLE_PRIMARY_AMMUNITION,
        WEAPON_SECONDARY_TRIGGER_MODE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponSecondaryTriggerMode_to_string(WeaponSecondaryTriggerMode value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponSecondaryTriggerMode_to_string_pretty(WeaponSecondaryTriggerMode value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponSecondaryTriggerMode WeaponSecondaryTriggerMode_from_string(const char *value);

    enum WeaponFunctionIn : TagEnum {
        WEAPON_FUNCTION_IN_NONE,
        WEAPON_FUNCTION_IN_HEAT,
        WEAPON_FUNCTION_IN_PRIMARY_AMMUNITION,
        WEAPON_FUNCTION_IN_SECONDARY_AMMUNITION,
        WEAPON_FUNCTION_IN_PRIMARY_RATE_OF_FIRE,
        WEAPON_FUNCTION_IN_SECONDARY_RATE_OF_FIRE,
        WEAPON_FUNCTION_IN_READY,
        WEAPON_FUNCTION_IN_PRIMARY_EJECTION_PORT,
        WEAPON_FUNCTION_IN_SECONDARY_EJECTION_PORT,
        WEAPON_FUNCTION_IN_OVERHEATED,
        WEAPON_FUNCTION_IN_PRIMARY_CHARGED,
        WEAPON_FUNCTION_IN_SECONDARY_CHARGED,
        WEAPON_FUNCTION_IN_ILLUMINATION,
        WEAPON_FUNCTION_IN_AGE,
        WEAPON_FUNCTION_IN_INTEGRATED_LIGHT,
        WEAPON_FUNCTION_IN_PRIMARY_FIRING,
        WEAPON_FUNCTION_IN_SECONDARY_FIRING,
        WEAPON_FUNCTION_IN_PRIMARY_FIRING_ON,
        WEAPON_FUNCTION_IN_SECONDARY_FIRING_ON,
        WEAPON_FUNCTION_IN_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponFunctionIn_to_string(WeaponFunctionIn value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponFunctionIn_to_string_pretty(WeaponFunctionIn value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponFunctionIn WeaponFunctionIn_from_string(const char *value);

    enum WeaponMovementPenalized : TagEnum {
        WEAPON_MOVEMENT_PENALIZED_ALWAYS,
        WEAPON_MOVEMENT_PENALIZED_WHEN_ZOOMED,
        WEAPON_MOVEMENT_PENALIZED_WHEN_ZOOMED_OR_RELOADING,
        WEAPON_MOVEMENT_PENALIZED_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponMovementPenalized_to_string(WeaponMovementPenalized value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponMovementPenalized_to_string_pretty(WeaponMovementPenalized value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponMovementPenalized WeaponMovementPenalized_from_string(const char *value);

    enum WeaponType : TagEnum {
        WEAPON_TYPE_UNDEFINED,
        WEAPON_TYPE_SHOTGUN,
        WEAPON_TYPE_NEEDLER,
        WEAPON_TYPE_PLASMA_PISTOL,
        WEAPON_TYPE_PLASMA_RIFLE,
        WEAPON_TYPE_ROCKET_LAUNCHER,
        WEAPON_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponType_to_string(WeaponType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponType_to_string_pretty(WeaponType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponType WeaponType_from_string(const char *value);

    enum WeaponPredictionType : TagEnum {
        WEAPON_PREDICTION_TYPE_NONE,
        WEAPON_PREDICTION_TYPE_CONTINUOUS,
        WEAPON_PREDICTION_TYPE_INSTANT,
        WEAPON_PREDICTION_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponPredictionType_to_string(WeaponPredictionType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponPredictionType_to_string_pretty(WeaponPredictionType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponPredictionType WeaponPredictionType_from_string(const char *value);

    enum WeaponOverchargedAction : TagEnum {
        WEAPON_OVERCHARGED_ACTION_NONE,
        WEAPON_OVERCHARGED_ACTION_EXPLODE,
        WEAPON_OVERCHARGED_ACTION_DISCHARGE,
        WEAPON_OVERCHARGED_ACTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponOverchargedAction_to_string(WeaponOverchargedAction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponOverchargedAction_to_string_pretty(WeaponOverchargedAction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponOverchargedAction WeaponOverchargedAction_from_string(const char *value);

    enum WeaponDistributionFunction : TagEnum {
        WEAPON_DISTRIBUTION_FUNCTION_POINT,
        WEAPON_DISTRIBUTION_FUNCTION_HORIZONTAL_FAN,
        WEAPON_DISTRIBUTION_FUNCTION_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponDistributionFunction_to_string(WeaponDistributionFunction value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponDistributionFunction_to_string_pretty(WeaponDistributionFunction value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponDistributionFunction WeaponDistributionFunction_from_string(const char *value);

    enum WeaponHUDInterfaceStateAttachedTo : TagEnum {
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_TOTAL_AMMO,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_LOADED_AMMO,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_HEAT,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_AGE,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_SECONDARY_WEAPON_TOTAL_AMMO,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_SECONDARY_WEAPON_LOADED_AMMO,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_DISTANCE_TO_TARGET,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_ELEVATION_TO_TARGET,
        WEAPON_HUD_INTERFACE_STATE_ATTACHED_TO_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceStateAttachedTo_to_string(WeaponHUDInterfaceStateAttachedTo value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceStateAttachedTo_to_string_pretty(WeaponHUDInterfaceStateAttachedTo value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceStateAttachedTo WeaponHUDInterfaceStateAttachedTo_from_string(const char *value);

    enum WeaponHUDInterfaceViewType : TagEnum {
        WEAPON_HUD_INTERFACE_VIEW_TYPE_ANY,
        WEAPON_HUD_INTERFACE_VIEW_TYPE_FULLSCREEN,
        WEAPON_HUD_INTERFACE_VIEW_TYPE_SPLITSCREEN,
        WEAPON_HUD_INTERFACE_VIEW_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceViewType_to_string(WeaponHUDInterfaceViewType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceViewType_to_string_pretty(WeaponHUDInterfaceViewType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceViewType WeaponHUDInterfaceViewType_from_string(const char *value);

    enum WeaponHUDInterfaceCrosshairType : TagEnum {
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_AIM,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_ZOOM_OVERLAY,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_CHARGE,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_SHOULD_RELOAD,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_HEAT,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_TOTAL_AMMO,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_BATTERY,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_RELOAD_OVERHEAT,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_WHEN_FIRING_AND_NO_AMMO,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_WHEN_THROWING_AND_NO_GRENADE,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_LOW_AMMO_AND_NONE_LEFT_TO_RELOAD,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_SHOULD_RELOAD_SECONDARY_TRIGGER,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_SECONDARY_TOTAL_AMMO,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_SECONDARY_RELOAD,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_WHEN_FIRING_SECONDARY_TRIGGER_WITH_NO_AMMO,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_LOW_SECONDARY_AMMO_AND_NONE_LEFT_TO_RELOAD,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_PRIMARY_TRIGGER_READY,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_SECONDARY_TRIGGER_READY,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLASH_WHEN_FIRING_WITH_DEPLETED_BATTERY,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceCrosshairType_to_string(WeaponHUDInterfaceCrosshairType value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceCrosshairType_to_string_pretty(WeaponHUDInterfaceCrosshairType value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceCrosshairType WeaponHUDInterfaceCrosshairType_from_string(const char *value);

    enum WeatherParticleSystemRenderDirectionSource : TagEnum {
        WEATHER_PARTICLE_SYSTEM_RENDER_DIRECTION_SOURCE_FROM_VELOCITY,
        WEATHER_PARTICLE_SYSTEM_RENDER_DIRECTION_SOURCE_FROM_ACCELERATION,
        WEATHER_PARTICLE_SYSTEM_RENDER_DIRECTION_SOURCE_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeatherParticleSystemRenderDirectionSource_to_string(WeatherParticleSystemRenderDirectionSource value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeatherParticleSystemRenderDirectionSource_to_string_pretty(WeatherParticleSystemRenderDirectionSource value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeatherParticleSystemRenderDirectionSource WeatherParticleSystemRenderDirectionSource_from_string(const char *value);

    using ActorFlags = std::uint32_t;
    enum ActorFlagsFlag : std::uint32_t {
        ACTOR_FLAGS_FLAG_CAN_SEE_IN_DARKNESS = static_cast<std::uint32_t>(1) << 0,
        ACTOR_FLAGS_FLAG_SNEAK_UNCOVERING_TARGET = static_cast<std::uint32_t>(1) << 1,
        ACTOR_FLAGS_FLAG_SNEAK_UNCOVERING_PURSUIT_POSITION = static_cast<std::uint32_t>(1) << 2,
        ACTOR_FLAGS_FLAG_UNUSED = static_cast<std::uint32_t>(1) << 3,
        ACTOR_FLAGS_FLAG_SHOOT_AT_TARGET_S_LAST_LOCATION = static_cast<std::uint32_t>(1) << 4,
        ACTOR_FLAGS_FLAG_TRY_TO_STAY_STILL_WHEN_CROUCHED = static_cast<std::uint32_t>(1) << 5,
        ACTOR_FLAGS_FLAG_CROUCH_WHEN_NOT_IN_COMBAT = static_cast<std::uint32_t>(1) << 6,
        ACTOR_FLAGS_FLAG_CROUCH_WHEN_GUARDING = static_cast<std::uint32_t>(1) << 7,
        ACTOR_FLAGS_FLAG_UNUSED_1 = static_cast<std::uint32_t>(1) << 8,
        ACTOR_FLAGS_FLAG_MUST_CROUCH_TO_SHOOT = static_cast<std::uint32_t>(1) << 9,
        ACTOR_FLAGS_FLAG_PANIC_WHEN_SURPRISED = static_cast<std::uint32_t>(1) << 10,
        ACTOR_FLAGS_FLAG_ALWAYS_CHARGE_AT_ENEMIES = static_cast<std::uint32_t>(1) << 11,
        ACTOR_FLAGS_FLAG_GETS_IN_VEHICLES_WITH_PLAYER = static_cast<std::uint32_t>(1) << 12,
        ACTOR_FLAGS_FLAG_START_FIRING_BEFORE_ALIGNED = static_cast<std::uint32_t>(1) << 13,
        ACTOR_FLAGS_FLAG_STANDING_MUST_MOVE_FORWARD = static_cast<std::uint32_t>(1) << 14,
        ACTOR_FLAGS_FLAG_CROUCHING_MUST_MOVE_FORWARD = static_cast<std::uint32_t>(1) << 15,
        ACTOR_FLAGS_FLAG_DEFENSIVE_CROUCH_WHILE_CHARGING = static_cast<std::uint32_t>(1) << 16,
        ACTOR_FLAGS_FLAG_USE_STALKING_BEHAVIOR = static_cast<std::uint32_t>(1) << 17,
        ACTOR_FLAGS_FLAG_STALKING_FREEZE_IF_EXPOSED = static_cast<std::uint32_t>(1) << 18,
        ACTOR_FLAGS_FLAG_ALWAYS_BERSERK_IN_ATTACKING_MODE = static_cast<std::uint32_t>(1) << 19,
        ACTOR_FLAGS_FLAG_BERSERKING_USES_PANICKED_MOVEMENT = static_cast<std::uint32_t>(1) << 20,
        ACTOR_FLAGS_FLAG_FLYING = static_cast<std::uint32_t>(1) << 21,
        ACTOR_FLAGS_FLAG_PANICKED_BY_UNOPPOSABLE_ENEMY = static_cast<std::uint32_t>(1) << 22,
        ACTOR_FLAGS_FLAG_CROUCH_WHEN_HIDING_FROM_UNOPPOSABLE = static_cast<std::uint32_t>(1) << 23,
        ACTOR_FLAGS_FLAG_ALWAYS_CHARGE_IN_ATTACKING_MODE = static_cast<std::uint32_t>(1) << 24,
        ACTOR_FLAGS_FLAG_DIVE_OFF_LEDGES = static_cast<std::uint32_t>(1) << 25,
        ACTOR_FLAGS_FLAG_SWARM = static_cast<std::uint32_t>(1) << 26,
        ACTOR_FLAGS_FLAG_SUICIDAL_MELEE_ATTACK = static_cast<std::uint32_t>(1) << 27,
        ACTOR_FLAGS_FLAG_CANNOT_MOVE_WHILE_CROUCHING = static_cast<std::uint32_t>(1) << 28,
        ACTOR_FLAGS_FLAG_FIXED_CROUCH_FACING = static_cast<std::uint32_t>(1) << 29,
        ACTOR_FLAGS_FLAG_CROUCH_WHEN_IN_LINE_OF_FIRE = static_cast<std::uint32_t>(1) << 30,
        ACTOR_FLAGS_FLAG_AVOID_FRIENDS_LINE_OF_FIRE = static_cast<std::uint32_t>(1) << 31,
        ACTOR_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorFlagsFlag_to_string(ActorFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorFlagsFlag_to_string_pretty(ActorFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorFlagsFlag ActorFlagsFlag_from_string(const char *value);

    using ActorMoreFlags = std::uint32_t;
    enum ActorMoreFlagsFlag : std::uint32_t {
        ACTOR_MORE_FLAGS_FLAG_AVOID_ALL_ENEMY_ATTACK_VECTORS = static_cast<std::uint32_t>(1) << 0,
        ACTOR_MORE_FLAGS_FLAG_MUST_STAND_TO_FIRE = static_cast<std::uint32_t>(1) << 1,
        ACTOR_MORE_FLAGS_FLAG_MUST_STOP_TO_FIRE = static_cast<std::uint32_t>(1) << 2,
        ACTOR_MORE_FLAGS_FLAG_DISALLOW_VEHICLE_COMBAT = static_cast<std::uint32_t>(1) << 3,
        ACTOR_MORE_FLAGS_FLAG_PATHFINDING_IGNORES_DANGER = static_cast<std::uint32_t>(1) << 4,
        ACTOR_MORE_FLAGS_FLAG_PANIC_IN_GROUPS = static_cast<std::uint32_t>(1) << 5,
        ACTOR_MORE_FLAGS_FLAG_NO_CORPSE_SHOOTING = static_cast<std::uint32_t>(1) << 6,
        ACTOR_MORE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorMoreFlagsFlag_to_string(ActorMoreFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorMoreFlagsFlag_to_string_pretty(ActorMoreFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorMoreFlagsFlag ActorMoreFlagsFlag_from_string(const char *value);

    using ActorVariantFlags = std::uint32_t;
    enum ActorVariantFlagsFlag : std::uint32_t {
        ACTOR_VARIANT_FLAGS_FLAG_CAN_SHOOT_WHILE_FLYING = static_cast<std::uint32_t>(1) << 0,
        ACTOR_VARIANT_FLAGS_FLAG_INTERPOLATE_COLOR_IN_HSV = static_cast<std::uint32_t>(1) << 1,
        ACTOR_VARIANT_FLAGS_FLAG_HAS_UNLIMITED_GRENADES = static_cast<std::uint32_t>(1) << 2,
        ACTOR_VARIANT_FLAGS_FLAG_MOVEMENT_SWITCHING_TRY_TO_STAY_WITH_FRIENDS = static_cast<std::uint32_t>(1) << 3,
        ACTOR_VARIANT_FLAGS_FLAG_ACTIVE_CAMOUFLAGE = static_cast<std::uint32_t>(1) << 4,
        ACTOR_VARIANT_FLAGS_FLAG_SUPER_ACTIVE_CAMOUFLAGE = static_cast<std::uint32_t>(1) << 5,
        ACTOR_VARIANT_FLAGS_FLAG_CANNOT_USE_RANGED_WEAPONS = static_cast<std::uint32_t>(1) << 6,
        ACTOR_VARIANT_FLAGS_FLAG_PREFER_PASSENGER_SEAT = static_cast<std::uint32_t>(1) << 7,
        ACTOR_VARIANT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ActorVariantFlagsFlag_to_string(ActorVariantFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ActorVariantFlagsFlag_to_string_pretty(ActorVariantFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ActorVariantFlagsFlag ActorVariantFlagsFlag_from_string(const char *value);

    using BipedFlags = std::uint32_t;
    enum BipedFlagsFlag : std::uint32_t {
        BIPED_FLAGS_FLAG_TURNS_WITHOUT_ANIMATING = static_cast<std::uint32_t>(1) << 0,
        BIPED_FLAGS_FLAG_USES_PLAYER_PHYSICS = static_cast<std::uint32_t>(1) << 1,
        BIPED_FLAGS_FLAG_FLYING = static_cast<std::uint32_t>(1) << 2,
        BIPED_FLAGS_FLAG_PHYSICS_PILL_CENTERED_AT_ORIGIN = static_cast<std::uint32_t>(1) << 3,
        BIPED_FLAGS_FLAG_SPHERICAL = static_cast<std::uint32_t>(1) << 4,
        BIPED_FLAGS_FLAG_PASSES_THROUGH_OTHER_BIPEDS = static_cast<std::uint32_t>(1) << 5,
        BIPED_FLAGS_FLAG_CAN_CLIMB_ANY_SURFACE = static_cast<std::uint32_t>(1) << 6,
        BIPED_FLAGS_FLAG_IMMUNE_TO_FALLING_DAMAGE = static_cast<std::uint32_t>(1) << 7,
        BIPED_FLAGS_FLAG_ROTATE_WHILE_AIRBORNE = static_cast<std::uint32_t>(1) << 8,
        BIPED_FLAGS_FLAG_USES_LIMP_BODY_PHYSICS = static_cast<std::uint32_t>(1) << 9,
        BIPED_FLAGS_FLAG_HAS_NO_DYING_AIRBORNE = static_cast<std::uint32_t>(1) << 10,
        BIPED_FLAGS_FLAG_RANDOM_SPEED_INCREASE = static_cast<std::uint32_t>(1) << 11,
        BIPED_FLAGS_FLAG_UNIT_USES_OLD_NTSC_PLAYER_PHYSICS = static_cast<std::uint32_t>(1) << 12,
        BIPED_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BipedFlagsFlag_to_string(BipedFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BipedFlagsFlag_to_string_pretty(BipedFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BipedFlagsFlag BipedFlagsFlag_from_string(const char *value);

    using IsUnusedFlag = std::uint32_t;
    enum IsUnusedFlagFlag : std::uint32_t {
        IS_UNUSED_FLAG_FLAG_UNUSED = static_cast<std::uint32_t>(1) << 0,
        IS_UNUSED_FLAG_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *IsUnusedFlagFlag_to_string(IsUnusedFlagFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *IsUnusedFlagFlag_to_string_pretty(IsUnusedFlagFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    IsUnusedFlagFlag IsUnusedFlagFlag_from_string(const char *value);

    using IsUnfilteredFlag = std::uint16_t;
    enum IsUnfilteredFlagFlag : std::uint16_t {
        IS_UNFILTERED_FLAG_FLAG_UNFILTERED = static_cast<std::uint16_t>(1) << 0,
        IS_UNFILTERED_FLAG_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *IsUnfilteredFlagFlag_to_string(IsUnfilteredFlagFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *IsUnfilteredFlagFlag_to_string_pretty(IsUnfilteredFlagFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    IsUnfilteredFlagFlag IsUnfilteredFlagFlag_from_string(const char *value);

    using ColorInterpolationFlags = std::uint32_t;
    enum ColorInterpolationFlagsFlag : std::uint32_t {
        COLOR_INTERPOLATION_FLAGS_FLAG_BLEND_IN_HSV = static_cast<std::uint32_t>(1) << 0,
        COLOR_INTERPOLATION_FLAGS_FLAG_MORE_COLORS = static_cast<std::uint32_t>(1) << 1,
        COLOR_INTERPOLATION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ColorInterpolationFlagsFlag_to_string(ColorInterpolationFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ColorInterpolationFlagsFlag_to_string_pretty(ColorInterpolationFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ColorInterpolationFlagsFlag ColorInterpolationFlagsFlag_from_string(const char *value);

    using BitmapDataFlags = std::uint16_t;
    enum BitmapDataFlagsFlag : std::uint16_t {
        BITMAP_DATA_FLAGS_FLAG_POWER_OF_TWO_DIMENSIONS = static_cast<std::uint16_t>(1) << 0,
        BITMAP_DATA_FLAGS_FLAG_COMPRESSED = static_cast<std::uint16_t>(1) << 1,
        BITMAP_DATA_FLAGS_FLAG_PALETTIZED = static_cast<std::uint16_t>(1) << 2,
        BITMAP_DATA_FLAGS_FLAG_SWIZZLED = static_cast<std::uint16_t>(1) << 3,
        BITMAP_DATA_FLAGS_FLAG_LINEAR = static_cast<std::uint16_t>(1) << 4,
        BITMAP_DATA_FLAGS_FLAG_V16U16 = static_cast<std::uint16_t>(1) << 5,
        BITMAP_DATA_FLAGS_FLAG_UNUSED = static_cast<std::uint16_t>(1) << 6,
        BITMAP_DATA_FLAGS_FLAG_MAKE_IT_ACTUALLY_WORK = static_cast<std::uint16_t>(1) << 7,
        BITMAP_DATA_FLAGS_FLAG_EXTERNAL = static_cast<std::uint16_t>(1) << 8,
        BITMAP_DATA_FLAGS_FLAG_ENVIRONMENT = static_cast<std::uint16_t>(1) << 9,
        BITMAP_DATA_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapDataFlagsFlag_to_string(BitmapDataFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapDataFlagsFlag_to_string_pretty(BitmapDataFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapDataFlagsFlag BitmapDataFlagsFlag_from_string(const char *value);

    using BitmapFlags = std::uint16_t;
    enum BitmapFlagsFlag : std::uint16_t {
        BITMAP_FLAGS_FLAG_ENABLE_DIFFUSION_DITHERING = static_cast<std::uint16_t>(1) << 0,
        BITMAP_FLAGS_FLAG_DISABLE_HEIGHT_MAP_COMPRESSION = static_cast<std::uint16_t>(1) << 1,
        BITMAP_FLAGS_FLAG_UNIFORM_SPRITE_SEQUENCES = static_cast<std::uint16_t>(1) << 2,
        BITMAP_FLAGS_FLAG_FILTHY_SPRITE_BUG_FIX = static_cast<std::uint16_t>(1) << 3,
        BITMAP_FLAGS_FLAG_HALF_HUD_SCALE = static_cast<std::uint16_t>(1) << 4,
        BITMAP_FLAGS_FLAG_INVERT_DETAIL_FADE = static_cast<std::uint16_t>(1) << 5,
        BITMAP_FLAGS_FLAG_USE_AVERAGE_COLOR_FOR_DETAIL_FADE = static_cast<std::uint16_t>(1) << 6,
        BITMAP_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BitmapFlagsFlag_to_string(BitmapFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BitmapFlagsFlag_to_string_pretty(BitmapFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BitmapFlagsFlag BitmapFlagsFlag_from_string(const char *value);

    using ContrailPointStateScaleFlags = std::uint32_t;
    enum ContrailPointStateScaleFlagsFlag : std::uint32_t {
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_DURATION = static_cast<std::uint32_t>(1) << 0,
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_DURATION_DELTA = static_cast<std::uint32_t>(1) << 1,
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_TRANSITION_DURATION = static_cast<std::uint32_t>(1) << 2,
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_TRANSITION_DURATION_DELTA = static_cast<std::uint32_t>(1) << 3,
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_WIDTH = static_cast<std::uint32_t>(1) << 4,
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_COLOR = static_cast<std::uint32_t>(1) << 5,
        CONTRAIL_POINT_STATE_SCALE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ContrailPointStateScaleFlagsFlag_to_string(ContrailPointStateScaleFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ContrailPointStateScaleFlagsFlag_to_string_pretty(ContrailPointStateScaleFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ContrailPointStateScaleFlagsFlag ContrailPointStateScaleFlagsFlag_from_string(const char *value);

    using ContrailFlags = std::uint16_t;
    enum ContrailFlagsFlag : std::uint16_t {
        CONTRAIL_FLAGS_FLAG_FIRST_POINT_UNFADED = static_cast<std::uint16_t>(1) << 0,
        CONTRAIL_FLAGS_FLAG_LAST_POINT_UNFADED = static_cast<std::uint16_t>(1) << 1,
        CONTRAIL_FLAGS_FLAG_POINTS_START_PINNED_TO_MEDIA = static_cast<std::uint16_t>(1) << 2,
        CONTRAIL_FLAGS_FLAG_POINTS_START_PINNED_TO_GROUND = static_cast<std::uint16_t>(1) << 3,
        CONTRAIL_FLAGS_FLAG_POINTS_ALWAYS_PINNED_TO_MEDIA = static_cast<std::uint16_t>(1) << 4,
        CONTRAIL_FLAGS_FLAG_POINTS_ALWAYS_PINNED_TO_GROUND = static_cast<std::uint16_t>(1) << 5,
        CONTRAIL_FLAGS_FLAG_EDGE_EFFECT_FADES_SLOWLY = static_cast<std::uint16_t>(1) << 6,
        CONTRAIL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ContrailFlagsFlag_to_string(ContrailFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ContrailFlagsFlag_to_string_pretty(ContrailFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ContrailFlagsFlag ContrailFlagsFlag_from_string(const char *value);

    using ContrailScaleFlags = std::uint16_t;
    enum ContrailScaleFlagsFlag : std::uint16_t {
        CONTRAIL_SCALE_FLAGS_FLAG_POINT_GENERATION_RATE = static_cast<std::uint16_t>(1) << 0,
        CONTRAIL_SCALE_FLAGS_FLAG_POINT_VELOCITY = static_cast<std::uint16_t>(1) << 1,
        CONTRAIL_SCALE_FLAGS_FLAG_POINT_VELOCITY_DELTA = static_cast<std::uint16_t>(1) << 2,
        CONTRAIL_SCALE_FLAGS_FLAG_POINT_VELOCITY_CONE_ANGLE = static_cast<std::uint16_t>(1) << 3,
        CONTRAIL_SCALE_FLAGS_FLAG_INHERITED_VELOCITY_FRACTION = static_cast<std::uint16_t>(1) << 4,
        CONTRAIL_SCALE_FLAGS_FLAG_SEQUENCE_ANIMATION_RATE = static_cast<std::uint16_t>(1) << 5,
        CONTRAIL_SCALE_FLAGS_FLAG_TEXTURE_SCALE_U = static_cast<std::uint16_t>(1) << 6,
        CONTRAIL_SCALE_FLAGS_FLAG_TEXTURE_SCALE_V = static_cast<std::uint16_t>(1) << 7,
        CONTRAIL_SCALE_FLAGS_FLAG_TEXTURE_ANIMATION_U = static_cast<std::uint16_t>(1) << 8,
        CONTRAIL_SCALE_FLAGS_FLAG_TEXTURE_ANIMATION_V = static_cast<std::uint16_t>(1) << 9,
        CONTRAIL_SCALE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ContrailScaleFlagsFlag_to_string(ContrailScaleFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ContrailScaleFlagsFlag_to_string_pretty(ContrailScaleFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ContrailScaleFlagsFlag ContrailScaleFlagsFlag_from_string(const char *value);

    using DamageEffectDamageFlags = std::uint32_t;
    enum DamageEffectDamageFlagsFlag : std::uint32_t {
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_DOES_NOT_HURT_OWNER = static_cast<std::uint32_t>(1) << 0,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_CAN_CAUSE_HEADSHOTS = static_cast<std::uint32_t>(1) << 1,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_PINGS_RESISTANT_UNITS = static_cast<std::uint32_t>(1) << 2,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_DOES_NOT_HURT_FRIENDS = static_cast<std::uint32_t>(1) << 3,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_DOES_NOT_PING_UNITS = static_cast<std::uint32_t>(1) << 4,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_DETONATES_EXPLOSIVES = static_cast<std::uint32_t>(1) << 5,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_ONLY_HURTS_SHIELDS = static_cast<std::uint32_t>(1) << 6,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_CAUSES_FLAMING_DEATH = static_cast<std::uint32_t>(1) << 7,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_DAMAGE_INDICATORS_ALWAYS_POINT_DOWN = static_cast<std::uint32_t>(1) << 8,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_SKIPS_SHIELDS = static_cast<std::uint32_t>(1) << 9,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_ONLY_HURTS_ONE_INFECTION_FORM = static_cast<std::uint32_t>(1) << 10,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_CAN_CAUSE_MULTIPLAYER_HEADSHOTS = static_cast<std::uint32_t>(1) << 11,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_INFECTION_FORM_POP = static_cast<std::uint32_t>(1) << 12,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_IGNORE_SEAT_SCALE_FOR_DIR_DMG = static_cast<std::uint32_t>(1) << 13,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_FORCES_HARD_PING = static_cast<std::uint32_t>(1) << 14,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_DOES_NOT_HURT_PLAYERS = static_cast<std::uint32_t>(1) << 15,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_USE_3D_INSTANTANEOUS_ACCELERATION = static_cast<std::uint32_t>(1) << 16,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_ALLOW_ANY_NON_ZERO_ACCELERATION_VALUE = static_cast<std::uint32_t>(1) << 17,
        DAMAGE_EFFECT_DAMAGE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DamageEffectDamageFlagsFlag_to_string(DamageEffectDamageFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DamageEffectDamageFlagsFlag_to_string_pretty(DamageEffectDamageFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DamageEffectDamageFlagsFlag DamageEffectDamageFlagsFlag_from_string(const char *value);

    using DamageEffectFlags = std::uint32_t;
    enum DamageEffectFlagsFlag : std::uint32_t {
        DAMAGE_EFFECT_FLAGS_FLAG_DO_NOT_SCALE_DAMAGE_BY_DISTANCE = static_cast<std::uint32_t>(1) << 0,
        DAMAGE_EFFECT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DamageEffectFlagsFlag_to_string(DamageEffectFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DamageEffectFlagsFlag_to_string_pretty(DamageEffectFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DamageEffectFlagsFlag DamageEffectFlagsFlag_from_string(const char *value);

    using DecalFlags = std::uint16_t;
    enum DecalFlagsFlag : std::uint16_t {
        DECAL_FLAGS_FLAG_GEOMETRY_INHERITED_BY_NEXT_DECAL_IN_CHAIN = static_cast<std::uint16_t>(1) << 0,
        DECAL_FLAGS_FLAG_INTERPOLATE_COLOR_IN_HSV = static_cast<std::uint16_t>(1) << 1,
        DECAL_FLAGS_FLAG_MORE_COLORS = static_cast<std::uint16_t>(1) << 2,
        DECAL_FLAGS_FLAG_NO_RANDOM_ROTATION = static_cast<std::uint16_t>(1) << 3,
        DECAL_FLAGS_FLAG_WATER_EFFECT = static_cast<std::uint16_t>(1) << 4,
        DECAL_FLAGS_FLAG_SAPIEN_SNAP_TO_AXIS = static_cast<std::uint16_t>(1) << 5,
        DECAL_FLAGS_FLAG_SAPIEN_INCREMENTAL_COUNTER = static_cast<std::uint16_t>(1) << 6,
        DECAL_FLAGS_FLAG_ANIMATION_LOOP = static_cast<std::uint16_t>(1) << 7,
        DECAL_FLAGS_FLAG_PRESERVE_ASPECT = static_cast<std::uint16_t>(1) << 8,
        DECAL_FLAGS_FLAG_DISABLED_IN_ANNIVERSARY_BY_BLOOD_SETTING = static_cast<std::uint16_t>(1) << 9,
        DECAL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DecalFlagsFlag_to_string(DecalFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DecalFlagsFlag_to_string_pretty(DecalFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DecalFlagsFlag DecalFlagsFlag_from_string(const char *value);

    using DetailObjectCollectionTypeFlags = std::uint8_t;
    enum DetailObjectCollectionTypeFlagsFlag : std::uint8_t {
        DETAIL_OBJECT_COLLECTION_TYPE_FLAGS_FLAG_UNUSED_A = static_cast<std::uint8_t>(1) << 0,
        DETAIL_OBJECT_COLLECTION_TYPE_FLAGS_FLAG_UNUSED_B = static_cast<std::uint8_t>(1) << 1,
        DETAIL_OBJECT_COLLECTION_TYPE_FLAGS_FLAG_INTERPOLATE_COLOR_IN_HSV = static_cast<std::uint8_t>(1) << 2,
        DETAIL_OBJECT_COLLECTION_TYPE_FLAGS_FLAG_MORE_COLORS = static_cast<std::uint8_t>(1) << 3,
        DETAIL_OBJECT_COLLECTION_TYPE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DetailObjectCollectionTypeFlagsFlag_to_string(DetailObjectCollectionTypeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DetailObjectCollectionTypeFlagsFlag_to_string_pretty(DetailObjectCollectionTypeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DetailObjectCollectionTypeFlagsFlag DetailObjectCollectionTypeFlagsFlag_from_string(const char *value);

    using DeviceFlags = std::uint32_t;
    enum DeviceFlagsFlag : std::uint32_t {
        DEVICE_FLAGS_FLAG_POSITION_LOOPS = static_cast<std::uint32_t>(1) << 0,
        DEVICE_FLAGS_FLAG_POSITION_NOT_INTERPOLATED = static_cast<std::uint32_t>(1) << 1,
        DEVICE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *DeviceFlagsFlag_to_string(DeviceFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *DeviceFlagsFlag_to_string_pretty(DeviceFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    DeviceFlagsFlag DeviceFlagsFlag_from_string(const char *value);

    using MachineFlags = std::uint16_t;
    enum MachineFlagsFlag : std::uint16_t {
        MACHINE_FLAGS_FLAG_PATHFINDING_OBSTACLE = static_cast<std::uint16_t>(1) << 0,
        MACHINE_FLAGS_FLAG_BUT_NOT_WHEN_OPEN = static_cast<std::uint16_t>(1) << 1,
        MACHINE_FLAGS_FLAG_ELEVATOR = static_cast<std::uint16_t>(1) << 2,
        MACHINE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *MachineFlagsFlag_to_string(MachineFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *MachineFlagsFlag_to_string_pretty(MachineFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    MachineFlagsFlag MachineFlagsFlag_from_string(const char *value);

    using EffectPartFlags = std::uint16_t;
    enum EffectPartFlagsFlag : std::uint16_t {
        EFFECT_PART_FLAGS_FLAG_FACE_DOWN_REGARDLESS_OF_LOCATION_DECALS = static_cast<std::uint16_t>(1) << 0,
        EFFECT_PART_FLAGS_FLAG_UNUSED = static_cast<std::uint16_t>(1) << 1,
        EFFECT_PART_FLAGS_FLAG_MAKE_EFFECT_WORK = static_cast<std::uint16_t>(1) << 2,
        EFFECT_PART_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectPartFlagsFlag_to_string(EffectPartFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectPartFlagsFlag_to_string_pretty(EffectPartFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectPartFlagsFlag EffectPartFlagsFlag_from_string(const char *value);

    using EffectPartScalesValues = std::uint32_t;
    enum EffectPartScalesValuesFlag : std::uint32_t {
        EFFECT_PART_SCALES_VALUES_FLAG_VELOCITY = static_cast<std::uint32_t>(1) << 0,
        EFFECT_PART_SCALES_VALUES_FLAG_VELOCITY_DELTA = static_cast<std::uint32_t>(1) << 1,
        EFFECT_PART_SCALES_VALUES_FLAG_VELOCITY_CONE_ANGLE = static_cast<std::uint32_t>(1) << 2,
        EFFECT_PART_SCALES_VALUES_FLAG_ANGULAR_VELOCITY = static_cast<std::uint32_t>(1) << 3,
        EFFECT_PART_SCALES_VALUES_FLAG_ANGULAR_VELOCITY_DELTA = static_cast<std::uint32_t>(1) << 4,
        EFFECT_PART_SCALES_VALUES_FLAG_TYPE_SPECIFIC_SCALE = static_cast<std::uint32_t>(1) << 5,
        EFFECT_PART_SCALES_VALUES_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectPartScalesValuesFlag_to_string(EffectPartScalesValuesFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectPartScalesValuesFlag_to_string_pretty(EffectPartScalesValuesFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectPartScalesValuesFlag EffectPartScalesValuesFlag_from_string(const char *value);

    using EffectParticleFlags = std::uint32_t;
    enum EffectParticleFlagsFlag : std::uint32_t {
        EFFECT_PARTICLE_FLAGS_FLAG_STAY_ATTACHED_TO_MARKER = static_cast<std::uint32_t>(1) << 0,
        EFFECT_PARTICLE_FLAGS_FLAG_RANDOM_INITIAL_ANGLE = static_cast<std::uint32_t>(1) << 1,
        EFFECT_PARTICLE_FLAGS_FLAG_TINT_FROM_OBJECT_COLOR = static_cast<std::uint32_t>(1) << 2,
        EFFECT_PARTICLE_FLAGS_FLAG_INTERPOLATE_TINT_AS_HSV = static_cast<std::uint32_t>(1) << 3,
        EFFECT_PARTICLE_FLAGS_FLAG_ACROSS_THE_LONG_HUE_PATH = static_cast<std::uint32_t>(1) << 4,
        EFFECT_PARTICLE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectParticleFlagsFlag_to_string(EffectParticleFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectParticleFlagsFlag_to_string_pretty(EffectParticleFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectParticleFlagsFlag EffectParticleFlagsFlag_from_string(const char *value);

    using EffectParticleScalesValues = std::uint32_t;
    enum EffectParticleScalesValuesFlag : std::uint32_t {
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_VELOCITY = static_cast<std::uint32_t>(1) << 0,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_VELOCITY_DELTA = static_cast<std::uint32_t>(1) << 1,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_VELOCITY_CONE_ANGLE = static_cast<std::uint32_t>(1) << 2,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_ANGULAR_VELOCITY = static_cast<std::uint32_t>(1) << 3,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_ANGULAR_VELOCITY_DELTA = static_cast<std::uint32_t>(1) << 4,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_COUNT = static_cast<std::uint32_t>(1) << 5,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_COUNT_DELTA = static_cast<std::uint32_t>(1) << 6,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_DISTRIBUTION_RADIUS = static_cast<std::uint32_t>(1) << 7,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_DISTRIBUTION_RADIUS_DELTA = static_cast<std::uint32_t>(1) << 8,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_PARTICLE_RADIUS = static_cast<std::uint32_t>(1) << 9,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_PARTICLE_RADIUS_DELTA = static_cast<std::uint32_t>(1) << 10,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_TINT = static_cast<std::uint32_t>(1) << 11,
        EFFECT_PARTICLE_SCALES_VALUES_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectParticleScalesValuesFlag_to_string(EffectParticleScalesValuesFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectParticleScalesValuesFlag_to_string_pretty(EffectParticleScalesValuesFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectParticleScalesValuesFlag EffectParticleScalesValuesFlag_from_string(const char *value);

    using EffectFlags = std::uint32_t;
    enum EffectFlagsFlag : std::uint32_t {
        EFFECT_FLAGS_FLAG_DELETED_WHEN_ATTACHMENT_DEACTIVATES = static_cast<std::uint32_t>(1) << 0,
        EFFECT_FLAGS_FLAG_MUST_BE_DETERMINISTIC_XBOX = static_cast<std::uint32_t>(1) << 1,
        EFFECT_FLAGS_FLAG_MUST_BE_DETERMINISTIC_PC = static_cast<std::uint32_t>(1) << 2,
        EFFECT_FLAGS_FLAG_DISABLED_IN_ANNIVERSARY_BY_BLOOD_SETTING = static_cast<std::uint32_t>(1) << 3,
        EFFECT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EffectFlagsFlag_to_string(EffectFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EffectFlagsFlag_to_string_pretty(EffectFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EffectFlagsFlag EffectFlagsFlag_from_string(const char *value);

    using FogFlags = std::uint32_t;
    enum FogFlagsFlag : std::uint32_t {
        FOG_FLAGS_FLAG_IS_WATER = static_cast<std::uint32_t>(1) << 0,
        FOG_FLAGS_FLAG_ATMOSPHERE_DOMINANT = static_cast<std::uint32_t>(1) << 1,
        FOG_FLAGS_FLAG_FOG_SCREEN_ONLY = static_cast<std::uint32_t>(1) << 2,
        FOG_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FogFlagsFlag_to_string(FogFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FogFlagsFlag_to_string_pretty(FogFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FogFlagsFlag FogFlagsFlag_from_string(const char *value);

    using FogScreenFlags = std::uint16_t;
    enum FogScreenFlagsFlag : std::uint16_t {
        FOG_SCREEN_FLAGS_FLAG_NO_ENVIRONMENT_MULTIPASS = static_cast<std::uint16_t>(1) << 0,
        FOG_SCREEN_FLAGS_FLAG_NO_MODEL_MULTIPASS = static_cast<std::uint16_t>(1) << 1,
        FOG_SCREEN_FLAGS_FLAG_NO_TEXTURE_BASED_FALLOFF = static_cast<std::uint16_t>(1) << 2,
        FOG_SCREEN_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FogScreenFlagsFlag_to_string(FogScreenFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FogScreenFlagsFlag_to_string_pretty(FogScreenFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FogScreenFlagsFlag FogScreenFlagsFlag_from_string(const char *value);

    using FontFlags = std::uint32_t;
    enum FontFlagsFlag : std::uint32_t {
        FONT_FLAGS_FLAG_DISABLE_MCC_FONT_OVERRIDE = static_cast<std::uint32_t>(1) << 0,
        FONT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *FontFlagsFlag_to_string(FontFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *FontFlagsFlag_to_string_pretty(FontFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    FontFlagsFlag FontFlagsFlag_from_string(const char *value);

    using GlobalsRasterizerDataFlags = std::uint16_t;
    enum GlobalsRasterizerDataFlagsFlag : std::uint16_t {
        GLOBALS_RASTERIZER_DATA_FLAGS_FLAG_TINT_EDGE_DENSITY = static_cast<std::uint16_t>(1) << 0,
        GLOBALS_RASTERIZER_DATA_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GlobalsRasterizerDataFlagsFlag_to_string(GlobalsRasterizerDataFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GlobalsRasterizerDataFlagsFlag_to_string_pretty(GlobalsRasterizerDataFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GlobalsRasterizerDataFlagsFlag GlobalsRasterizerDataFlagsFlag_from_string(const char *value);

    using GlobalsBreakableSurfaceParticleEffectFlags = std::uint32_t;
    enum GlobalsBreakableSurfaceParticleEffectFlagsFlag : std::uint32_t {
        GLOBALS_BREAKABLE_SURFACE_PARTICLE_EFFECT_FLAGS_FLAG_INTERPOLATE_COLOR_IN_HSV = static_cast<std::uint32_t>(1) << 0,
        GLOBALS_BREAKABLE_SURFACE_PARTICLE_EFFECT_FLAGS_FLAG_MORE_COLORS = static_cast<std::uint32_t>(1) << 1,
        GLOBALS_BREAKABLE_SURFACE_PARTICLE_EFFECT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GlobalsBreakableSurfaceParticleEffectFlagsFlag_to_string(GlobalsBreakableSurfaceParticleEffectFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GlobalsBreakableSurfaceParticleEffectFlagsFlag_to_string_pretty(GlobalsBreakableSurfaceParticleEffectFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GlobalsBreakableSurfaceParticleEffectFlagsFlag GlobalsBreakableSurfaceParticleEffectFlagsFlag_from_string(const char *value);

    using GlowFlags = std::uint32_t;
    enum GlowFlagsFlag : std::uint32_t {
        GLOW_FLAGS_FLAG_MODIFY_PARTICLE_COLOR_IN_RANGE = static_cast<std::uint32_t>(1) << 0,
        GLOW_FLAGS_FLAG_PARTICLES_MOVE_BACKWARDS = static_cast<std::uint32_t>(1) << 1,
        GLOW_FLAGS_FLAG_PARTICES_MOVE_IN_BOTH_DIRECTIONS = static_cast<std::uint32_t>(1) << 2,
        GLOW_FLAGS_FLAG_TRAILING_PARTICLES_FADE_OVER_TIME = static_cast<std::uint32_t>(1) << 3,
        GLOW_FLAGS_FLAG_TRAILING_PARTICLES_SHRINK_OVER_TIME = static_cast<std::uint32_t>(1) << 4,
        GLOW_FLAGS_FLAG_TRAILING_PARTICLES_SLOW_OVER_TIME = static_cast<std::uint32_t>(1) << 5,
        GLOW_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GlowFlagsFlag_to_string(GlowFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GlowFlagsFlag_to_string_pretty(GlowFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GlowFlagsFlag GlowFlagsFlag_from_string(const char *value);

    using GrenadeHUDInterfaceOverlayType = std::uint16_t;
    enum GrenadeHUDInterfaceOverlayTypeFlag : std::uint16_t {
        GRENADE_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_FLASHING = static_cast<std::uint16_t>(1) << 0,
        GRENADE_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_EMPTY = static_cast<std::uint16_t>(1) << 1,
        GRENADE_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_DEFAULT = static_cast<std::uint16_t>(1) << 2,
        GRENADE_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ALWAYS = static_cast<std::uint16_t>(1) << 3,
        GRENADE_HUD_INTERFACE_OVERLAY_TYPE_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GrenadeHUDInterfaceOverlayTypeFlag_to_string(GrenadeHUDInterfaceOverlayTypeFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GrenadeHUDInterfaceOverlayTypeFlag_to_string_pretty(GrenadeHUDInterfaceOverlayTypeFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GrenadeHUDInterfaceOverlayTypeFlag GrenadeHUDInterfaceOverlayTypeFlag_from_string(const char *value);

    using GrenadeHUDInterfaceSoundLatchedTo = std::uint32_t;
    enum GrenadeHUDInterfaceSoundLatchedToFlag : std::uint32_t {
        GRENADE_HUD_INTERFACE_SOUND_LATCHED_TO_FLAG_LOW_GRENADE_COUNT = static_cast<std::uint32_t>(1) << 0,
        GRENADE_HUD_INTERFACE_SOUND_LATCHED_TO_FLAG_NO_GRENADES_LEFT = static_cast<std::uint32_t>(1) << 1,
        GRENADE_HUD_INTERFACE_SOUND_LATCHED_TO_FLAG_THROW_ON_NO_GRENADES = static_cast<std::uint32_t>(1) << 2,
        GRENADE_HUD_INTERFACE_SOUND_LATCHED_TO_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *GrenadeHUDInterfaceSoundLatchedToFlag_to_string(GrenadeHUDInterfaceSoundLatchedToFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *GrenadeHUDInterfaceSoundLatchedToFlag_to_string_pretty(GrenadeHUDInterfaceSoundLatchedToFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    GrenadeHUDInterfaceSoundLatchedToFlag GrenadeHUDInterfaceSoundLatchedToFlag_from_string(const char *value);

    using HUDGlobalsWaypointArrowFlags = std::uint32_t;
    enum HUDGlobalsWaypointArrowFlagsFlag : std::uint32_t {
        HUD_GLOBALS_WAYPOINT_ARROW_FLAGS_FLAG_DONT_ROTATE_WHEN_POINTING_OFFSCREEN = static_cast<std::uint32_t>(1) << 0,
        HUD_GLOBALS_WAYPOINT_ARROW_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDGlobalsWaypointArrowFlagsFlag_to_string(HUDGlobalsWaypointArrowFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDGlobalsWaypointArrowFlagsFlag_to_string_pretty(HUDGlobalsWaypointArrowFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDGlobalsWaypointArrowFlagsFlag HUDGlobalsWaypointArrowFlagsFlag_from_string(const char *value);

    using HUDGlobalsAnniversaryRemapTargetFlags = std::uint16_t;
    enum HUDGlobalsAnniversaryRemapTargetFlagsFlag : std::uint16_t {
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_FLAGS_FLAG_LEGACY_MODE = static_cast<std::uint16_t>(1) << 0,
        HUD_GLOBALS_ANNIVERSARY_REMAP_TARGET_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDGlobalsAnniversaryRemapTargetFlagsFlag_to_string(HUDGlobalsAnniversaryRemapTargetFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDGlobalsAnniversaryRemapTargetFlagsFlag_to_string_pretty(HUDGlobalsAnniversaryRemapTargetFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDGlobalsAnniversaryRemapTargetFlagsFlag HUDGlobalsAnniversaryRemapTargetFlagsFlag_from_string(const char *value);

    using HUDInterfaceMeterFlags = std::uint8_t;
    enum HUDInterfaceMeterFlagsFlag : std::uint8_t {
        HUD_INTERFACE_METER_FLAGS_FLAG_USE_MIN_MAX_FOR_STATE_CHANGES = static_cast<std::uint8_t>(1) << 0,
        HUD_INTERFACE_METER_FLAGS_FLAG_INTERPOLATE_BETWEEN_MIN_MAX_FLASH_COLORS_AS_STATE_CHANGES = static_cast<std::uint8_t>(1) << 1,
        HUD_INTERFACE_METER_FLAGS_FLAG_INTERPOLATE_COLOR_ALONG_HSV_SPACE = static_cast<std::uint8_t>(1) << 2,
        HUD_INTERFACE_METER_FLAGS_FLAG_MORE_COLORS_FOR_HSV_INTERPOLATION = static_cast<std::uint8_t>(1) << 3,
        HUD_INTERFACE_METER_FLAGS_FLAG_INVERT_INTERPOLATION = static_cast<std::uint8_t>(1) << 4,
        HUD_INTERFACE_METER_FLAGS_FLAG_USE_XBOX_SHADING = static_cast<std::uint8_t>(1) << 5,
        HUD_INTERFACE_METER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceMeterFlagsFlag_to_string(HUDInterfaceMeterFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceMeterFlagsFlag_to_string_pretty(HUDInterfaceMeterFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceMeterFlagsFlag HUDInterfaceMeterFlagsFlag_from_string(const char *value);

    using HUDInterfaceScalingFlags = std::uint16_t;
    enum HUDInterfaceScalingFlagsFlag : std::uint16_t {
        HUD_INTERFACE_SCALING_FLAGS_FLAG_DONT_SCALE_OFFSET = static_cast<std::uint16_t>(1) << 0,
        HUD_INTERFACE_SCALING_FLAGS_FLAG_DONT_SCALE_SIZE = static_cast<std::uint16_t>(1) << 1,
        HUD_INTERFACE_SCALING_FLAGS_FLAG_USE_HIGH_RES_SCALE = static_cast<std::uint16_t>(1) << 2,
        HUD_INTERFACE_SCALING_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceScalingFlagsFlag_to_string(HUDInterfaceScalingFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceScalingFlagsFlag_to_string_pretty(HUDInterfaceScalingFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceScalingFlagsFlag HUDInterfaceScalingFlagsFlag_from_string(const char *value);

    using HUDInterfaceFlashFlags = std::uint16_t;
    enum HUDInterfaceFlashFlagsFlag : std::uint16_t {
        HUD_INTERFACE_FLASH_FLAGS_FLAG_REVERSE_DEFAULT_FLASHING_COLORS = static_cast<std::uint16_t>(1) << 0,
        HUD_INTERFACE_FLASH_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceFlashFlagsFlag_to_string(HUDInterfaceFlashFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceFlashFlagsFlag_to_string_pretty(HUDInterfaceFlashFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceFlashFlagsFlag HUDInterfaceFlashFlagsFlag_from_string(const char *value);

    using HUDInterfaceNumberFlags = std::uint8_t;
    enum HUDInterfaceNumberFlagsFlag : std::uint8_t {
        HUD_INTERFACE_NUMBER_FLAGS_FLAG_SHOW_LEADING_ZEROS = static_cast<std::uint8_t>(1) << 0,
        HUD_INTERFACE_NUMBER_FLAGS_FLAG_ONLY_SHOW_WHEN_ZOOMED = static_cast<std::uint8_t>(1) << 1,
        HUD_INTERFACE_NUMBER_FLAGS_FLAG_DRAW_A_TRAILING_M = static_cast<std::uint8_t>(1) << 2,
        HUD_INTERFACE_NUMBER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceNumberFlagsFlag_to_string(HUDInterfaceNumberFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceNumberFlagsFlag_to_string_pretty(HUDInterfaceNumberFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceNumberFlagsFlag HUDInterfaceNumberFlagsFlag_from_string(const char *value);

    using HUDInterfaceOverlayFlashFlags = std::uint32_t;
    enum HUDInterfaceOverlayFlashFlagsFlag : std::uint32_t {
        HUD_INTERFACE_OVERLAY_FLASH_FLAGS_FLAG_FLASHES_WHEN_ACTIVE = static_cast<std::uint32_t>(1) << 0,
        HUD_INTERFACE_OVERLAY_FLASH_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceOverlayFlashFlagsFlag_to_string(HUDInterfaceOverlayFlashFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceOverlayFlashFlagsFlag_to_string_pretty(HUDInterfaceOverlayFlashFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceOverlayFlashFlagsFlag HUDInterfaceOverlayFlashFlagsFlag_from_string(const char *value);

    using HUDInterfaceMessagingFlags = std::uint8_t;
    enum HUDInterfaceMessagingFlagsFlag : std::uint8_t {
        HUD_INTERFACE_MESSAGING_FLAGS_FLAG_USE_TEXT_FROM_STRING_LIST_INSTEAD = static_cast<std::uint8_t>(1) << 0,
        HUD_INTERFACE_MESSAGING_FLAGS_FLAG_OVERRIDE_DEFAULT_COLOR = static_cast<std::uint8_t>(1) << 1,
        HUD_INTERFACE_MESSAGING_FLAGS_FLAG_WIDTH_OFFSET_IS_ABSOLUTE_ICON_WIDTH = static_cast<std::uint8_t>(1) << 2,
        HUD_INTERFACE_MESSAGING_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *HUDInterfaceMessagingFlagsFlag_to_string(HUDInterfaceMessagingFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *HUDInterfaceMessagingFlagsFlag_to_string_pretty(HUDInterfaceMessagingFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    HUDInterfaceMessagingFlagsFlag HUDInterfaceMessagingFlagsFlag_from_string(const char *value);

    using InputDeviceDefaultsFlags = std::uint16_t;
    enum InputDeviceDefaultsFlagsFlag : std::uint16_t {
        INPUT_DEVICE_DEFAULTS_FLAGS_FLAG_UNUSED = static_cast<std::uint16_t>(1) << 0,
        INPUT_DEVICE_DEFAULTS_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *InputDeviceDefaultsFlagsFlag_to_string(InputDeviceDefaultsFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *InputDeviceDefaultsFlagsFlag_to_string_pretty(InputDeviceDefaultsFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    InputDeviceDefaultsFlagsFlag InputDeviceDefaultsFlagsFlag_from_string(const char *value);

    using ItemFlags = std::uint32_t;
    enum ItemFlagsFlag : std::uint32_t {
        ITEM_FLAGS_FLAG_ALWAYS_MAINTAINS_Z_UP = static_cast<std::uint32_t>(1) << 0,
        ITEM_FLAGS_FLAG_DESTROYED_BY_EXPLOSIONS = static_cast<std::uint32_t>(1) << 1,
        ITEM_FLAGS_FLAG_UNAFFECTED_BY_GRAVITY = static_cast<std::uint32_t>(1) << 2,
        ITEM_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ItemFlagsFlag_to_string(ItemFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ItemFlagsFlag_to_string_pretty(ItemFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ItemFlagsFlag ItemFlagsFlag_from_string(const char *value);

    using LensFlareReflectionFlags = std::uint16_t;
    enum LensFlareReflectionFlagsFlag : std::uint16_t {
        LENS_FLARE_REFLECTION_FLAGS_FLAG_ALIGN_ROTATION_WITH_SCREEN_CENTER = static_cast<std::uint16_t>(1) << 0,
        LENS_FLARE_REFLECTION_FLAGS_FLAG_RADIUS_NOT_SCALED_BY_DISTANCE = static_cast<std::uint16_t>(1) << 1,
        LENS_FLARE_REFLECTION_FLAGS_FLAG_RADIUS_SCALED_BY_OCCLUSION_FACTOR = static_cast<std::uint16_t>(1) << 2,
        LENS_FLARE_REFLECTION_FLAGS_FLAG_OCCLUDED_BY_SOLID_OBJECTS = static_cast<std::uint16_t>(1) << 3,
        LENS_FLARE_REFLECTION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LensFlareReflectionFlagsFlag_to_string(LensFlareReflectionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LensFlareReflectionFlagsFlag_to_string_pretty(LensFlareReflectionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LensFlareReflectionFlagsFlag LensFlareReflectionFlagsFlag_from_string(const char *value);

    using LensFlareReflectionMoreFlags = std::uint16_t;
    enum LensFlareReflectionMoreFlagsFlag : std::uint16_t {
        LENS_FLARE_REFLECTION_MORE_FLAGS_FLAG_INTERPOLATE_COLORS_IN_HSV = static_cast<std::uint16_t>(1) << 0,
        LENS_FLARE_REFLECTION_MORE_FLAGS_FLAG_MORE_COLORS = static_cast<std::uint16_t>(1) << 1,
        LENS_FLARE_REFLECTION_MORE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LensFlareReflectionMoreFlagsFlag_to_string(LensFlareReflectionMoreFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LensFlareReflectionMoreFlagsFlag_to_string_pretty(LensFlareReflectionMoreFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LensFlareReflectionMoreFlagsFlag LensFlareReflectionMoreFlagsFlag_from_string(const char *value);

    using LensFlareFlags = std::uint16_t;
    enum LensFlareFlagsFlag : std::uint16_t {
        LENS_FLARE_FLAGS_FLAG_SUN = static_cast<std::uint16_t>(1) << 0,
        LENS_FLARE_FLAGS_FLAG_NO_OCCLUSION_TEST = static_cast<std::uint16_t>(1) << 1,
        LENS_FLARE_FLAGS_FLAG_ONLY_RENDER_IN_FIRST_PERSON = static_cast<std::uint16_t>(1) << 2,
        LENS_FLARE_FLAGS_FLAG_ONLY_RENDER_IN_THIRD_PERSON = static_cast<std::uint16_t>(1) << 3,
        LENS_FLARE_FLAGS_FLAG_FADE_IN_MORE_QUICKLY = static_cast<std::uint16_t>(1) << 4,
        LENS_FLARE_FLAGS_FLAG_FADE_OUT_MORE_QUICKLY = static_cast<std::uint16_t>(1) << 5,
        LENS_FLARE_FLAGS_FLAG_SCALE_BY_MARKER = static_cast<std::uint16_t>(1) << 6,
        LENS_FLARE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LensFlareFlagsFlag_to_string(LensFlareFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LensFlareFlagsFlag_to_string_pretty(LensFlareFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LensFlareFlagsFlag LensFlareFlagsFlag_from_string(const char *value);

    using LightFlags = std::uint32_t;
    enum LightFlagsFlag : std::uint32_t {
        LIGHT_FLAGS_FLAG_DYNAMIC = static_cast<std::uint32_t>(1) << 0,
        LIGHT_FLAGS_FLAG_NO_SPECULAR = static_cast<std::uint32_t>(1) << 1,
        LIGHT_FLAGS_FLAG_DONT_LIGHT_OWN_OBJECT = static_cast<std::uint32_t>(1) << 2,
        LIGHT_FLAGS_FLAG_SUPERSIZE_IN_FIRST_PERSON = static_cast<std::uint32_t>(1) << 3,
        LIGHT_FLAGS_FLAG_FIRST_PERSON_FLASHLIGHT = static_cast<std::uint32_t>(1) << 4,
        LIGHT_FLAGS_FLAG_DONT_FADE_ACTIVE_CAMOUFLAGE = static_cast<std::uint32_t>(1) << 5,
        LIGHT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LightFlagsFlag_to_string(LightFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LightFlagsFlag_to_string_pretty(LightFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LightFlagsFlag LightFlagsFlag_from_string(const char *value);

    using LightVolumeFlags = std::uint16_t;
    enum LightVolumeFlagsFlag : std::uint16_t {
        LIGHT_VOLUME_FLAGS_FLAG_INTERPOLATE_COLOR_IN_HSV = static_cast<std::uint16_t>(1) << 0,
        LIGHT_VOLUME_FLAGS_FLAG_MORE_COLORS = static_cast<std::uint16_t>(1) << 1,
        LIGHT_VOLUME_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LightVolumeFlagsFlag_to_string(LightVolumeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LightVolumeFlagsFlag_to_string_pretty(LightVolumeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LightVolumeFlagsFlag LightVolumeFlagsFlag_from_string(const char *value);

    using LightningMarkerFlag = std::uint16_t;
    enum LightningMarkerFlagFlag : std::uint16_t {
        LIGHTNING_MARKER_FLAG_FLAG_NOT_CONNECTED_TO_NEXT_MARKER = static_cast<std::uint16_t>(1) << 0,
        LIGHTNING_MARKER_FLAG_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *LightningMarkerFlagFlag_to_string(LightningMarkerFlagFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *LightningMarkerFlagFlag_to_string_pretty(LightningMarkerFlagFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    LightningMarkerFlagFlag LightningMarkerFlagFlag_from_string(const char *value);

    using ModelRegionPermutationFlags = std::uint32_t;
    enum ModelRegionPermutationFlagsFlag : std::uint32_t {
        MODEL_REGION_PERMUTATION_FLAGS_FLAG_CANNOT_BE_CHOSEN_RANDOMLY = static_cast<std::uint32_t>(1) << 0,
        MODEL_REGION_PERMUTATION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelRegionPermutationFlagsFlag_to_string(ModelRegionPermutationFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelRegionPermutationFlagsFlag_to_string_pretty(ModelRegionPermutationFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelRegionPermutationFlagsFlag ModelRegionPermutationFlagsFlag_from_string(const char *value);

    using ModelGeometryPartFlags = std::uint32_t;
    enum ModelGeometryPartFlagsFlag : std::uint32_t {
        MODEL_GEOMETRY_PART_FLAGS_FLAG_STRIPPED_INTERNAL = static_cast<std::uint32_t>(1) << 0,
        MODEL_GEOMETRY_PART_FLAGS_FLAG_ZONER = static_cast<std::uint32_t>(1) << 1,
        MODEL_GEOMETRY_PART_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelGeometryPartFlagsFlag_to_string(ModelGeometryPartFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelGeometryPartFlagsFlag_to_string_pretty(ModelGeometryPartFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelGeometryPartFlagsFlag ModelGeometryPartFlagsFlag_from_string(const char *value);

    using ModelFlags = std::uint32_t;
    enum ModelFlagsFlag : std::uint32_t {
        MODEL_FLAGS_FLAG_BLEND_SHARED_NORMALS = static_cast<std::uint32_t>(1) << 0,
        MODEL_FLAGS_FLAG_PARTS_HAVE_LOCAL_NODES = static_cast<std::uint32_t>(1) << 1,
        MODEL_FLAGS_FLAG_IGNORE_SKINNING = static_cast<std::uint32_t>(1) << 2,
        MODEL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelFlagsFlag_to_string(ModelFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelFlagsFlag_to_string_pretty(ModelFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelFlagsFlag ModelFlagsFlag_from_string(const char *value);

    using ModelAnimationsAnimationGraphNodeFlags = std::uint32_t;
    enum ModelAnimationsAnimationGraphNodeFlagsFlag : std::uint32_t {
        MODEL_ANIMATIONS_ANIMATION_GRAPH_NODE_FLAGS_FLAG_BALL_SOCKET = static_cast<std::uint32_t>(1) << 0,
        MODEL_ANIMATIONS_ANIMATION_GRAPH_NODE_FLAGS_FLAG_HINGE = static_cast<std::uint32_t>(1) << 1,
        MODEL_ANIMATIONS_ANIMATION_GRAPH_NODE_FLAGS_FLAG_NO_MOVEMENT = static_cast<std::uint32_t>(1) << 2,
        MODEL_ANIMATIONS_ANIMATION_GRAPH_NODE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelAnimationsAnimationGraphNodeFlagsFlag_to_string(ModelAnimationsAnimationGraphNodeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelAnimationsAnimationGraphNodeFlagsFlag_to_string_pretty(ModelAnimationsAnimationGraphNodeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelAnimationsAnimationGraphNodeFlagsFlag ModelAnimationsAnimationGraphNodeFlagsFlag_from_string(const char *value);

    using ModelAnimationsAnimationFlags = std::uint16_t;
    enum ModelAnimationsAnimationFlagsFlag : std::uint16_t {
        MODEL_ANIMATIONS_ANIMATION_FLAGS_FLAG_COMPRESSED_DATA = static_cast<std::uint16_t>(1) << 0,
        MODEL_ANIMATIONS_ANIMATION_FLAGS_FLAG_WORLD_RELATIVE = static_cast<std::uint16_t>(1) << 1,
        MODEL_ANIMATIONS_ANIMATION_FLAGS_FLAG__25HZ_PAL = static_cast<std::uint16_t>(1) << 2,
        MODEL_ANIMATIONS_ANIMATION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelAnimationsAnimationFlagsFlag_to_string(ModelAnimationsAnimationFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelAnimationsAnimationFlagsFlag_to_string_pretty(ModelAnimationsAnimationFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelAnimationsAnimationFlagsFlag ModelAnimationsAnimationFlagsFlag_from_string(const char *value);

    using ModelAnimationsFlags = std::uint16_t;
    enum ModelAnimationsFlagsFlag : std::uint16_t {
        MODEL_ANIMATIONS_FLAGS_FLAG_COMPRESS_ALL_ANIMATIONS = static_cast<std::uint16_t>(1) << 0,
        MODEL_ANIMATIONS_FLAGS_FLAG_FORCE_IDLE_COMPRESSION = static_cast<std::uint16_t>(1) << 1,
        MODEL_ANIMATIONS_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelAnimationsFlagsFlag_to_string(ModelAnimationsFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelAnimationsFlagsFlag_to_string_pretty(ModelAnimationsFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelAnimationsFlagsFlag ModelAnimationsFlagsFlag_from_string(const char *value);

    using ModelCollisionGeometryMaterialFlags = std::uint32_t;
    enum ModelCollisionGeometryMaterialFlagsFlag : std::uint32_t {
        MODEL_COLLISION_GEOMETRY_MATERIAL_FLAGS_FLAG_HEAD = static_cast<std::uint32_t>(1) << 0,
        MODEL_COLLISION_GEOMETRY_MATERIAL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelCollisionGeometryMaterialFlagsFlag_to_string(ModelCollisionGeometryMaterialFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelCollisionGeometryMaterialFlagsFlag_to_string_pretty(ModelCollisionGeometryMaterialFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelCollisionGeometryMaterialFlagsFlag ModelCollisionGeometryMaterialFlagsFlag_from_string(const char *value);

    using ModelCollisionGeometryRegionFlags = std::uint32_t;
    enum ModelCollisionGeometryRegionFlagsFlag : std::uint32_t {
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_LIVES_UNTIL_OBJECT_DIES = static_cast<std::uint32_t>(1) << 0,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_FORCES_OBJECT_TO_DIE = static_cast<std::uint32_t>(1) << 1,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_DIES_WHEN_OBJECT_DIES = static_cast<std::uint32_t>(1) << 2,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_DIES_WHEN_OBJECT_IS_DAMAGED = static_cast<std::uint32_t>(1) << 3,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_DISAPPEARS_WHEN_SHIELD_IS_OFF = static_cast<std::uint32_t>(1) << 4,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_INHIBITS_MELEE_ATTACK = static_cast<std::uint32_t>(1) << 5,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_INHIBITS_WEAPON_ATTACK = static_cast<std::uint32_t>(1) << 6,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_INHIBITS_WALKING = static_cast<std::uint32_t>(1) << 7,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_FORCES_DROP_WEAPON = static_cast<std::uint32_t>(1) << 8,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_CAUSES_HEAD_MAIMED_SCREAM = static_cast<std::uint32_t>(1) << 9,
        MODEL_COLLISION_GEOMETRY_REGION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelCollisionGeometryRegionFlagsFlag_to_string(ModelCollisionGeometryRegionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelCollisionGeometryRegionFlagsFlag_to_string_pretty(ModelCollisionGeometryRegionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelCollisionGeometryRegionFlagsFlag ModelCollisionGeometryRegionFlagsFlag_from_string(const char *value);

    using ModelCollisionGeometryBSPLeafFlags = std::uint16_t;
    enum ModelCollisionGeometryBSPLeafFlagsFlag : std::uint16_t {
        MODEL_COLLISION_GEOMETRY_B_S_P_LEAF_FLAGS_FLAG_CONTAINS_DOUBLE_SIDED_SURFACES = static_cast<std::uint16_t>(1) << 0,
        MODEL_COLLISION_GEOMETRY_B_S_P_LEAF_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelCollisionGeometryBSPLeafFlagsFlag_to_string(ModelCollisionGeometryBSPLeafFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelCollisionGeometryBSPLeafFlagsFlag_to_string_pretty(ModelCollisionGeometryBSPLeafFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelCollisionGeometryBSPLeafFlagsFlag ModelCollisionGeometryBSPLeafFlagsFlag_from_string(const char *value);

    using ModelCollisionGeometryBSPSurfaceFlags = std::uint8_t;
    enum ModelCollisionGeometryBSPSurfaceFlagsFlag : std::uint8_t {
        MODEL_COLLISION_GEOMETRY_B_S_P_SURFACE_FLAGS_FLAG_TWO_SIDED = static_cast<std::uint8_t>(1) << 0,
        MODEL_COLLISION_GEOMETRY_B_S_P_SURFACE_FLAGS_FLAG_INVISIBLE = static_cast<std::uint8_t>(1) << 1,
        MODEL_COLLISION_GEOMETRY_B_S_P_SURFACE_FLAGS_FLAG_CLIMBABLE = static_cast<std::uint8_t>(1) << 2,
        MODEL_COLLISION_GEOMETRY_B_S_P_SURFACE_FLAGS_FLAG_BREAKABLE = static_cast<std::uint8_t>(1) << 3,
        MODEL_COLLISION_GEOMETRY_B_S_P_SURFACE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelCollisionGeometryBSPSurfaceFlagsFlag_to_string(ModelCollisionGeometryBSPSurfaceFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelCollisionGeometryBSPSurfaceFlagsFlag_to_string_pretty(ModelCollisionGeometryBSPSurfaceFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelCollisionGeometryBSPSurfaceFlagsFlag ModelCollisionGeometryBSPSurfaceFlagsFlag_from_string(const char *value);

    using ModelCollisionGeometryFlags = std::uint32_t;
    enum ModelCollisionGeometryFlagsFlag : std::uint32_t {
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_TAKES_SHIELD_DAMAGE_FOR_CHILDREN = static_cast<std::uint32_t>(1) << 0,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_TAKES_BODY_DAMAGE_FOR_CHILDREN = static_cast<std::uint32_t>(1) << 1,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_ALWAYS_SHIELDS_FRIENDLY_DAMAGE = static_cast<std::uint32_t>(1) << 2,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_PASSES_AREA_DAMAGE_TO_CHILDREN = static_cast<std::uint32_t>(1) << 3,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_PARENT_NEVER_TAKES_BODY_DAMAGE_FOR_US = static_cast<std::uint32_t>(1) << 4,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_ONLY_DAMAGED_BY_EXPLOSIVES = static_cast<std::uint32_t>(1) << 5,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_ONLY_DAMAGED_WHILE_OCCUPIED = static_cast<std::uint32_t>(1) << 6,
        MODEL_COLLISION_GEOMETRY_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ModelCollisionGeometryFlagsFlag_to_string(ModelCollisionGeometryFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ModelCollisionGeometryFlagsFlag_to_string_pretty(ModelCollisionGeometryFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ModelCollisionGeometryFlagsFlag ModelCollisionGeometryFlagsFlag_from_string(const char *value);

    using ObjectFunctionFlags = std::uint32_t;
    enum ObjectFunctionFlagsFlag : std::uint32_t {
        OBJECT_FUNCTION_FLAGS_FLAG_INVERT = static_cast<std::uint32_t>(1) << 0,
        OBJECT_FUNCTION_FLAGS_FLAG_ADDITIVE = static_cast<std::uint32_t>(1) << 1,
        OBJECT_FUNCTION_FLAGS_FLAG_ALWAYS_ACTIVE = static_cast<std::uint32_t>(1) << 2,
        OBJECT_FUNCTION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ObjectFunctionFlagsFlag_to_string(ObjectFunctionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ObjectFunctionFlagsFlag_to_string_pretty(ObjectFunctionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ObjectFunctionFlagsFlag ObjectFunctionFlagsFlag_from_string(const char *value);

    using ObjectFlags = std::uint16_t;
    enum ObjectFlagsFlag : std::uint16_t {
        OBJECT_FLAGS_FLAG_DOES_NOT_CAST_SHADOW = static_cast<std::uint16_t>(1) << 0,
        OBJECT_FLAGS_FLAG_TRANSPARENT_SELF_OCCLUSION = static_cast<std::uint16_t>(1) << 1,
        OBJECT_FLAGS_FLAG_BRIGHTER_THAN_IT_SHOULD_BE = static_cast<std::uint16_t>(1) << 2,
        OBJECT_FLAGS_FLAG_NOT_A_PATHFINDING_OBSTACLE = static_cast<std::uint16_t>(1) << 3,
        OBJECT_FLAGS_FLAG_EXTENSION_OF_PARENT = static_cast<std::uint16_t>(1) << 4,
        OBJECT_FLAGS_FLAG_CAST_SHADOW_BY_DEFAULT = static_cast<std::uint16_t>(1) << 5,
        OBJECT_FLAGS_FLAG_DOES_NOT_HAVE_ANNIVERSARY_GEOMETRY = static_cast<std::uint16_t>(1) << 6,
        OBJECT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ObjectFlagsFlag_to_string(ObjectFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ObjectFlagsFlag_to_string_pretty(ObjectFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ObjectFlagsFlag ObjectFlagsFlag_from_string(const char *value);

    using BaseObjectFlags = std::uint16_t;
    enum BaseObjectFlagsFlag : std::uint16_t {
        BASE_OBJECT_FLAGS_FLAG_OFF_IN_PEGASUS = static_cast<std::uint16_t>(1) << 0,
        BASE_OBJECT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *BaseObjectFlagsFlag_to_string(BaseObjectFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *BaseObjectFlagsFlag_to_string_pretty(BaseObjectFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    BaseObjectFlagsFlag BaseObjectFlagsFlag_from_string(const char *value);

    using ParticleFlags = std::uint32_t;
    enum ParticleFlagsFlag : std::uint32_t {
        PARTICLE_FLAGS_FLAG_CAN_ANIMATE_BACKWARDS = static_cast<std::uint32_t>(1) << 0,
        PARTICLE_FLAGS_FLAG_ANIMATION_STOPS_AT_REST = static_cast<std::uint32_t>(1) << 1,
        PARTICLE_FLAGS_FLAG_ANIMATION_STARTS_ON_RANDOM_FRAME = static_cast<std::uint32_t>(1) << 2,
        PARTICLE_FLAGS_FLAG_ANIMATE_ONCE_PER_FRAME = static_cast<std::uint32_t>(1) << 3,
        PARTICLE_FLAGS_FLAG_DIES_AT_REST = static_cast<std::uint32_t>(1) << 4,
        PARTICLE_FLAGS_FLAG_DIES_ON_CONTACT_WITH_STRUCTURE = static_cast<std::uint32_t>(1) << 5,
        PARTICLE_FLAGS_FLAG_TINT_FROM_DIFFUSE_TEXTURE = static_cast<std::uint32_t>(1) << 6,
        PARTICLE_FLAGS_FLAG_DIES_ON_CONTACT_WITH_WATER = static_cast<std::uint32_t>(1) << 7,
        PARTICLE_FLAGS_FLAG_DIES_ON_CONTACT_WITH_AIR = static_cast<std::uint32_t>(1) << 8,
        PARTICLE_FLAGS_FLAG_SELF_ILLUMINATED = static_cast<std::uint32_t>(1) << 9,
        PARTICLE_FLAGS_FLAG_RANDOM_HORIZONTAL_MIRRORING = static_cast<std::uint32_t>(1) << 10,
        PARTICLE_FLAGS_FLAG_RANDOM_VERTICAL_MIRRORING = static_cast<std::uint32_t>(1) << 11,
        PARTICLE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleFlagsFlag_to_string(ParticleFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleFlagsFlag_to_string_pretty(ParticleFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleFlagsFlag ParticleFlagsFlag_from_string(const char *value);

    using ParticleShaderFlags = std::uint16_t;
    enum ParticleShaderFlagsFlag : std::uint16_t {
        PARTICLE_SHADER_FLAGS_FLAG_SORT_BIAS = static_cast<std::uint16_t>(1) << 0,
        PARTICLE_SHADER_FLAGS_FLAG_NONLINEAR_TINT = static_cast<std::uint16_t>(1) << 1,
        PARTICLE_SHADER_FLAGS_FLAG_DONT_OVERDRAW_FP_WEAPON = static_cast<std::uint16_t>(1) << 2,
        PARTICLE_SHADER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleShaderFlagsFlag_to_string(ParticleShaderFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleShaderFlagsFlag_to_string_pretty(ParticleShaderFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleShaderFlagsFlag ParticleShaderFlagsFlag_from_string(const char *value);

    using ParticleSystemTypeFlags = std::uint32_t;
    enum ParticleSystemTypeFlagsFlag : std::uint32_t {
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_TYPE_STATES_LOOP = static_cast<std::uint32_t>(1) << 0,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_FORWARD_BACKWARD = static_cast<std::uint32_t>(1) << 1,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_PARTICLE_STATES_LOOP = static_cast<std::uint32_t>(1) << 2,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_FORWARD_BACKWARD_1 = static_cast<std::uint32_t>(1) << 3,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_PARTICLES_DIE_IN_WATER = static_cast<std::uint32_t>(1) << 4,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_PARTICLES_DIE_IN_AIR = static_cast<std::uint32_t>(1) << 5,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_PARTICLES_DIE_ON_GROUND = static_cast<std::uint32_t>(1) << 6,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_ROTATIONAL_SPRITES_ANIMATE_SIDEWAYS = static_cast<std::uint32_t>(1) << 7,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_DISABLED = static_cast<std::uint32_t>(1) << 8,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_TINT_BY_EFFECT_COLOR = static_cast<std::uint32_t>(1) << 9,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_INITIAL_COUNT_SCALES_WITH_EFFECT = static_cast<std::uint32_t>(1) << 10,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_MINIMUM_COUNT_SCALES_WITH_EFFECT = static_cast<std::uint32_t>(1) << 11,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_CREATION_RATE_SCALES_WITH_EFFECT = static_cast<std::uint32_t>(1) << 12,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_SCALE_SCALES_WITH_EFFECT = static_cast<std::uint32_t>(1) << 13,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_ANIMATION_RATE_SCALES_WITH_EFFECT = static_cast<std::uint32_t>(1) << 14,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_ROTATION_RATE_SCALES_WITH_EFFECT = static_cast<std::uint32_t>(1) << 15,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_DO_NOT_DRAW_IN_FIRST_PERSON = static_cast<std::uint32_t>(1) << 16,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_DO_NOT_DRAW_IN_THIRD_PERSON = static_cast<std::uint32_t>(1) << 17,
        PARTICLE_SYSTEM_TYPE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ParticleSystemTypeFlagsFlag_to_string(ParticleSystemTypeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ParticleSystemTypeFlagsFlag_to_string_pretty(ParticleSystemTypeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ParticleSystemTypeFlagsFlag ParticleSystemTypeFlagsFlag_from_string(const char *value);

    using PhysicsPoweredMassPointFlags = std::uint32_t;
    enum PhysicsPoweredMassPointFlagsFlag : std::uint32_t {
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_GROUND_FRICTION = static_cast<std::uint32_t>(1) << 0,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_WATER_FRICTION = static_cast<std::uint32_t>(1) << 1,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_AIR_FRICTION = static_cast<std::uint32_t>(1) << 2,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_WATER_LIFT = static_cast<std::uint32_t>(1) << 3,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_AIR_LIFT = static_cast<std::uint32_t>(1) << 4,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_THRUST = static_cast<std::uint32_t>(1) << 5,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_ANTIGRAV = static_cast<std::uint32_t>(1) << 6,
        PHYSICS_POWERED_MASS_POINT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *PhysicsPoweredMassPointFlagsFlag_to_string(PhysicsPoweredMassPointFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *PhysicsPoweredMassPointFlagsFlag_to_string_pretty(PhysicsPoweredMassPointFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    PhysicsPoweredMassPointFlagsFlag PhysicsPoweredMassPointFlagsFlag_from_string(const char *value);

    using PhysicsMassPointFlags = std::uint32_t;
    enum PhysicsMassPointFlagsFlag : std::uint32_t {
        PHYSICS_MASS_POINT_FLAGS_FLAG_METALLIC = static_cast<std::uint32_t>(1) << 0,
        PHYSICS_MASS_POINT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *PhysicsMassPointFlagsFlag_to_string(PhysicsMassPointFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *PhysicsMassPointFlagsFlag_to_string_pretty(PhysicsMassPointFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    PhysicsMassPointFlagsFlag PhysicsMassPointFlagsFlag_from_string(const char *value);

    using PointPhysicsFlags = std::uint32_t;
    enum PointPhysicsFlagsFlag : std::uint32_t {
        POINT_PHYSICS_FLAGS_FLAG_FLAMETHROWER_PARTICLE_COLLISION = static_cast<std::uint32_t>(1) << 0,
        POINT_PHYSICS_FLAGS_FLAG_COLLIDES_WITH_STRUCTURES = static_cast<std::uint32_t>(1) << 1,
        POINT_PHYSICS_FLAGS_FLAG_COLLIDES_WITH_WATER_SURFACE = static_cast<std::uint32_t>(1) << 2,
        POINT_PHYSICS_FLAGS_FLAG_USES_SIMPLE_WIND = static_cast<std::uint32_t>(1) << 3,
        POINT_PHYSICS_FLAGS_FLAG_USES_DAMPED_WIND = static_cast<std::uint32_t>(1) << 4,
        POINT_PHYSICS_FLAGS_FLAG_NO_GRAVITY = static_cast<std::uint32_t>(1) << 5,
        POINT_PHYSICS_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *PointPhysicsFlagsFlag_to_string(PointPhysicsFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *PointPhysicsFlagsFlag_to_string_pretty(PointPhysicsFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    PointPhysicsFlagsFlag PointPhysicsFlagsFlag_from_string(const char *value);

    using ProjectileFlags = std::uint32_t;
    enum ProjectileFlagsFlag : std::uint32_t {
        PROJECTILE_FLAGS_FLAG_ORIENTED_ALONG_VELOCITY = static_cast<std::uint32_t>(1) << 0,
        PROJECTILE_FLAGS_FLAG_AI_MUST_USE_BALLISTIC_AIMING = static_cast<std::uint32_t>(1) << 1,
        PROJECTILE_FLAGS_FLAG_DETONATION_MAX_TIME_IF_ATTACHED = static_cast<std::uint32_t>(1) << 2,
        PROJECTILE_FLAGS_FLAG_HAS_SUPER_COMBINING_EXPLOSION = static_cast<std::uint32_t>(1) << 3,
        PROJECTILE_FLAGS_FLAG_COMBINE_INITIAL_VELOCITY_WITH_PARENT_VELOCITY = static_cast<std::uint32_t>(1) << 4,
        PROJECTILE_FLAGS_FLAG_RANDOM_ATTACHED_DETONATION_TIME = static_cast<std::uint32_t>(1) << 5,
        PROJECTILE_FLAGS_FLAG_MINIMUM_UNATTACHED_DETONATION_TIME = static_cast<std::uint32_t>(1) << 6,
        PROJECTILE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileFlagsFlag_to_string(ProjectileFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileFlagsFlag_to_string_pretty(ProjectileFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileFlagsFlag ProjectileFlagsFlag_from_string(const char *value);

    using ProjectileMaterialResponseFlags = std::uint16_t;
    enum ProjectileMaterialResponseFlagsFlag : std::uint16_t {
        PROJECTILE_MATERIAL_RESPONSE_FLAGS_FLAG_CANNOT_BE_OVERPENETRATED = static_cast<std::uint16_t>(1) << 0,
        PROJECTILE_MATERIAL_RESPONSE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileMaterialResponseFlagsFlag_to_string(ProjectileMaterialResponseFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileMaterialResponseFlagsFlag_to_string_pretty(ProjectileMaterialResponseFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileMaterialResponseFlagsFlag ProjectileMaterialResponseFlagsFlag_from_string(const char *value);

    using ProjectileMaterialResponsePotentialFlags = std::uint16_t;
    enum ProjectileMaterialResponsePotentialFlagsFlag : std::uint16_t {
        PROJECTILE_MATERIAL_RESPONSE_POTENTIAL_FLAGS_FLAG_ONLY_AGAINST_UNITS = static_cast<std::uint16_t>(1) << 0,
        PROJECTILE_MATERIAL_RESPONSE_POTENTIAL_FLAGS_FLAG_NEVER_AGAINST_UNITS = static_cast<std::uint16_t>(1) << 1,
        PROJECTILE_MATERIAL_RESPONSE_POTENTIAL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ProjectileMaterialResponsePotentialFlagsFlag_to_string(ProjectileMaterialResponsePotentialFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ProjectileMaterialResponsePotentialFlagsFlag_to_string_pretty(ProjectileMaterialResponsePotentialFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ProjectileMaterialResponsePotentialFlagsFlag ProjectileMaterialResponsePotentialFlagsFlag_from_string(const char *value);

    using ScenarioTextFlags = std::uint32_t;
    enum ScenarioTextFlagsFlag : std::uint32_t {
        SCENARIO_TEXT_FLAGS_FLAG_WRAP_HORIZONTALLY = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_TEXT_FLAGS_FLAG_WRAP_VERTICALLY = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_TEXT_FLAGS_FLAG_CENTER_VERTICALLY = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_TEXT_FLAGS_FLAG_BOTTOM_JUSTIFY = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_TEXT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioTextFlagsFlag_to_string(ScenarioTextFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioTextFlagsFlag_to_string_pretty(ScenarioTextFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioTextFlagsFlag ScenarioTextFlagsFlag_from_string(const char *value);

    using ScenarioFunctionFlags = std::uint32_t;
    enum ScenarioFunctionFlagsFlag : std::uint32_t {
        SCENARIO_FUNCTION_FLAGS_FLAG_SCRIPTED = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_FUNCTION_FLAGS_FLAG_INVERT = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_FUNCTION_FLAGS_FLAG_ADDITIVE = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_FUNCTION_FLAGS_FLAG_ALWAYS_ACTIVE = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_FUNCTION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioFunctionFlagsFlag_to_string(ScenarioFunctionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioFunctionFlagsFlag_to_string_pretty(ScenarioFunctionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioFunctionFlagsFlag ScenarioFunctionFlagsFlag_from_string(const char *value);

    using ScenarioSpawnNotPlaced = std::uint16_t;
    enum ScenarioSpawnNotPlacedFlag : std::uint16_t {
        SCENARIO_SPAWN_NOT_PLACED_FLAG_AUTOMATICALLY = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_SPAWN_NOT_PLACED_FLAG_ON_EASY = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_SPAWN_NOT_PLACED_FLAG_ON_NORMAL = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_SPAWN_NOT_PLACED_FLAG_ON_HARD = static_cast<std::uint16_t>(1) << 3,
        SCENARIO_SPAWN_NOT_PLACED_FLAG_USE_PLAYER_APPEARANCE = static_cast<std::uint16_t>(1) << 4,
        SCENARIO_SPAWN_NOT_PLACED_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioSpawnNotPlacedFlag_to_string(ScenarioSpawnNotPlacedFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioSpawnNotPlacedFlag_to_string_pretty(ScenarioSpawnNotPlacedFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioSpawnNotPlacedFlag ScenarioSpawnNotPlacedFlag_from_string(const char *value);

    using ScenarioUnitFlags = std::uint32_t;
    enum ScenarioUnitFlagsFlag : std::uint32_t {
        SCENARIO_UNIT_FLAGS_FLAG_DEAD = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_UNIT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioUnitFlagsFlag_to_string(ScenarioUnitFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioUnitFlagsFlag_to_string_pretty(ScenarioUnitFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioUnitFlagsFlag ScenarioUnitFlagsFlag_from_string(const char *value);

    using ScenarioVehicleMultiplayerSpawnFlags = std::uint16_t;
    enum ScenarioVehicleMultiplayerSpawnFlagsFlag : std::uint16_t {
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_SLAYER_DEFAULT = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_CTF_DEFAULT = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_KING_DEFAULT = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_ODDBALL_DEFAULT = static_cast<std::uint16_t>(1) << 3,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED = static_cast<std::uint16_t>(1) << 4,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED1 = static_cast<std::uint16_t>(1) << 5,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED2 = static_cast<std::uint16_t>(1) << 6,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED3 = static_cast<std::uint16_t>(1) << 7,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_SLAYER_ALLOWED = static_cast<std::uint16_t>(1) << 8,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_CTF_ALLOWED = static_cast<std::uint16_t>(1) << 9,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_KING_ALLOWED = static_cast<std::uint16_t>(1) << 10,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_ODDBALL_ALLOWED = static_cast<std::uint16_t>(1) << 11,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED4 = static_cast<std::uint16_t>(1) << 12,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED5 = static_cast<std::uint16_t>(1) << 13,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED6 = static_cast<std::uint16_t>(1) << 14,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_UNUSED7 = static_cast<std::uint16_t>(1) << 15,
        SCENARIO_VEHICLE_MULTIPLAYER_SPAWN_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioVehicleMultiplayerSpawnFlagsFlag_to_string(ScenarioVehicleMultiplayerSpawnFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioVehicleMultiplayerSpawnFlagsFlag_to_string_pretty(ScenarioVehicleMultiplayerSpawnFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioVehicleMultiplayerSpawnFlagsFlag ScenarioVehicleMultiplayerSpawnFlagsFlag_from_string(const char *value);

    using ScenarioItemFlags = std::uint16_t;
    enum ScenarioItemFlagsFlag : std::uint16_t {
        SCENARIO_ITEM_FLAGS_FLAG_INITIALLY_AT_REST = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_ITEM_FLAGS_FLAG_OBSOLETE = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_ITEM_FLAGS_FLAG_DOES_ACCELERATE = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_ITEM_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioItemFlagsFlag_to_string(ScenarioItemFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioItemFlagsFlag_to_string_pretty(ScenarioItemFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioItemFlagsFlag ScenarioItemFlagsFlag_from_string(const char *value);

    using ScenarioDeviceGroupFlags = std::uint32_t;
    enum ScenarioDeviceGroupFlagsFlag : std::uint32_t {
        SCENARIO_DEVICE_GROUP_FLAGS_FLAG_CAN_CHANGE_ONLY_ONCE = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_DEVICE_GROUP_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioDeviceGroupFlagsFlag_to_string(ScenarioDeviceGroupFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioDeviceGroupFlagsFlag_to_string_pretty(ScenarioDeviceGroupFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioDeviceGroupFlagsFlag ScenarioDeviceGroupFlagsFlag_from_string(const char *value);

    using ScenarioDeviceFlags = std::uint32_t;
    enum ScenarioDeviceFlagsFlag : std::uint32_t {
        SCENARIO_DEVICE_FLAGS_FLAG_INITIALLY_OPEN = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_DEVICE_FLAGS_FLAG_INITIALLY_OFF = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_DEVICE_FLAGS_FLAG_CAN_CHANGE_ONLY_ONCE = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_DEVICE_FLAGS_FLAG_POSITION_REVERSED = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_DEVICE_FLAGS_FLAG_NOT_USABLE_FROM_ANY_SIDE = static_cast<std::uint32_t>(1) << 4,
        SCENARIO_DEVICE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioDeviceFlagsFlag_to_string(ScenarioDeviceFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioDeviceFlagsFlag_to_string_pretty(ScenarioDeviceFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioDeviceFlagsFlag ScenarioDeviceFlagsFlag_from_string(const char *value);

    using ScenarioMachineFlags = std::uint32_t;
    enum ScenarioMachineFlagsFlag : std::uint32_t {
        SCENARIO_MACHINE_FLAGS_FLAG_DOES_NOT_OPERATE_AUTOMATICALLY = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_MACHINE_FLAGS_FLAG_ONE_SIDED = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_MACHINE_FLAGS_FLAG_NEVER_APPEARS_LOCKED = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_MACHINE_FLAGS_FLAG_OPENED_BY_MELEE_ATTACK = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_MACHINE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioMachineFlagsFlag_to_string(ScenarioMachineFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioMachineFlagsFlag_to_string_pretty(ScenarioMachineFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioMachineFlagsFlag ScenarioMachineFlagsFlag_from_string(const char *value);

    using ScenarioControlFlags = std::uint32_t;
    enum ScenarioControlFlagsFlag : std::uint32_t {
        SCENARIO_CONTROL_FLAGS_FLAG_USABLE_FROM_BOTH_SIDES = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_CONTROL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioControlFlagsFlag_to_string(ScenarioControlFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioControlFlagsFlag_to_string_pretty(ScenarioControlFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioControlFlagsFlag ScenarioControlFlagsFlag_from_string(const char *value);

    using ScenarioNetgameEquipmentFlags = std::uint32_t;
    enum ScenarioNetgameEquipmentFlagsFlag : std::uint32_t {
        SCENARIO_NETGAME_EQUIPMENT_FLAGS_FLAG_LEVITATE = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_NETGAME_EQUIPMENT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioNetgameEquipmentFlagsFlag_to_string(ScenarioNetgameEquipmentFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioNetgameEquipmentFlagsFlag_to_string_pretty(ScenarioNetgameEquipmentFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioNetgameEquipmentFlagsFlag ScenarioNetgameEquipmentFlagsFlag_from_string(const char *value);

    using ScenarioStartingEquipmentFlags = std::uint32_t;
    enum ScenarioStartingEquipmentFlagsFlag : std::uint32_t {
        SCENARIO_STARTING_EQUIPMENT_FLAGS_FLAG_NO_GRENADES = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_STARTING_EQUIPMENT_FLAGS_FLAG_PLASMA_GRENADES_ONLY = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_STARTING_EQUIPMENT_FLAGS_FLAG_TYPE2_GRENADES_ONLY = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_STARTING_EQUIPMENT_FLAGS_FLAG_TYPE3_GRENADES_ONLY = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_STARTING_EQUIPMENT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioStartingEquipmentFlagsFlag_to_string(ScenarioStartingEquipmentFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioStartingEquipmentFlagsFlag_to_string_pretty(ScenarioStartingEquipmentFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioStartingEquipmentFlagsFlag ScenarioStartingEquipmentFlagsFlag_from_string(const char *value);

    using ScenarioActorStartingLocationFlags = std::uint8_t;
    enum ScenarioActorStartingLocationFlagsFlag : std::uint8_t {
        SCENARIO_ACTOR_STARTING_LOCATION_FLAGS_FLAG_REQUIRED = static_cast<std::uint8_t>(1) << 0,
        SCENARIO_ACTOR_STARTING_LOCATION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioActorStartingLocationFlagsFlag_to_string(ScenarioActorStartingLocationFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioActorStartingLocationFlagsFlag_to_string_pretty(ScenarioActorStartingLocationFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioActorStartingLocationFlagsFlag ScenarioActorStartingLocationFlagsFlag_from_string(const char *value);

    using ScenarioSquadFlags = std::uint32_t;
    enum ScenarioSquadFlagsFlag : std::uint32_t {
        SCENARIO_SQUAD_FLAGS_FLAG_UNUSED = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_SQUAD_FLAGS_FLAG_NEVER_SEARCH = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_SQUAD_FLAGS_FLAG_START_TIMER_IMMEDIATELY = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_SQUAD_FLAGS_FLAG_NO_TIMER_DELAY_FOREVER = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_SQUAD_FLAGS_FLAG_MAGIC_SIGHT_AFTER_TIMER = static_cast<std::uint32_t>(1) << 4,
        SCENARIO_SQUAD_FLAGS_FLAG_AUTOMATIC_MIGRATION = static_cast<std::uint32_t>(1) << 5,
        SCENARIO_SQUAD_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioSquadFlagsFlag_to_string(ScenarioSquadFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioSquadFlagsFlag_to_string_pretty(ScenarioSquadFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioSquadFlagsFlag ScenarioSquadFlagsFlag_from_string(const char *value);

    using ScenarioSquadAttacking = std::uint32_t;
    enum ScenarioSquadAttackingFlag : std::uint32_t {
        SCENARIO_SQUAD_ATTACKING_FLAG_A = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_SQUAD_ATTACKING_FLAG_B = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_SQUAD_ATTACKING_FLAG_C = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_SQUAD_ATTACKING_FLAG_D = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_SQUAD_ATTACKING_FLAG_E = static_cast<std::uint32_t>(1) << 4,
        SCENARIO_SQUAD_ATTACKING_FLAG_F = static_cast<std::uint32_t>(1) << 5,
        SCENARIO_SQUAD_ATTACKING_FLAG_G = static_cast<std::uint32_t>(1) << 6,
        SCENARIO_SQUAD_ATTACKING_FLAG_H = static_cast<std::uint32_t>(1) << 7,
        SCENARIO_SQUAD_ATTACKING_FLAG_I = static_cast<std::uint32_t>(1) << 8,
        SCENARIO_SQUAD_ATTACKING_FLAG_J = static_cast<std::uint32_t>(1) << 9,
        SCENARIO_SQUAD_ATTACKING_FLAG_K = static_cast<std::uint32_t>(1) << 10,
        SCENARIO_SQUAD_ATTACKING_FLAG_L = static_cast<std::uint32_t>(1) << 11,
        SCENARIO_SQUAD_ATTACKING_FLAG_M = static_cast<std::uint32_t>(1) << 12,
        SCENARIO_SQUAD_ATTACKING_FLAG_N = static_cast<std::uint32_t>(1) << 13,
        SCENARIO_SQUAD_ATTACKING_FLAG_O = static_cast<std::uint32_t>(1) << 14,
        SCENARIO_SQUAD_ATTACKING_FLAG_P = static_cast<std::uint32_t>(1) << 15,
        SCENARIO_SQUAD_ATTACKING_FLAG_Q = static_cast<std::uint32_t>(1) << 16,
        SCENARIO_SQUAD_ATTACKING_FLAG_R = static_cast<std::uint32_t>(1) << 17,
        SCENARIO_SQUAD_ATTACKING_FLAG_S = static_cast<std::uint32_t>(1) << 18,
        SCENARIO_SQUAD_ATTACKING_FLAG_T = static_cast<std::uint32_t>(1) << 19,
        SCENARIO_SQUAD_ATTACKING_FLAG_U = static_cast<std::uint32_t>(1) << 20,
        SCENARIO_SQUAD_ATTACKING_FLAG_V = static_cast<std::uint32_t>(1) << 21,
        SCENARIO_SQUAD_ATTACKING_FLAG_W = static_cast<std::uint32_t>(1) << 22,
        SCENARIO_SQUAD_ATTACKING_FLAG_X = static_cast<std::uint32_t>(1) << 23,
        SCENARIO_SQUAD_ATTACKING_FLAG_Y = static_cast<std::uint32_t>(1) << 24,
        SCENARIO_SQUAD_ATTACKING_FLAG_Z = static_cast<std::uint32_t>(1) << 25,
        SCENARIO_SQUAD_ATTACKING_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioSquadAttackingFlag_to_string(ScenarioSquadAttackingFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioSquadAttackingFlag_to_string_pretty(ScenarioSquadAttackingFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioSquadAttackingFlag ScenarioSquadAttackingFlag_from_string(const char *value);

    using ScenarioPlatoonFlags = std::uint32_t;
    enum ScenarioPlatoonFlagsFlag : std::uint32_t {
        SCENARIO_PLATOON_FLAGS_FLAG_FLEE_WHEN_MANEUVERING = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_PLATOON_FLAGS_FLAG_SAY_ADVANCING_WHEN_MANEUVER = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_PLATOON_FLAGS_FLAG_START_IN_DEFENDING_STATE = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_PLATOON_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioPlatoonFlagsFlag_to_string(ScenarioPlatoonFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioPlatoonFlagsFlag_to_string_pretty(ScenarioPlatoonFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioPlatoonFlagsFlag ScenarioPlatoonFlagsFlag_from_string(const char *value);

    using ScenarioEncounterFlags = std::uint32_t;
    enum ScenarioEncounterFlagsFlag : std::uint32_t {
        SCENARIO_ENCOUNTER_FLAGS_FLAG_NOT_INITIALLY_CREATED = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_ENCOUNTER_FLAGS_FLAG_RESPAWN_ENABLED = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_ENCOUNTER_FLAGS_FLAG_INITIALLY_BLIND = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_ENCOUNTER_FLAGS_FLAG_INITIALLY_DEAF = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_ENCOUNTER_FLAGS_FLAG_INITIALLY_BRAINDEAD = static_cast<std::uint32_t>(1) << 4,
        SCENARIO_ENCOUNTER_FLAGS_FLAG__3D_FIRING_POSITIONS = static_cast<std::uint32_t>(1) << 5,
        SCENARIO_ENCOUNTER_FLAGS_FLAG_MANUAL_BSP_INDEX_SPECIFIED = static_cast<std::uint32_t>(1) << 6,
        SCENARIO_ENCOUNTER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioEncounterFlagsFlag_to_string(ScenarioEncounterFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioEncounterFlagsFlag_to_string_pretty(ScenarioEncounterFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioEncounterFlagsFlag ScenarioEncounterFlagsFlag_from_string(const char *value);

    using ScenarioCommandListFlags = std::uint32_t;
    enum ScenarioCommandListFlagsFlag : std::uint32_t {
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_ALLOW_INITIATIVE = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_ALLOW_TARGETING = static_cast<std::uint32_t>(1) << 1,
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_DISABLE_LOOKING = static_cast<std::uint32_t>(1) << 2,
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_DISABLE_COMMUNICATION = static_cast<std::uint32_t>(1) << 3,
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_DISABLE_FALLING_DAMAGE = static_cast<std::uint32_t>(1) << 4,
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_MANUAL_BSP_INDEX = static_cast<std::uint32_t>(1) << 5,
        SCENARIO_COMMAND_LIST_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioCommandListFlagsFlag_to_string(ScenarioCommandListFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioCommandListFlagsFlag_to_string_pretty(ScenarioCommandListFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioCommandListFlagsFlag ScenarioCommandListFlagsFlag_from_string(const char *value);

    using ScenarioAIConversationParticipantFlags = std::uint16_t;
    enum ScenarioAIConversationParticipantFlagsFlag : std::uint16_t {
        SCENARIO_A_I_CONVERSATION_PARTICIPANT_FLAGS_FLAG_OPTIONAL = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_A_I_CONVERSATION_PARTICIPANT_FLAGS_FLAG_HAS_ALTERNATE = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_A_I_CONVERSATION_PARTICIPANT_FLAGS_FLAG_IS_ALTERNATE = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_A_I_CONVERSATION_PARTICIPANT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioAIConversationParticipantFlagsFlag_to_string(ScenarioAIConversationParticipantFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioAIConversationParticipantFlagsFlag_to_string_pretty(ScenarioAIConversationParticipantFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioAIConversationParticipantFlagsFlag ScenarioAIConversationParticipantFlagsFlag_from_string(const char *value);

    using ScenarioAIConversationLineFlags = std::uint16_t;
    enum ScenarioAIConversationLineFlagsFlag : std::uint16_t {
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_ADDRESSEE_LOOK_AT_SPEAKER = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_EVERYONE_LOOK_AT_SPEAKER = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_EVERYONE_LOOK_AT_ADDRESSEE = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_WAIT_AFTER_UNTIL_TOLD_TO_ADVANCE = static_cast<std::uint16_t>(1) << 3,
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_WAIT_UNTIL_SPEAKER_NEARBY = static_cast<std::uint16_t>(1) << 4,
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_WAIT_UNTIL_EVERYONE_NEARBY = static_cast<std::uint16_t>(1) << 5,
        SCENARIO_A_I_CONVERSATION_LINE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioAIConversationLineFlagsFlag_to_string(ScenarioAIConversationLineFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioAIConversationLineFlagsFlag_to_string_pretty(ScenarioAIConversationLineFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioAIConversationLineFlagsFlag ScenarioAIConversationLineFlagsFlag_from_string(const char *value);

    using ScenarioAIConversationFlags = std::uint16_t;
    enum ScenarioAIConversationFlagsFlag : std::uint16_t {
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_STOP_IF_DEATH = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_STOP_IF_DAMAGED = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_STOP_IF_VISIBLE_ENEMY = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_STOP_IF_ALERTED_TO_ENEMY = static_cast<std::uint16_t>(1) << 3,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_PLAYER_MUST_BE_VISIBLE = static_cast<std::uint16_t>(1) << 4,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_STOP_OTHER_ACTIONS = static_cast<std::uint16_t>(1) << 5,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_KEEP_TRYING_TO_PLAY = static_cast<std::uint16_t>(1) << 6,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_PLAYER_MUST_BE_LOOKING = static_cast<std::uint16_t>(1) << 7,
        SCENARIO_A_I_CONVERSATION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioAIConversationFlagsFlag_to_string(ScenarioAIConversationFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioAIConversationFlagsFlag_to_string_pretty(ScenarioAIConversationFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioAIConversationFlagsFlag ScenarioAIConversationFlagsFlag_from_string(const char *value);

    using ScenarioFlags = std::uint16_t;
    enum ScenarioFlagsFlag : std::uint16_t {
        SCENARIO_FLAGS_FLAG_CORTANA_HACK = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_FLAGS_FLAG_USE_DEMO_UI = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_FLAGS_FLAG_COLOR_CORRECTION_NTSC_TO_SRGB = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_FLAGS_FLAG_DO_NOT_APPLY_BUNGIE_CAMPAIGN_TAG_PATCHES = static_cast<std::uint16_t>(1) << 3,
        SCENARIO_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioFlagsFlag_to_string(ScenarioFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioFlagsFlag_to_string_pretty(ScenarioFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioFlagsFlag ScenarioFlagsFlag_from_string(const char *value);

    using ScenarioScriptNodeFlags = std::uint16_t;
    enum ScenarioScriptNodeFlagsFlag : std::uint16_t {
        SCENARIO_SCRIPT_NODE_FLAGS_FLAG_IS_PRIMITIVE = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_SCRIPT_NODE_FLAGS_FLAG_IS_SCRIPT_CALL = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_SCRIPT_NODE_FLAGS_FLAG_IS_GLOBAL = static_cast<std::uint16_t>(1) << 2,
        SCENARIO_SCRIPT_NODE_FLAGS_FLAG_IS_GARBAGE_COLLECTABLE = static_cast<std::uint16_t>(1) << 3,
        SCENARIO_SCRIPT_NODE_FLAGS_FLAG_IS_LOCAL_VARIABLE = static_cast<std::uint16_t>(1) << 4,
        SCENARIO_SCRIPT_NODE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioScriptNodeFlagsFlag_to_string(ScenarioScriptNodeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioScriptNodeFlagsFlag_to_string_pretty(ScenarioScriptNodeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioScriptNodeFlagsFlag ScenarioScriptNodeFlagsFlag_from_string(const char *value);

    using ScenarioStructureBSPMaterialFlags = std::uint16_t;
    enum ScenarioStructureBSPMaterialFlagsFlag : std::uint16_t {
        SCENARIO_STRUCTURE_B_S_P_MATERIAL_FLAGS_FLAG_COPLANAR = static_cast<std::uint16_t>(1) << 0,
        SCENARIO_STRUCTURE_B_S_P_MATERIAL_FLAGS_FLAG_FOG_PLANE = static_cast<std::uint16_t>(1) << 1,
        SCENARIO_STRUCTURE_B_S_P_MATERIAL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioStructureBSPMaterialFlagsFlag_to_string(ScenarioStructureBSPMaterialFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioStructureBSPMaterialFlagsFlag_to_string_pretty(ScenarioStructureBSPMaterialFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioStructureBSPMaterialFlagsFlag ScenarioStructureBSPMaterialFlagsFlag_from_string(const char *value);

    using ScenarioStructureBSPClusterPortalFlags = std::uint32_t;
    enum ScenarioStructureBSPClusterPortalFlagsFlag : std::uint32_t {
        SCENARIO_STRUCTURE_B_S_P_CLUSTER_PORTAL_FLAGS_FLAG_AI_CAN_SIMPLY_NOT_HEAR_THROUGH_ALL_THIS_AMAZING_STUFF_DARN_IT = static_cast<std::uint32_t>(1) << 0,
        SCENARIO_STRUCTURE_B_S_P_CLUSTER_PORTAL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ScenarioStructureBSPClusterPortalFlagsFlag_to_string(ScenarioStructureBSPClusterPortalFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ScenarioStructureBSPClusterPortalFlagsFlag_to_string_pretty(ScenarioStructureBSPClusterPortalFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ScenarioStructureBSPClusterPortalFlagsFlag ScenarioStructureBSPClusterPortalFlagsFlag_from_string(const char *value);

    using ShaderFlags = std::uint16_t;
    enum ShaderFlagsFlag : std::uint16_t {
        SHADER_FLAGS_FLAG_SIMPLE_PARAMETERIZATION = static_cast<std::uint16_t>(1) << 0,
        SHADER_FLAGS_FLAG_IGNORE_NORMALS = static_cast<std::uint16_t>(1) << 1,
        SHADER_FLAGS_FLAG_TRANSPARENT_LIT = static_cast<std::uint16_t>(1) << 2,
        SHADER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderFlagsFlag_to_string(ShaderFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderFlagsFlag_to_string_pretty(ShaderFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderFlagsFlag ShaderFlagsFlag_from_string(const char *value);

    using ShaderPhysicsFlags = std::uint16_t;
    enum ShaderPhysicsFlagsFlag : std::uint16_t {
        SHADER_PHYSICS_FLAGS_FLAG_UNUSED = static_cast<std::uint16_t>(1) << 0,
        SHADER_PHYSICS_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderPhysicsFlagsFlag_to_string(ShaderPhysicsFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderPhysicsFlagsFlag_to_string_pretty(ShaderPhysicsFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderPhysicsFlagsFlag ShaderPhysicsFlagsFlag_from_string(const char *value);

    using ShaderEnvironmentFlags = std::uint16_t;
    enum ShaderEnvironmentFlagsFlag : std::uint16_t {
        SHADER_ENVIRONMENT_FLAGS_FLAG_ALPHA_TESTED = static_cast<std::uint16_t>(1) << 0,
        SHADER_ENVIRONMENT_FLAGS_FLAG_BUMP_MAP_IS_SPECULAR_MASK = static_cast<std::uint16_t>(1) << 1,
        SHADER_ENVIRONMENT_FLAGS_FLAG_TRUE_ATMOSPHERIC_FOG = static_cast<std::uint16_t>(1) << 2,
        SHADER_ENVIRONMENT_FLAGS_FLAG_USE_ALTERNATE_BUMP_ATTENUATION = static_cast<std::uint16_t>(1) << 3,
        SHADER_ENVIRONMENT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderEnvironmentFlagsFlag_to_string(ShaderEnvironmentFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderEnvironmentFlagsFlag_to_string_pretty(ShaderEnvironmentFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderEnvironmentFlagsFlag ShaderEnvironmentFlagsFlag_from_string(const char *value);

    using ShaderEnvironmentDiffuseFlags = std::uint16_t;
    enum ShaderEnvironmentDiffuseFlagsFlag : std::uint16_t {
        SHADER_ENVIRONMENT_DIFFUSE_FLAGS_FLAG_RESCALE_DETAIL_MAPS = static_cast<std::uint16_t>(1) << 0,
        SHADER_ENVIRONMENT_DIFFUSE_FLAGS_FLAG_RESCALE_BUMP_MAP = static_cast<std::uint16_t>(1) << 1,
        SHADER_ENVIRONMENT_DIFFUSE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderEnvironmentDiffuseFlagsFlag_to_string(ShaderEnvironmentDiffuseFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderEnvironmentDiffuseFlagsFlag_to_string_pretty(ShaderEnvironmentDiffuseFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderEnvironmentDiffuseFlagsFlag ShaderEnvironmentDiffuseFlagsFlag_from_string(const char *value);

    using ShaderEnvironmentSpecularFlags = std::uint16_t;
    enum ShaderEnvironmentSpecularFlagsFlag : std::uint16_t {
        SHADER_ENVIRONMENT_SPECULAR_FLAGS_FLAG_OVERBRIGHT = static_cast<std::uint16_t>(1) << 0,
        SHADER_ENVIRONMENT_SPECULAR_FLAGS_FLAG_EXTRA_SHINY = static_cast<std::uint16_t>(1) << 1,
        SHADER_ENVIRONMENT_SPECULAR_FLAGS_FLAG_LIGHTMAP_IS_SPECULAR = static_cast<std::uint16_t>(1) << 2,
        SHADER_ENVIRONMENT_SPECULAR_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderEnvironmentSpecularFlagsFlag_to_string(ShaderEnvironmentSpecularFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderEnvironmentSpecularFlagsFlag_to_string_pretty(ShaderEnvironmentSpecularFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderEnvironmentSpecularFlagsFlag ShaderEnvironmentSpecularFlagsFlag_from_string(const char *value);

    using ShaderEnvironmentReflectionFlags = std::uint16_t;
    enum ShaderEnvironmentReflectionFlagsFlag : std::uint16_t {
        SHADER_ENVIRONMENT_REFLECTION_FLAGS_FLAG_DYNAMIC_MIRROR = static_cast<std::uint16_t>(1) << 0,
        SHADER_ENVIRONMENT_REFLECTION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderEnvironmentReflectionFlagsFlag_to_string(ShaderEnvironmentReflectionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderEnvironmentReflectionFlagsFlag_to_string_pretty(ShaderEnvironmentReflectionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderEnvironmentReflectionFlagsFlag ShaderEnvironmentReflectionFlagsFlag_from_string(const char *value);

    using ShaderModelFlags = std::uint16_t;
    enum ShaderModelFlagsFlag : std::uint16_t {
        SHADER_MODEL_FLAGS_FLAG_DETAIL_AFTER_REFLECTION = static_cast<std::uint16_t>(1) << 0,
        SHADER_MODEL_FLAGS_FLAG_TWO_SIDED = static_cast<std::uint16_t>(1) << 1,
        SHADER_MODEL_FLAGS_FLAG_NOT_ALPHA_TESTED = static_cast<std::uint16_t>(1) << 2,
        SHADER_MODEL_FLAGS_FLAG_ALPHA_BLENDED_DECAL = static_cast<std::uint16_t>(1) << 3,
        SHADER_MODEL_FLAGS_FLAG_TRUE_ATMOSPHERIC_FOG = static_cast<std::uint16_t>(1) << 4,
        SHADER_MODEL_FLAGS_FLAG_DISABLE_TWO_SIDED_CULLING = static_cast<std::uint16_t>(1) << 5,
        SHADER_MODEL_FLAGS_FLAG_USE_XBOX_MULTIPURPOSE_CHANNEL_ORDER = static_cast<std::uint16_t>(1) << 6,
        SHADER_MODEL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderModelFlagsFlag_to_string(ShaderModelFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderModelFlagsFlag_to_string_pretty(ShaderModelFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderModelFlagsFlag ShaderModelFlagsFlag_from_string(const char *value);

    using ShaderModelMoreFlags = std::uint16_t;
    enum ShaderModelMoreFlagsFlag : std::uint16_t {
        SHADER_MODEL_MORE_FLAGS_FLAG_NO_RANDOM_PHASE = static_cast<std::uint16_t>(1) << 0,
        SHADER_MODEL_MORE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderModelMoreFlagsFlag_to_string(ShaderModelMoreFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderModelMoreFlagsFlag_to_string_pretty(ShaderModelMoreFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderModelMoreFlagsFlag ShaderModelMoreFlagsFlag_from_string(const char *value);

    using ShaderTransparentChicagoMapFlags = std::uint16_t;
    enum ShaderTransparentChicagoMapFlagsFlag : std::uint16_t {
        SHADER_TRANSPARENT_CHICAGO_MAP_FLAGS_FLAG_UNFILTERED = static_cast<std::uint16_t>(1) << 0,
        SHADER_TRANSPARENT_CHICAGO_MAP_FLAGS_FLAG_ALPHA_REPLICATE = static_cast<std::uint16_t>(1) << 1,
        SHADER_TRANSPARENT_CHICAGO_MAP_FLAGS_FLAG_U_CLAMPED = static_cast<std::uint16_t>(1) << 2,
        SHADER_TRANSPARENT_CHICAGO_MAP_FLAGS_FLAG_V_CLAMPED = static_cast<std::uint16_t>(1) << 3,
        SHADER_TRANSPARENT_CHICAGO_MAP_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentChicagoMapFlagsFlag_to_string(ShaderTransparentChicagoMapFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentChicagoMapFlagsFlag_to_string_pretty(ShaderTransparentChicagoMapFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentChicagoMapFlagsFlag ShaderTransparentChicagoMapFlagsFlag_from_string(const char *value);

    using ShaderTransparentChicagoExtraFlags = std::uint32_t;
    enum ShaderTransparentChicagoExtraFlagsFlag : std::uint32_t {
        SHADER_TRANSPARENT_CHICAGO_EXTRA_FLAGS_FLAG_DONT_FADE_ACTIVE_CAMOUFLAGE = static_cast<std::uint32_t>(1) << 0,
        SHADER_TRANSPARENT_CHICAGO_EXTRA_FLAGS_FLAG_NUMERIC_COUNTDOWN_TIMER = static_cast<std::uint32_t>(1) << 1,
        SHADER_TRANSPARENT_CHICAGO_EXTRA_FLAGS_FLAG_CUSTOM_EDITION_BLENDING = static_cast<std::uint32_t>(1) << 2,
        SHADER_TRANSPARENT_CHICAGO_EXTRA_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentChicagoExtraFlagsFlag_to_string(ShaderTransparentChicagoExtraFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentChicagoExtraFlagsFlag_to_string_pretty(ShaderTransparentChicagoExtraFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentChicagoExtraFlagsFlag ShaderTransparentChicagoExtraFlagsFlag_from_string(const char *value);

    using ShaderTransparentGenericMapFlag = std::uint16_t;
    enum ShaderTransparentGenericMapFlagFlag : std::uint16_t {
        SHADER_TRANSPARENT_GENERIC_MAP_FLAG_FLAG_UNFILTERED = static_cast<std::uint16_t>(1) << 0,
        SHADER_TRANSPARENT_GENERIC_MAP_FLAG_FLAG_U_CLAMPED = static_cast<std::uint16_t>(1) << 1,
        SHADER_TRANSPARENT_GENERIC_MAP_FLAG_FLAG_V_CLAMPED = static_cast<std::uint16_t>(1) << 2,
        SHADER_TRANSPARENT_GENERIC_MAP_FLAG_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericMapFlagFlag_to_string(ShaderTransparentGenericMapFlagFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericMapFlagFlag_to_string_pretty(ShaderTransparentGenericMapFlagFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericMapFlagFlag ShaderTransparentGenericMapFlagFlag_from_string(const char *value);

    using ShaderTransparentGenericStageFlags = std::uint16_t;
    enum ShaderTransparentGenericStageFlagsFlag : std::uint16_t {
        SHADER_TRANSPARENT_GENERIC_STAGE_FLAGS_FLAG_COLOR_MUX = static_cast<std::uint16_t>(1) << 0,
        SHADER_TRANSPARENT_GENERIC_STAGE_FLAGS_FLAG_ALPHA_MUX = static_cast<std::uint16_t>(1) << 1,
        SHADER_TRANSPARENT_GENERIC_STAGE_FLAGS_FLAG_A_OUT_CONTROLS_COLOR0_ANIMATION = static_cast<std::uint16_t>(1) << 2,
        SHADER_TRANSPARENT_GENERIC_STAGE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericStageFlagsFlag_to_string(ShaderTransparentGenericStageFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericStageFlagsFlag_to_string_pretty(ShaderTransparentGenericStageFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericStageFlagsFlag ShaderTransparentGenericStageFlagsFlag_from_string(const char *value);

    using ShaderTransparentGenericFlags = std::uint8_t;
    enum ShaderTransparentGenericFlagsFlag : std::uint8_t {
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_ALPHA_TESTED = static_cast<std::uint8_t>(1) << 0,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_DECAL = static_cast<std::uint8_t>(1) << 1,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_TWO_SIDED = static_cast<std::uint8_t>(1) << 2,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_FIRST_MAP_IS_IN_SCREENSPACE = static_cast<std::uint8_t>(1) << 3,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_DRAW_BEFORE_WATER = static_cast<std::uint8_t>(1) << 4,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_IGNORE_EFFECT = static_cast<std::uint8_t>(1) << 5,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_SCALE_FIRST_MAP_WITH_DISTANCE = static_cast<std::uint8_t>(1) << 6,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_NUMERIC = static_cast<std::uint8_t>(1) << 7,
        SHADER_TRANSPARENT_GENERIC_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGenericFlagsFlag_to_string(ShaderTransparentGenericFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGenericFlagsFlag_to_string_pretty(ShaderTransparentGenericFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGenericFlagsFlag ShaderTransparentGenericFlagsFlag_from_string(const char *value);

    using ShaderTransparentGlassFlags = std::uint16_t;
    enum ShaderTransparentGlassFlagsFlag : std::uint16_t {
        SHADER_TRANSPARENT_GLASS_FLAGS_FLAG_ALPHA_TESTED = static_cast<std::uint16_t>(1) << 0,
        SHADER_TRANSPARENT_GLASS_FLAGS_FLAG_DECAL = static_cast<std::uint16_t>(1) << 1,
        SHADER_TRANSPARENT_GLASS_FLAGS_FLAG_TWO_SIDED = static_cast<std::uint16_t>(1) << 2,
        SHADER_TRANSPARENT_GLASS_FLAGS_FLAG_BUMP_MAP_IS_SPECULAR_MASK = static_cast<std::uint16_t>(1) << 3,
        SHADER_TRANSPARENT_GLASS_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentGlassFlagsFlag_to_string(ShaderTransparentGlassFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentGlassFlagsFlag_to_string_pretty(ShaderTransparentGlassFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentGlassFlagsFlag ShaderTransparentGlassFlagsFlag_from_string(const char *value);

    using ShaderTransparentMeterFlags = std::uint16_t;
    enum ShaderTransparentMeterFlagsFlag : std::uint16_t {
        SHADER_TRANSPARENT_METER_FLAGS_FLAG_DECAL = static_cast<std::uint16_t>(1) << 0,
        SHADER_TRANSPARENT_METER_FLAGS_FLAG_TWO_SIDED = static_cast<std::uint16_t>(1) << 1,
        SHADER_TRANSPARENT_METER_FLAGS_FLAG_FLASH_COLOR_IS_NEGATIVE = static_cast<std::uint16_t>(1) << 2,
        SHADER_TRANSPARENT_METER_FLAGS_FLAG_TINT_MODE_2 = static_cast<std::uint16_t>(1) << 3,
        SHADER_TRANSPARENT_METER_FLAGS_FLAG_UNFILTERED = static_cast<std::uint16_t>(1) << 4,
        SHADER_TRANSPARENT_METER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentMeterFlagsFlag_to_string(ShaderTransparentMeterFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentMeterFlagsFlag_to_string_pretty(ShaderTransparentMeterFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentMeterFlagsFlag ShaderTransparentMeterFlagsFlag_from_string(const char *value);

    using ShaderTransparentWaterFlags = std::uint16_t;
    enum ShaderTransparentWaterFlagsFlag : std::uint16_t {
        SHADER_TRANSPARENT_WATER_FLAGS_FLAG_BASE_MAP_ALPHA_MODULATES_REFLECTION = static_cast<std::uint16_t>(1) << 0,
        SHADER_TRANSPARENT_WATER_FLAGS_FLAG_BASE_MAP_COLOR_MODULATES_BACKGROUND = static_cast<std::uint16_t>(1) << 1,
        SHADER_TRANSPARENT_WATER_FLAGS_FLAG_ATMOSPHERIC_FOG = static_cast<std::uint16_t>(1) << 2,
        SHADER_TRANSPARENT_WATER_FLAGS_FLAG_DRAW_BEFORE_FOG = static_cast<std::uint16_t>(1) << 3,
        SHADER_TRANSPARENT_WATER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ShaderTransparentWaterFlagsFlag_to_string(ShaderTransparentWaterFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ShaderTransparentWaterFlagsFlag_to_string_pretty(ShaderTransparentWaterFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ShaderTransparentWaterFlagsFlag ShaderTransparentWaterFlagsFlag_from_string(const char *value);

    using SkyLightFlags = std::uint32_t;
    enum SkyLightFlagsFlag : std::uint32_t {
        SKY_LIGHT_FLAGS_FLAG_AFFECTS_EXTERIORS = static_cast<std::uint32_t>(1) << 0,
        SKY_LIGHT_FLAGS_FLAG_AFFECTS_INTERIORS = static_cast<std::uint32_t>(1) << 1,
        SKY_LIGHT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SkyLightFlagsFlag_to_string(SkyLightFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SkyLightFlagsFlag_to_string_pretty(SkyLightFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SkyLightFlagsFlag SkyLightFlagsFlag_from_string(const char *value);

    using SoundFlags = std::uint32_t;
    enum SoundFlagsFlag : std::uint32_t {
        SOUND_FLAGS_FLAG_FIT_TO_ADPCM_BLOCKSIZE = static_cast<std::uint32_t>(1) << 0,
        SOUND_FLAGS_FLAG_SPLIT_LONG_SOUND_INTO_PERMUTATIONS = static_cast<std::uint32_t>(1) << 1,
        SOUND_FLAGS_FLAG_THIRSTY_GRUNT = static_cast<std::uint32_t>(1) << 2,
        SOUND_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundFlagsFlag_to_string(SoundFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundFlagsFlag_to_string_pretty(SoundFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundFlagsFlag SoundFlagsFlag_from_string(const char *value);

    using SoundLoopingTrackFlags = std::uint32_t;
    enum SoundLoopingTrackFlagsFlag : std::uint32_t {
        SOUND_LOOPING_TRACK_FLAGS_FLAG_FADE_IN_AT_START = static_cast<std::uint32_t>(1) << 0,
        SOUND_LOOPING_TRACK_FLAGS_FLAG_FADE_OUT_AT_STOP = static_cast<std::uint32_t>(1) << 1,
        SOUND_LOOPING_TRACK_FLAGS_FLAG_FADE_IN_ALTERNATE = static_cast<std::uint32_t>(1) << 2,
        SOUND_LOOPING_TRACK_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundLoopingTrackFlagsFlag_to_string(SoundLoopingTrackFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundLoopingTrackFlagsFlag_to_string_pretty(SoundLoopingTrackFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundLoopingTrackFlagsFlag SoundLoopingTrackFlagsFlag_from_string(const char *value);

    using SoundLoopingDetailFlags = std::uint32_t;
    enum SoundLoopingDetailFlagsFlag : std::uint32_t {
        SOUND_LOOPING_DETAIL_FLAGS_FLAG_DONT_PLAY_WITH_ALTERNATE = static_cast<std::uint32_t>(1) << 0,
        SOUND_LOOPING_DETAIL_FLAGS_FLAG_DONT_PLAY_WITHOUT_ALTERNATE = static_cast<std::uint32_t>(1) << 1,
        SOUND_LOOPING_DETAIL_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundLoopingDetailFlagsFlag_to_string(SoundLoopingDetailFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundLoopingDetailFlagsFlag_to_string_pretty(SoundLoopingDetailFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundLoopingDetailFlagsFlag SoundLoopingDetailFlagsFlag_from_string(const char *value);

    using SoundLoopingFlags = std::uint32_t;
    enum SoundLoopingFlagsFlag : std::uint32_t {
        SOUND_LOOPING_FLAGS_FLAG_DEAFENING_TO_AIS = static_cast<std::uint32_t>(1) << 0,
        SOUND_LOOPING_FLAGS_FLAG_NOT_A_LOOP = static_cast<std::uint32_t>(1) << 1,
        SOUND_LOOPING_FLAGS_FLAG_STOPS_MUSIC = static_cast<std::uint32_t>(1) << 2,
        SOUND_LOOPING_FLAGS_FLAG_SIEGE_OF_MADRIGAL = static_cast<std::uint32_t>(1) << 3,
        SOUND_LOOPING_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *SoundLoopingFlagsFlag_to_string(SoundLoopingFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *SoundLoopingFlagsFlag_to_string_pretty(SoundLoopingFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    SoundLoopingFlagsFlag SoundLoopingFlagsFlag_from_string(const char *value);

    using EventHandlerReferencesFlags = std::uint32_t;
    enum EventHandlerReferencesFlagsFlag : std::uint32_t {
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_CLOSE_CURRENT_WIDGET = static_cast<std::uint32_t>(1) << 0,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_CLOSE_OTHER_WIDGET = static_cast<std::uint32_t>(1) << 1,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_CLOSE_ALL_WIDGETS = static_cast<std::uint32_t>(1) << 2,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_OPEN_WIDGET = static_cast<std::uint32_t>(1) << 3,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_RELOAD_SELF = static_cast<std::uint32_t>(1) << 4,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_RELOAD_OTHER_WIDGET = static_cast<std::uint32_t>(1) << 5,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_GIVE_FOCUS_TO_WIDGET = static_cast<std::uint32_t>(1) << 6,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_RUN_FUNCTION = static_cast<std::uint32_t>(1) << 7,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_REPLACE_SELF_W_WIDGET = static_cast<std::uint32_t>(1) << 8,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_GO_BACK_TO_PREVIOUS_WIDGET = static_cast<std::uint32_t>(1) << 9,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_RUN_SCENARIO_SCRIPT = static_cast<std::uint32_t>(1) << 10,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_TRY_TO_BRANCH_ON_FAILURE = static_cast<std::uint32_t>(1) << 11,
        EVENT_HANDLER_REFERENCES_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *EventHandlerReferencesFlagsFlag_to_string(EventHandlerReferencesFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *EventHandlerReferencesFlagsFlag_to_string_pretty(EventHandlerReferencesFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    EventHandlerReferencesFlagsFlag EventHandlerReferencesFlagsFlag_from_string(const char *value);

    using ConditionalWidgetReferenceFlags = std::uint32_t;
    enum ConditionalWidgetReferenceFlagsFlag : std::uint32_t {
        CONDITIONAL_WIDGET_REFERENCE_FLAGS_FLAG_LOAD_IF_EVENT_HANDLER_FUNCTION_FAILS = static_cast<std::uint32_t>(1) << 0,
        CONDITIONAL_WIDGET_REFERENCE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ConditionalWidgetReferenceFlagsFlag_to_string(ConditionalWidgetReferenceFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ConditionalWidgetReferenceFlagsFlag_to_string_pretty(ConditionalWidgetReferenceFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ConditionalWidgetReferenceFlagsFlag ConditionalWidgetReferenceFlagsFlag_from_string(const char *value);

    using ChildWidgetReferenceFlags = std::uint32_t;
    enum ChildWidgetReferenceFlagsFlag : std::uint32_t {
        CHILD_WIDGET_REFERENCE_FLAGS_FLAG_USE_CUSTOM_CONTROLLER_INDEX = static_cast<std::uint32_t>(1) << 0,
        CHILD_WIDGET_REFERENCE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *ChildWidgetReferenceFlagsFlag_to_string(ChildWidgetReferenceFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *ChildWidgetReferenceFlagsFlag_to_string_pretty(ChildWidgetReferenceFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    ChildWidgetReferenceFlagsFlag ChildWidgetReferenceFlagsFlag_from_string(const char *value);

    using UIWidgetDefinitionFlags = std::uint32_t;
    enum UIWidgetDefinitionFlagsFlag : std::uint32_t {
        UI_WIDGET_DEFINITION_FLAGS_FLAG_PASS_UNHANDLED_EVENTS_TO_FOCUSED_CHILD = static_cast<std::uint32_t>(1) << 0,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_PAUSE_GAME_TIME = static_cast<std::uint32_t>(1) << 1,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_FLASH_BACKGROUND_BITMAP = static_cast<std::uint32_t>(1) << 2,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_DPAD_UP_DOWN_TABS_THRU_CHILDREN = static_cast<std::uint32_t>(1) << 3,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_DPAD_LEFT_RIGHT_TABS_THRU_CHILDREN = static_cast<std::uint32_t>(1) << 4,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_DPAD_UP_DOWN_TABS_THRU_LIST_ITEMS = static_cast<std::uint32_t>(1) << 5,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_DPAD_LEFT_RIGHT_TABS_THRU_LIST_ITEMS = static_cast<std::uint32_t>(1) << 6,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_DONT_FOCUS_A_SPECIFIC_CHILD_WIDGET = static_cast<std::uint32_t>(1) << 7,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_PASS_UNHANDLED_EVENTS_TO_ALL_CHILDREN = static_cast<std::uint32_t>(1) << 8,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_RENDER_REGARDLESS_OF_CONTROLLER_INDEX = static_cast<std::uint32_t>(1) << 9,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_PASS_HANDLED_EVENTS_TO_ALL_CHILDREN = static_cast<std::uint32_t>(1) << 10,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_RETURN_TO_MAIN_MENU_IF_NO_HISTORY = static_cast<std::uint32_t>(1) << 11,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_ALWAYS_USE_TAG_CONTROLLER_INDEX = static_cast<std::uint32_t>(1) << 12,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_ALWAYS_USE_NIFTY_RENDER_FX = static_cast<std::uint32_t>(1) << 13,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_DONT_PUSH_HISTORY = static_cast<std::uint32_t>(1) << 14,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_FORCE_HANDLE_MOUSE = static_cast<std::uint32_t>(1) << 15,
        UI_WIDGET_DEFINITION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIWidgetDefinitionFlagsFlag_to_string(UIWidgetDefinitionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIWidgetDefinitionFlagsFlag_to_string_pretty(UIWidgetDefinitionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIWidgetDefinitionFlagsFlag UIWidgetDefinitionFlagsFlag_from_string(const char *value);

    using UIWidgetDefinitionFlags1 = std::uint32_t;
    enum UIWidgetDefinitionFlags1Flag : std::uint32_t {
        UI_WIDGET_DEFINITION_FLAGS1_FLAG_EDITABLE = static_cast<std::uint32_t>(1) << 0,
        UI_WIDGET_DEFINITION_FLAGS1_FLAG_PASSWORD = static_cast<std::uint32_t>(1) << 1,
        UI_WIDGET_DEFINITION_FLAGS1_FLAG_FLASHING = static_cast<std::uint32_t>(1) << 2,
        UI_WIDGET_DEFINITION_FLAGS1_FLAG_DONT_DO_THAT_WEIRD_FOCUS_TEST = static_cast<std::uint32_t>(1) << 3,
        UI_WIDGET_DEFINITION_FLAGS1_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIWidgetDefinitionFlags1Flag_to_string(UIWidgetDefinitionFlags1Flag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIWidgetDefinitionFlags1Flag_to_string_pretty(UIWidgetDefinitionFlags1Flag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIWidgetDefinitionFlags1Flag UIWidgetDefinitionFlags1Flag_from_string(const char *value);

    using UIWidgetDefinitionFlags2 = std::uint32_t;
    enum UIWidgetDefinitionFlags2Flag : std::uint32_t {
        UI_WIDGET_DEFINITION_FLAGS2_FLAG_LIST_ITEMS_GENERATED_IN_CODE = static_cast<std::uint32_t>(1) << 0,
        UI_WIDGET_DEFINITION_FLAGS2_FLAG_LIST_ITEMS_FROM_STRING_LIST_TAG = static_cast<std::uint32_t>(1) << 1,
        UI_WIDGET_DEFINITION_FLAGS2_FLAG_LIST_ITEMS_ONLY_ONE_TOOLTIP = static_cast<std::uint32_t>(1) << 2,
        UI_WIDGET_DEFINITION_FLAGS2_FLAG_LIST_SINGLE_PREVIEW_NO_SCROLL = static_cast<std::uint32_t>(1) << 3,
        UI_WIDGET_DEFINITION_FLAGS2_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UIWidgetDefinitionFlags2Flag_to_string(UIWidgetDefinitionFlags2Flag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UIWidgetDefinitionFlags2Flag_to_string_pretty(UIWidgetDefinitionFlags2Flag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UIWidgetDefinitionFlags2Flag UIWidgetDefinitionFlags2Flag_from_string(const char *value);

    using UnitFlags = std::uint32_t;
    enum UnitFlagsFlag : std::uint32_t {
        UNIT_FLAGS_FLAG_CIRCULAR_AIMING = static_cast<std::uint32_t>(1) << 0,
        UNIT_FLAGS_FLAG_DESTROYED_AFTER_DYING = static_cast<std::uint32_t>(1) << 1,
        UNIT_FLAGS_FLAG_HALF_SPEED_INTERPOLATION = static_cast<std::uint32_t>(1) << 2,
        UNIT_FLAGS_FLAG_FIRES_FROM_CAMERA = static_cast<std::uint32_t>(1) << 3,
        UNIT_FLAGS_FLAG_ENTRANCE_INSIDE_BOUNDING_SPHERE = static_cast<std::uint32_t>(1) << 4,
        UNIT_FLAGS_FLAG_UNUSED = static_cast<std::uint32_t>(1) << 5,
        UNIT_FLAGS_FLAG_CAUSES_PASSENGER_DIALOGUE = static_cast<std::uint32_t>(1) << 6,
        UNIT_FLAGS_FLAG_RESISTS_PINGS = static_cast<std::uint32_t>(1) << 7,
        UNIT_FLAGS_FLAG_MELEE_ATTACK_IS_FATAL = static_cast<std::uint32_t>(1) << 8,
        UNIT_FLAGS_FLAG_DONT_REFACE_DURING_PINGS = static_cast<std::uint32_t>(1) << 9,
        UNIT_FLAGS_FLAG_HAS_NO_AIMING = static_cast<std::uint32_t>(1) << 10,
        UNIT_FLAGS_FLAG_SIMPLE_CREATURE = static_cast<std::uint32_t>(1) << 11,
        UNIT_FLAGS_FLAG_IMPACT_MELEE_ATTACHES_TO_UNIT = static_cast<std::uint32_t>(1) << 12,
        UNIT_FLAGS_FLAG_IMPACT_MELEE_DIES_ON_SHIELDS = static_cast<std::uint32_t>(1) << 13,
        UNIT_FLAGS_FLAG_CANNOT_OPEN_DOORS_AUTOMATICALLY = static_cast<std::uint32_t>(1) << 14,
        UNIT_FLAGS_FLAG_MELEE_ATTACKERS_CANNOT_ATTACH = static_cast<std::uint32_t>(1) << 15,
        UNIT_FLAGS_FLAG_NOT_INSTANTLY_KILLED_BY_MELEE = static_cast<std::uint32_t>(1) << 16,
        UNIT_FLAGS_FLAG_SHIELD_SAPPING = static_cast<std::uint32_t>(1) << 17,
        UNIT_FLAGS_FLAG_RUNS_AROUND_FLAMING = static_cast<std::uint32_t>(1) << 18,
        UNIT_FLAGS_FLAG_INCONSEQUENTIAL = static_cast<std::uint32_t>(1) << 19,
        UNIT_FLAGS_FLAG_SPECIAL_CINEMATIC_UNIT = static_cast<std::uint32_t>(1) << 20,
        UNIT_FLAGS_FLAG_IGNORED_BY_AUTOAIMING = static_cast<std::uint32_t>(1) << 21,
        UNIT_FLAGS_FLAG_SHIELDS_FRY_INFECTION_FORMS = static_cast<std::uint32_t>(1) << 22,
        UNIT_FLAGS_FLAG_INTEGRATED_LIGHT_CNTRLS_WEAPON = static_cast<std::uint32_t>(1) << 23,
        UNIT_FLAGS_FLAG_INTEGRATED_LIGHT_LASTS_FOREVER = static_cast<std::uint32_t>(1) << 24,
        UNIT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitFlagsFlag_to_string(UnitFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitFlagsFlag_to_string_pretty(UnitFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitFlagsFlag UnitFlagsFlag_from_string(const char *value);

    using UnitSeatFlags = std::uint32_t;
    enum UnitSeatFlagsFlag : std::uint32_t {
        UNIT_SEAT_FLAGS_FLAG_INVISIBLE = static_cast<std::uint32_t>(1) << 0,
        UNIT_SEAT_FLAGS_FLAG_LOCKED = static_cast<std::uint32_t>(1) << 1,
        UNIT_SEAT_FLAGS_FLAG_DRIVER = static_cast<std::uint32_t>(1) << 2,
        UNIT_SEAT_FLAGS_FLAG_GUNNER = static_cast<std::uint32_t>(1) << 3,
        UNIT_SEAT_FLAGS_FLAG_THIRD_PERSON_CAMERA = static_cast<std::uint32_t>(1) << 4,
        UNIT_SEAT_FLAGS_FLAG_ALLOWS_WEAPONS = static_cast<std::uint32_t>(1) << 5,
        UNIT_SEAT_FLAGS_FLAG_THIRD_PERSON_ON_ENTER = static_cast<std::uint32_t>(1) << 6,
        UNIT_SEAT_FLAGS_FLAG_FIRST_PERSON_CAMERA_SLAVED_TO_GUN = static_cast<std::uint32_t>(1) << 7,
        UNIT_SEAT_FLAGS_FLAG_ALLOW_VEHICLE_COMMUNICATION_ANIMATIONS = static_cast<std::uint32_t>(1) << 8,
        UNIT_SEAT_FLAGS_FLAG_NOT_VALID_WITHOUT_DRIVER = static_cast<std::uint32_t>(1) << 9,
        UNIT_SEAT_FLAGS_FLAG_ALLOW_AI_NONCOMBATANTS = static_cast<std::uint32_t>(1) << 10,
        UNIT_SEAT_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitSeatFlagsFlag_to_string(UnitSeatFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitSeatFlagsFlag_to_string_pretty(UnitSeatFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitSeatFlagsFlag UnitSeatFlagsFlag_from_string(const char *value);

    using UnitHUDInterfaceAuxiliaryOverlayFlags = std::uint16_t;
    enum UnitHUDInterfaceAuxiliaryOverlayFlagsFlag : std::uint16_t {
        UNIT_HUD_INTERFACE_AUXILIARY_OVERLAY_FLAGS_FLAG_USE_TEAM_COLOR = static_cast<std::uint16_t>(1) << 0,
        UNIT_HUD_INTERFACE_AUXILIARY_OVERLAY_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitHUDInterfaceAuxiliaryOverlayFlagsFlag_to_string(UnitHUDInterfaceAuxiliaryOverlayFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitHUDInterfaceAuxiliaryOverlayFlagsFlag_to_string_pretty(UnitHUDInterfaceAuxiliaryOverlayFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitHUDInterfaceAuxiliaryOverlayFlagsFlag UnitHUDInterfaceAuxiliaryOverlayFlagsFlag_from_string(const char *value);

    using UnitHUDInterfaceHUDSoundLatchedTo = std::uint32_t;
    enum UnitHUDInterfaceHUDSoundLatchedToFlag : std::uint32_t {
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_SHIELD_RECHARGING = static_cast<std::uint32_t>(1) << 0,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_SHIELD_DAMAGED = static_cast<std::uint32_t>(1) << 1,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_SHIELD_LOW = static_cast<std::uint32_t>(1) << 2,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_SHIELD_EMPTY = static_cast<std::uint32_t>(1) << 3,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_HEALTH_LOW = static_cast<std::uint32_t>(1) << 4,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_HEALTH_EMPTY = static_cast<std::uint32_t>(1) << 5,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_HEALTH_MINOR_DAMAGE = static_cast<std::uint32_t>(1) << 6,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_HEALTH_MAJOR_DAMAGE = static_cast<std::uint32_t>(1) << 7,
        UNIT_HUD_INTERFACE_HUD_SOUND_LATCHED_TO_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitHUDInterfaceHUDSoundLatchedToFlag_to_string(UnitHUDInterfaceHUDSoundLatchedToFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitHUDInterfaceHUDSoundLatchedToFlag_to_string_pretty(UnitHUDInterfaceHUDSoundLatchedToFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitHUDInterfaceHUDSoundLatchedToFlag UnitHUDInterfaceHUDSoundLatchedToFlag_from_string(const char *value);

    using UnitHUDInterfaceAuxiliaryPanelMeterMoreFlags = std::uint32_t;
    enum UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag : std::uint32_t {
        UNIT_HUD_INTERFACE_AUXILIARY_PANEL_METER_MORE_FLAGS_FLAG_SHOW_ONLY_WHEN_ACTIVE = static_cast<std::uint32_t>(1) << 0,
        UNIT_HUD_INTERFACE_AUXILIARY_PANEL_METER_MORE_FLAGS_FLAG_FLASH_ONCE_IF_ACTIVATED_WHILE_DISABLED = static_cast<std::uint32_t>(1) << 1,
        UNIT_HUD_INTERFACE_AUXILIARY_PANEL_METER_MORE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag_to_string(UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag_to_string_pretty(UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag UnitHUDInterfaceAuxiliaryPanelMeterMoreFlagsFlag_from_string(const char *value);

    using VehicleFlags = std::uint32_t;
    enum VehicleFlagsFlag : std::uint32_t {
        VEHICLE_FLAGS_FLAG_SPEED_WAKES_PHYSICS = static_cast<std::uint32_t>(1) << 0,
        VEHICLE_FLAGS_FLAG_TURN_WAKES_PHYSICS = static_cast<std::uint32_t>(1) << 1,
        VEHICLE_FLAGS_FLAG_DRIVER_POWER_WAKES_PHYSICS = static_cast<std::uint32_t>(1) << 2,
        VEHICLE_FLAGS_FLAG_GUNNER_POWER_WAKES_PHYSICS = static_cast<std::uint32_t>(1) << 3,
        VEHICLE_FLAGS_FLAG_CONTROL_OPPOSITE_SPEED_SETS_BRAKE = static_cast<std::uint32_t>(1) << 4,
        VEHICLE_FLAGS_FLAG_SLIDE_WAKES_PHYSICS = static_cast<std::uint32_t>(1) << 5,
        VEHICLE_FLAGS_FLAG_KILLS_RIDERS_AT_TERMINAL_VELOCITY = static_cast<std::uint32_t>(1) << 6,
        VEHICLE_FLAGS_FLAG_CAUSES_COLLISION_DAMAGE = static_cast<std::uint32_t>(1) << 7,
        VEHICLE_FLAGS_FLAG_AI_WEAPON_CANNOT_ROTATE = static_cast<std::uint32_t>(1) << 8,
        VEHICLE_FLAGS_FLAG_AI_DOES_NOT_REQUIRE_DRIVER = static_cast<std::uint32_t>(1) << 9,
        VEHICLE_FLAGS_FLAG_AI_UNUSED = static_cast<std::uint32_t>(1) << 10,
        VEHICLE_FLAGS_FLAG_AI_DRIVER_ENABLE = static_cast<std::uint32_t>(1) << 11,
        VEHICLE_FLAGS_FLAG_AI_DRIVER_FLYING = static_cast<std::uint32_t>(1) << 12,
        VEHICLE_FLAGS_FLAG_AI_DRIVER_CAN_SIDESTEP = static_cast<std::uint32_t>(1) << 13,
        VEHICLE_FLAGS_FLAG_AI_DRIVER_HOVERING = static_cast<std::uint32_t>(1) << 14,
        VEHICLE_FLAGS_FLAG_VEHICLE_STEERS_DIRECTLY = static_cast<std::uint32_t>(1) << 15,
        VEHICLE_FLAGS_FLAG_UNUSED = static_cast<std::uint32_t>(1) << 16,
        VEHICLE_FLAGS_FLAG_HAS_EBRAKE = static_cast<std::uint32_t>(1) << 17,
        VEHICLE_FLAGS_FLAG_NONCOMBAT_VEHICLE = static_cast<std::uint32_t>(1) << 18,
        VEHICLE_FLAGS_FLAG_NO_FRICTION_WITH_DRIVER = static_cast<std::uint32_t>(1) << 19,
        VEHICLE_FLAGS_FLAG_CAN_TRIGGER_AUTOMATIC_OPENING_DOORS = static_cast<std::uint32_t>(1) << 20,
        VEHICLE_FLAGS_FLAG_AUTOAIM_WHEN_TEAMLESS = static_cast<std::uint32_t>(1) << 21,
        VEHICLE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *VehicleFlagsFlag_to_string(VehicleFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *VehicleFlagsFlag_to_string_pretty(VehicleFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    VehicleFlagsFlag VehicleFlagsFlag_from_string(const char *value);

    using WeaponMagazineFlags = std::uint32_t;
    enum WeaponMagazineFlagsFlag : std::uint32_t {
        WEAPON_MAGAZINE_FLAGS_FLAG_WASTES_ROUNDS_WHEN_RELOADED = static_cast<std::uint32_t>(1) << 0,
        WEAPON_MAGAZINE_FLAGS_FLAG_EVERY_ROUND_MUST_BE_CHAMBERED = static_cast<std::uint32_t>(1) << 1,
        WEAPON_MAGAZINE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponMagazineFlagsFlag_to_string(WeaponMagazineFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponMagazineFlagsFlag_to_string_pretty(WeaponMagazineFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponMagazineFlagsFlag WeaponMagazineFlagsFlag_from_string(const char *value);

    using WeaponTriggerFlags = std::uint32_t;
    enum WeaponTriggerFlagsFlag : std::uint32_t {
        WEAPON_TRIGGER_FLAGS_FLAG_TRACKS_FIRED_PROJECTILE = static_cast<std::uint32_t>(1) << 0,
        WEAPON_TRIGGER_FLAGS_FLAG_RANDOM_FIRING_EFFECTS = static_cast<std::uint32_t>(1) << 1,
        WEAPON_TRIGGER_FLAGS_FLAG_CAN_FIRE_WITH_PARTIAL_AMMO = static_cast<std::uint32_t>(1) << 2,
        WEAPON_TRIGGER_FLAGS_FLAG_DOES_NOT_REPEAT_AUTOMATICALLY = static_cast<std::uint32_t>(1) << 3,
        WEAPON_TRIGGER_FLAGS_FLAG_LOCKS_IN_ON_OFF_STATE = static_cast<std::uint32_t>(1) << 4,
        WEAPON_TRIGGER_FLAGS_FLAG_PROJECTILES_USE_WEAPON_ORIGIN = static_cast<std::uint32_t>(1) << 5,
        WEAPON_TRIGGER_FLAGS_FLAG_STICKS_WHEN_DROPPED = static_cast<std::uint32_t>(1) << 6,
        WEAPON_TRIGGER_FLAGS_FLAG_EJECTS_DURING_CHAMBER = static_cast<std::uint32_t>(1) << 7,
        WEAPON_TRIGGER_FLAGS_FLAG_DISCHARGING_SPEWS = static_cast<std::uint32_t>(1) << 8,
        WEAPON_TRIGGER_FLAGS_FLAG_ANALOG_RATE_OF_FIRE = static_cast<std::uint32_t>(1) << 9,
        WEAPON_TRIGGER_FLAGS_FLAG_USE_ERROR_WHEN_UNZOOMED = static_cast<std::uint32_t>(1) << 10,
        WEAPON_TRIGGER_FLAGS_FLAG_PROJECTILE_VECTOR_CANNOT_BE_ADJUSTED = static_cast<std::uint32_t>(1) << 11,
        WEAPON_TRIGGER_FLAGS_FLAG_PROJECTILES_HAVE_IDENTICAL_ERROR = static_cast<std::uint32_t>(1) << 12,
        WEAPON_TRIGGER_FLAGS_FLAG_PROJECTILE_IS_CLIENT_SIDE_ONLY = static_cast<std::uint32_t>(1) << 13,
        WEAPON_TRIGGER_FLAGS_FLAG_USE_ORIGINAL_UNIT_ADJUST_PROJECTILE_RAY = static_cast<std::uint32_t>(1) << 14,
        WEAPON_TRIGGER_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponTriggerFlagsFlag_to_string(WeaponTriggerFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponTriggerFlagsFlag_to_string_pretty(WeaponTriggerFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponTriggerFlagsFlag WeaponTriggerFlagsFlag_from_string(const char *value);

    using WeaponFlags = std::uint32_t;
    enum WeaponFlagsFlag : std::uint32_t {
        WEAPON_FLAGS_FLAG_VERTICAL_HEAT_DISPLAY = static_cast<std::uint32_t>(1) << 0,
        WEAPON_FLAGS_FLAG_MUTUALLY_EXCLUSIVE_TRIGGERS = static_cast<std::uint32_t>(1) << 1,
        WEAPON_FLAGS_FLAG_ATTACKS_AUTOMATICALLY_ON_BUMP = static_cast<std::uint32_t>(1) << 2,
        WEAPON_FLAGS_FLAG_MUST_BE_READIED = static_cast<std::uint32_t>(1) << 3,
        WEAPON_FLAGS_FLAG_DOESNT_COUNT_TOWARD_MAXIMUM = static_cast<std::uint32_t>(1) << 4,
        WEAPON_FLAGS_FLAG_AIM_ASSISTS_ONLY_WHEN_ZOOMED = static_cast<std::uint32_t>(1) << 5,
        WEAPON_FLAGS_FLAG_PREVENTS_GRENADE_THROWING = static_cast<std::uint32_t>(1) << 6,
        WEAPON_FLAGS_FLAG_MUST_BE_PICKED_UP = static_cast<std::uint32_t>(1) << 7,
        WEAPON_FLAGS_FLAG_HOLDS_TRIGGERS_WHEN_DROPPED = static_cast<std::uint32_t>(1) << 8,
        WEAPON_FLAGS_FLAG_PREVENTS_MELEE_ATTACK = static_cast<std::uint32_t>(1) << 9,
        WEAPON_FLAGS_FLAG_DETONATES_WHEN_DROPPED = static_cast<std::uint32_t>(1) << 10,
        WEAPON_FLAGS_FLAG_CANNOT_FIRE_AT_MAXIMUM_AGE = static_cast<std::uint32_t>(1) << 11,
        WEAPON_FLAGS_FLAG_SECONDARY_TRIGGER_OVERRIDES_GRENADES = static_cast<std::uint32_t>(1) << 12,
        WEAPON_FLAGS_FLAG_DOES_NOT_DEPOWER_ACTIVE_CAMO_IN_MULTILPLAYER = static_cast<std::uint32_t>(1) << 13,
        WEAPON_FLAGS_FLAG_ENABLES_INTEGRATED_NIGHT_VISION = static_cast<std::uint32_t>(1) << 14,
        WEAPON_FLAGS_FLAG_AIS_USE_WEAPON_MELEE_DAMAGE = static_cast<std::uint32_t>(1) << 15,
        WEAPON_FLAGS_FLAG_PREVENTS_CROUCHING = static_cast<std::uint32_t>(1) << 16,
        WEAPON_FLAGS_FLAG_USES_3RD_PERSON_CAMERA = static_cast<std::uint32_t>(1) << 17,
        WEAPON_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponFlagsFlag_to_string(WeaponFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponFlagsFlag_to_string_pretty(WeaponFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponFlagsFlag WeaponFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceCrosshairTypeFlags = std::uint32_t;
    enum WeaponHUDInterfaceCrosshairTypeFlagsFlag : std::uint32_t {
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_AIM = static_cast<std::uint32_t>(1) << 0,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_ZOOM_OVERLAY = static_cast<std::uint32_t>(1) << 1,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_CHARGE = static_cast<std::uint32_t>(1) << 2,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_SHOULD_RELOAD = static_cast<std::uint32_t>(1) << 3,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_HEAT = static_cast<std::uint32_t>(1) << 4,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_TOTAL_AMMO = static_cast<std::uint32_t>(1) << 5,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_BATTERY = static_cast<std::uint32_t>(1) << 6,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_RELOAD_OVERHEAT = static_cast<std::uint32_t>(1) << 7,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_WHEN_FIRING_AND_NO_AMMO = static_cast<std::uint32_t>(1) << 8,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_WHEN_THROWING_AND_NO_GRENADE = static_cast<std::uint32_t>(1) << 9,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_LOW_AMMO_AND_NONE_LEFT_TO_RELOAD = static_cast<std::uint32_t>(1) << 10,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_SHOULD_RELOAD_SECONDARY_TRIGGER = static_cast<std::uint32_t>(1) << 11,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_SECONDARY_TOTAL_AMMO = static_cast<std::uint32_t>(1) << 12,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_SECONDARY_RELOAD = static_cast<std::uint32_t>(1) << 13,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_WHEN_FIRING_SECONDARY_TRIGGER_WITH_NO_AMMO = static_cast<std::uint32_t>(1) << 14,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_LOW_SECONDARY_AMMO_AND_NONE_LEFT_TO_RELOAD = static_cast<std::uint32_t>(1) << 15,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_PRIMARY_TRIGGER_READY = static_cast<std::uint32_t>(1) << 16,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_SECONDARY_TRIGGER_READY = static_cast<std::uint32_t>(1) << 17,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_FLASH_WHEN_FIRING_WITH_DEPLETED_BATTERY = static_cast<std::uint32_t>(1) << 18,
        WEAPON_HUD_INTERFACE_CROSSHAIR_TYPE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceCrosshairTypeFlagsFlag_to_string(WeaponHUDInterfaceCrosshairTypeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceCrosshairTypeFlagsFlag_to_string_pretty(WeaponHUDInterfaceCrosshairTypeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceCrosshairTypeFlagsFlag WeaponHUDInterfaceCrosshairTypeFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceNumberWeaponSpecificFlags = std::uint16_t;
    enum WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag : std::uint16_t {
        WEAPON_HUD_INTERFACE_NUMBER_WEAPON_SPECIFIC_FLAGS_FLAG_DIVIDE_NUMBER_BY_CLIP_SIZE = static_cast<std::uint16_t>(1) << 0,
        WEAPON_HUD_INTERFACE_NUMBER_WEAPON_SPECIFIC_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag_to_string(WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag_to_string_pretty(WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag WeaponHUDInterfaceNumberWeaponSpecificFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceCrosshairOverlayFlags = std::uint32_t;
    enum WeaponHUDInterfaceCrosshairOverlayFlagsFlag : std::uint32_t {
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_FLASHES_WHEN_ACTIVE = static_cast<std::uint32_t>(1) << 0,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_NOT_A_SPRITE = static_cast<std::uint32_t>(1) << 1,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_SHOW_ONLY_WHEN_ZOOMED = static_cast<std::uint32_t>(1) << 2,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_SHOW_SNIPER_DATA = static_cast<std::uint32_t>(1) << 3,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_HIDE_AREA_OUTSIDE_RETICLE = static_cast<std::uint32_t>(1) << 4,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_ONE_ZOOM_LEVEL = static_cast<std::uint32_t>(1) << 5,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_DONT_SHOW_WHEN_ZOOMED = static_cast<std::uint32_t>(1) << 6,
        WEAPON_HUD_INTERFACE_CROSSHAIR_OVERLAY_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceCrosshairOverlayFlagsFlag_to_string(WeaponHUDInterfaceCrosshairOverlayFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceCrosshairOverlayFlagsFlag_to_string_pretty(WeaponHUDInterfaceCrosshairOverlayFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceCrosshairOverlayFlagsFlag WeaponHUDInterfaceCrosshairOverlayFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceOverlayType = std::uint16_t;
    enum WeaponHUDInterfaceOverlayTypeFlag : std::uint16_t {
        WEAPON_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_FLASHING = static_cast<std::uint16_t>(1) << 0,
        WEAPON_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_EMPTY = static_cast<std::uint16_t>(1) << 1,
        WEAPON_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_RELOAD_OVERHEATING = static_cast<std::uint16_t>(1) << 2,
        WEAPON_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ON_DEFAULT = static_cast<std::uint16_t>(1) << 3,
        WEAPON_HUD_INTERFACE_OVERLAY_TYPE_FLAG_SHOW_ALWAYS = static_cast<std::uint16_t>(1) << 4,
        WEAPON_HUD_INTERFACE_OVERLAY_TYPE_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceOverlayTypeFlag_to_string(WeaponHUDInterfaceOverlayTypeFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceOverlayTypeFlag_to_string_pretty(WeaponHUDInterfaceOverlayTypeFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceOverlayTypeFlag WeaponHUDInterfaceOverlayTypeFlag_from_string(const char *value);

    using WeaponHUDInterfaceScreenEffectDefinitionMaskFlags = std::uint16_t;
    enum WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag : std::uint16_t {
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_MASK_FLAGS_FLAG_ONLY_WHEN_ZOOMED = static_cast<std::uint16_t>(1) << 0,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_MASK_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag_to_string(WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag_to_string_pretty(WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag WeaponHUDInterfaceScreenEffectDefinitionMaskFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlags = std::uint16_t;
    enum WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag : std::uint16_t {
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_NIGHT_VISION_FLAGS_FLAG_ONLY_WHEN_ZOOMED = static_cast<std::uint16_t>(1) << 0,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_NIGHT_VISION_FLAGS_FLAG_CONNECT_TO_FLASHLIGHT = static_cast<std::uint16_t>(1) << 1,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_NIGHT_VISION_FLAGS_FLAG_MASKED = static_cast<std::uint16_t>(1) << 2,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_NIGHT_VISION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag_to_string(WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag_to_string_pretty(WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlags = std::uint16_t;
    enum WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag : std::uint16_t {
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_DESATURATION_FLAGS_FLAG_ONLY_WHEN_ZOOMED = static_cast<std::uint16_t>(1) << 0,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_DESATURATION_FLAGS_FLAG_CONNECT_TO_FLASHLIGHT = static_cast<std::uint16_t>(1) << 1,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_DESATURATION_FLAGS_FLAG_ADDITIVE = static_cast<std::uint16_t>(1) << 2,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_DESATURATION_FLAGS_FLAG_MASKED = static_cast<std::uint16_t>(1) << 3,
        WEAPON_HUD_INTERFACE_SCREEN_EFFECT_DEFINITION_DESATURATION_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag_to_string(WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag_to_string_pretty(WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlagsFlag_from_string(const char *value);

    using WeaponHUDInterfaceFlags = std::uint16_t;
    enum WeaponHUDInterfaceFlagsFlag : std::uint16_t {
        WEAPON_HUD_INTERFACE_FLAGS_FLAG_USE_PARENT_HUD_FLASHING_PARAMETERS = static_cast<std::uint16_t>(1) << 0,
        WEAPON_HUD_INTERFACE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeaponHUDInterfaceFlagsFlag_to_string(WeaponHUDInterfaceFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeaponHUDInterfaceFlagsFlag_to_string_pretty(WeaponHUDInterfaceFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeaponHUDInterfaceFlagsFlag WeaponHUDInterfaceFlagsFlag_from_string(const char *value);

    using WeatherParticleSystemParticleTypeFlags = std::uint32_t;
    enum WeatherParticleSystemParticleTypeFlagsFlag : std::uint32_t {
        WEATHER_PARTICLE_SYSTEM_PARTICLE_TYPE_FLAGS_FLAG_INTERPOLATE_COLORS_IN_HSV = static_cast<std::uint32_t>(1) << 0,
        WEATHER_PARTICLE_SYSTEM_PARTICLE_TYPE_FLAGS_FLAG_ALONG_LONG_HUE_PATH = static_cast<std::uint32_t>(1) << 1,
        WEATHER_PARTICLE_SYSTEM_PARTICLE_TYPE_FLAGS_FLAG_RANDOM_ROTATION = static_cast<std::uint32_t>(1) << 2,
        WEATHER_PARTICLE_SYSTEM_PARTICLE_TYPE_FLAGS_FLAG_ENUM_COUNT
    };
    /**
     * Get the string representation of the enum.
     * @param value value of the enum
     * @return      string representation of the enum
     */
    const char *WeatherParticleSystemParticleTypeFlagsFlag_to_string(WeatherParticleSystemParticleTypeFlagsFlag value);
    /**
     * Get the pretty string representation of the enum.
     * @param value value of the enum
     * @return      pretty string representation of the enum
     */
    const char *WeatherParticleSystemParticleTypeFlagsFlag_to_string_pretty(WeatherParticleSystemParticleTypeFlagsFlag value);
    /**
     * Get the enum value from the string.
     * @param value value of the enum as a string
     * @return      value of the enum
     */
    WeatherParticleSystemParticleTypeFlagsFlag WeatherParticleSystemParticleTypeFlagsFlag_from_string(const char *value);

    ENDIAN_TEMPLATE(EndianType) struct Actor {
        EndianType<ActorFlags> flags;
        EndianType<ActorMoreFlags> more_flags;
        PAD(0xC);
        EndianType<ActorType> type;
        PAD(0x2);
        EndianType<float> max_vision_distance;
        EndianType<Angle> central_vision_angle;
        EndianType<Angle> max_vision_angle;
        PAD(0x4);
        EndianType<Angle> peripheral_vision_angle;
        EndianType<float> peripheral_distance;
        PAD(0x4);
        Vector3D<EndianType> standing_gun_offset;
        Vector3D<EndianType> crouching_gun_offset;
        EndianType<float> hearing_distance;
        EndianType<float> notice_projectile_chance;
        EndianType<float> notice_vehicle_chance;
        PAD(0x8);
        EndianType<float> combat_perception_time;
        EndianType<float> guard_perception_time;
        EndianType<float> non_combat_perception_time;
        LittleEndian<float> inverse_combat_perception_time;
        LittleEndian<float> inverse_guard_perception_time;
        LittleEndian<float> inverse_non_combat_perception_time;
        PAD(0x8);
        EndianType<float> dive_into_cover_chance;
        EndianType<float> emerge_from_cover_chance;
        EndianType<float> dive_from_grenade_chance;
        EndianType<float> pathfinding_radius;
        EndianType<float> glass_ignorance_chance;
        EndianType<float> stationary_movement_dist;
        EndianType<float> free_flying_sidestep;
        EndianType<Angle> begin_moving_angle;
        LittleEndian<float> cosine_begin_moving_angle;
        Euler2D<EndianType> maximum_aiming_deviation;
        Euler2D<EndianType> maximum_looking_deviation;
        EndianType<Angle> noncombat_look_delta_l;
        EndianType<Angle> noncombat_look_delta_r;
        EndianType<Angle> combat_look_delta_l;
        EndianType<Angle> combat_look_delta_r;
        Euler2D<EndianType> idle_aiming_range;
        Euler2D<EndianType> idle_looking_range;
        Bounds<EndianType<float>> event_look_time_modifier;
        Bounds<EndianType<float>> noncombat_idle_facing;
        Bounds<EndianType<float>> noncombat_idle_aiming;
        Bounds<EndianType<float>> noncombat_idle_looking;
        Bounds<EndianType<float>> guard_idle_facing;
        Bounds<EndianType<float>> guard_idle_aiming;
        Bounds<EndianType<float>> guard_idle_looking;
        Bounds<EndianType<float>> combat_idle_facing;
        Bounds<EndianType<float>> combat_idle_aiming;
        Bounds<EndianType<float>> combat_idle_looking;
        PAD(0x8);
        Euler2D<LittleEndian> cosine_maximum_aiming_deviation;
        Euler2D<LittleEndian> cosine_maximum_looking_deviation;
        TagDependency<EndianType> do_not_use;
        PAD(0x10C);
        TagDependency<EndianType> do_not_use_1;
        EndianType<ActorUnreachableDangerTrigger> unreachable_danger_trigger;
        EndianType<ActorUnreachableDangerTrigger> vehicle_danger_trigger;
        EndianType<ActorUnreachableDangerTrigger> player_danger_trigger;
        PAD(0x2);
        Bounds<EndianType<float>> danger_trigger_time;
        EndianType<std::int16_t> friends_killed_trigger;
        EndianType<std::int16_t> friends_retreating_trigger;
        PAD(0xC);
        Bounds<EndianType<float>> retreat_time;
        PAD(0x8);
        Bounds<EndianType<float>> cowering_time;
        EndianType<float> friend_killed_panic_chance;
        EndianType<ActorType> leader_type;
        PAD(0x2);
        EndianType<float> leader_killed_panic_chance;
        EndianType<float> panic_damage_threshold;
        EndianType<float> surprise_distance;
        PAD(0x1C);
        Bounds<EndianType<float>> hide_behind_cover_time;
        EndianType<float> hide_target_not_visible_time;
        EndianType<float> hide_shield_fraction;
        EndianType<float> attack_shield_fraction;
        EndianType<float> pursue_shield_fraction;
        PAD(0x10);
        EndianType<ActorDefensiveCrouchType> defensive_crouch_type;
        PAD(0x2);
        EndianType<float> attacking_crouch_threshold;
        EndianType<float> defending_crouch_threshold;
        EndianType<float> min_stand_time;
        EndianType<float> min_crouch_time;
        EndianType<float> defending_hide_time_modifier;
        EndianType<float> attacking_evasion_threshold;
        EndianType<float> defending_evasion_threshold;
        EndianType<float> evasion_seek_cover_chance;
        EndianType<float> evasion_delay_time;
        EndianType<float> max_seek_cover_distance;
        EndianType<float> cover_damage_threshold;
        EndianType<float> stalking_discovery_time;
        EndianType<float> stalking_max_distance;
        EndianType<Angle> stationary_facing_angle;
        EndianType<float> change_facing_stand_time;
        PAD(0x4);
        Bounds<EndianType<float>> uncover_delay_time;
        Bounds<EndianType<float>> target_search_time;
        Bounds<EndianType<float>> pursuit_position_time;
        EndianType<std::uint16_t> num_positions_coord;
        EndianType<std::uint16_t> num_positions_normal;
        PAD(0x20);
        EndianType<float> melee_attack_delay;
        EndianType<float> melee_fudge_factor;
        EndianType<float> melee_charge_time;
        Bounds<EndianType<float>> melee_leap_range;
        EndianType<float> melee_leap_velocity;
        EndianType<float> melee_leap_chance;
        EndianType<float> melee_leap_ballistic;
        EndianType<float> berserk_damage_amount;
        EndianType<float> berserk_damage_threshold;
        EndianType<float> berserk_proximity;
        EndianType<float> suicide_sensing_dist;
        EndianType<float> berserk_grenade_chance;
        PAD(0xC);
        Bounds<EndianType<float>> guard_position_time;
        Bounds<EndianType<float>> combat_position_time;
        EndianType<float> old_position_avoid_dist;
        EndianType<float> friend_avoid_dist;
        PAD(0x28);
        Bounds<EndianType<float>> noncombat_idle_speech_time;
        Bounds<EndianType<float>> combat_idle_speech_time;
        PAD(0x30);
        PAD(0x80);
        TagDependency<EndianType> do_not_use_2;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator Actor<NewEndian>() const {
            Actor<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(more_flags);
            COPY_THIS(type);
            COPY_THIS(max_vision_distance);
            COPY_THIS(central_vision_angle);
            COPY_THIS(max_vision_angle);
            COPY_THIS(peripheral_vision_angle);
            COPY_THIS(peripheral_distance);
            COPY_THIS(standing_gun_offset);
            COPY_THIS(crouching_gun_offset);
            COPY_THIS(hearing_distance);
            COPY_THIS(notice_projectile_chance);
            COPY_THIS(notice_vehicle_chance);
            COPY_THIS(combat_perception_time);
            COPY_THIS(guard_perception_time);
            COPY_THIS(non_combat_perception_time);
            COPY_THIS(inverse_combat_perception_time);
            COPY_THIS(inverse_guard_perception_time);
            COPY_THIS(inverse_non_combat_perception_time);
            COPY_THIS(dive_into_cover_chance);
            COPY_THIS(emerge_from_cover_chance);
            COPY_THIS(dive_from_grenade_chance);
            COPY_THIS(pathfinding_radius);
            COPY_THIS(glass_ignorance_chance);
            COPY_THIS(stationary_movement_dist);
            COPY_THIS(free_flying_sidestep);
            COPY_THIS(begin_moving_angle);
            COPY_THIS(cosine_begin_moving_angle);
            COPY_THIS(maximum_aiming_deviation);
            COPY_THIS(maximum_looking_deviation);
            COPY_THIS(noncombat_look_delta_l);
            COPY_THIS(noncombat_look_delta_r);
            COPY_THIS(combat_look_delta_l);
            COPY_THIS(combat_look_delta_r);
            COPY_THIS(idle_aiming_range);
            COPY_THIS(idle_looking_range);
            COPY_THIS(event_look_time_modifier);
            COPY_THIS(noncombat_idle_facing);
            COPY_THIS(noncombat_idle_aiming);
            COPY_THIS(noncombat_idle_looking);
            COPY_THIS(guard_idle_facing);
            COPY_THIS(guard_idle_aiming);
            COPY_THIS(guard_idle_looking);
            COPY_THIS(combat_idle_facing);
            COPY_THIS(combat_idle_aiming);
            COPY_THIS(combat_idle_looking);
            COPY_THIS(cosine_maximum_aiming_deviation);
            COPY_THIS(cosine_maximum_looking_deviation);
            COPY_THIS(do_not_use);
            COPY_THIS(do_not_use_1);
            COPY_THIS(unreachable_danger_trigger);
            COPY_THIS(vehicle_danger_trigger);
            COPY_THIS(player_danger_trigger);
            COPY_THIS(danger_trigger_time);
            COPY_THIS(friends_killed_trigger);
            COPY_THIS(friends_retreating_trigger);
            COPY_THIS(retreat_time);
            COPY_THIS(cowering_time);
            COPY_THIS(friend_killed_panic_chance);
            COPY_THIS(leader_type);
            COPY_THIS(leader_killed_panic_chance);
            COPY_THIS(panic_damage_threshold);
            COPY_THIS(surprise_distance);
            COPY_THIS(hide_behind_cover_time);
            COPY_THIS(hide_target_not_visible_time);
            COPY_THIS(hide_shield_fraction);
            COPY_THIS(attack_shield_fraction);
            COPY_THIS(pursue_shield_fraction);
            COPY_THIS(defensive_crouch_type);
            COPY_THIS(attacking_crouch_threshold);
            COPY_THIS(defending_crouch_threshold);
            COPY_THIS(min_stand_time);
            COPY_THIS(min_crouch_time);
            COPY_THIS(defending_hide_time_modifier);
            COPY_THIS(attacking_evasion_threshold);
            COPY_THIS(defending_evasion_threshold);
            COPY_THIS(evasion_seek_cover_chance);
            COPY_THIS(evasion_delay_time);
            COPY_THIS(max_seek_cover_distance);
            COPY_THIS(cover_damage_threshold);
            COPY_THIS(stalking_discovery_time);
            COPY_THIS(stalking_max_distance);
            COPY_THIS(stationary_facing_angle);
            COPY_THIS(change_facing_stand_time);
            COPY_THIS(uncover_delay_time);
            COPY_THIS(target_search_time);
            COPY_THIS(pursuit_position_time);
            COPY_THIS(num_positions_coord);
            COPY_THIS(num_positions_normal);
            COPY_THIS(melee_attack_delay);
            COPY_THIS(melee_fudge_factor);
            COPY_THIS(melee_charge_time);
            COPY_THIS(melee_leap_range);
            COPY_THIS(melee_leap_velocity);
            COPY_THIS(melee_leap_chance);
            COPY_THIS(melee_leap_ballistic);
            COPY_THIS(berserk_damage_amount);
            COPY_THIS(berserk_damage_threshold);
            COPY_THIS(berserk_proximity);
            COPY_THIS(suicide_sensing_dist);
            COPY_THIS(berserk_grenade_chance);
            COPY_THIS(guard_position_time);
            COPY_THIS(combat_position_time);
            COPY_THIS(old_position_avoid_dist);
            COPY_THIS(friend_avoid_dist);
            COPY_THIS(noncombat_idle_speech_time);
            COPY_THIS(combat_idle_speech_time);
            COPY_THIS(do_not_use_2);
            return copy;
        }
    };
    static_assert(sizeof(Actor<NativeEndian>) == 0x4F8);

    ENDIAN_TEMPLATE(EndianType) struct ActorVariantChangeColors {
        ColorRGB<EndianType> color_lower_bound;
        ColorRGB<EndianType> color_upper_bound;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ActorVariantChangeColors<NewEndian>() const {
            ActorVariantChangeColors<NewEndian> copy = {};
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            return copy;
        }
    };
    static_assert(sizeof(ActorVariantChangeColors<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ActorVariant {
        EndianType<ActorVariantFlags> flags;
        TagDependency<EndianType> actor_definition;
        TagDependency<EndianType> unit;
        TagDependency<EndianType> major_variant;
        EndianType<MetagameType> metagame_type;
        EndianType<MetagameClass> metagame_class;
        PAD(0x14);
        EndianType<ActorVariantMovementType> movement_type;
        PAD(0x2);
        EndianType<float> initial_crouch_chance;
        Bounds<EndianType<float>> crouch_time;
        Bounds<EndianType<float>> run_time;
        TagDependency<EndianType> weapon;
        EndianType<float> maximum_firing_distance;
        EndianType<float> rate_of_fire;
        EndianType<Angle> projectile_error;
        Bounds<EndianType<float>> first_burst_delay_time;
        EndianType<float> new_target_firing_pattern_time;
        EndianType<float> surprise_delay_time;
        EndianType<float> surprise_fire_wildly_time;
        EndianType<float> death_fire_wildly_chance;
        EndianType<float> death_fire_wildly_time;
        Bounds<EndianType<float>> desired_combat_range;
        Vector3D<EndianType> custom_stand_gun_offset;
        Vector3D<EndianType> custom_crouch_gun_offset;
        EndianType<float> target_tracking;
        EndianType<float> target_leading;
        EndianType<float> weapon_damage_modifier;
        EndianType<float> damage_per_second;
        EndianType<float> burst_origin_radius;
        EndianType<Angle> burst_origin_angle;
        Bounds<EndianType<float>> burst_return_length;
        EndianType<Angle> burst_return_angle;
        Bounds<EndianType<float>> burst_duration;
        Bounds<EndianType<float>> burst_separation;
        EndianType<Angle> burst_angular_velocity;
        PAD(0x4);
        EndianType<float> special_damage_modifier;
        EndianType<Angle> special_projectile_error;
        EndianType<float> new_target_burst_duration;
        EndianType<float> new_target_burst_separation;
        EndianType<float> new_target_rate_of_fire;
        EndianType<float> new_target_projectile_error;
        PAD(0x8);
        EndianType<float> moving_burst_duration;
        EndianType<float> moving_burst_separation;
        EndianType<float> moving_rate_of_fire;
        EndianType<float> moving_projectile_error;
        PAD(0x8);
        EndianType<float> berserk_burst_duration;
        EndianType<float> berserk_burst_separation;
        EndianType<float> berserk_rate_of_fire;
        EndianType<float> berserk_projectile_error;
        PAD(0x8);
        EndianType<float> super_ballistic_range;
        EndianType<float> bombardment_range;
        EndianType<float> modified_vision_range;
        EndianType<ActorVariantSpecialFireMode> special_fire_mode;
        EndianType<ActorVariantSpecialFireSituation> special_fire_situation;
        EndianType<float> special_fire_chance;
        EndianType<float> special_fire_delay;
        EndianType<float> melee_range;
        EndianType<float> melee_abort_range;
        Bounds<EndianType<float>> berserk_firing_ranges;
        EndianType<float> berserk_melee_range;
        EndianType<float> berserk_melee_abort_range;
        PAD(0x8);
        EndianType<GrenadeType> grenade_type;
        EndianType<ActorVariantTrajectoryType> trajectory_type;
        EndianType<ActorVariantGrenadeStimulus> grenade_stimulus;
        EndianType<std::int16_t> minimum_enemy_count;
        EndianType<float> enemy_radius;
        PAD(0x4);
        EndianType<float> grenade_velocity;
        Bounds<EndianType<float>> grenade_ranges;
        EndianType<float> collateral_damage_radius;
        EndianType<Fraction> grenade_chance;
        EndianType<float> grenade_check_time;
        EndianType<float> encounter_grenade_timeout;
        PAD(0x14);
        TagDependency<EndianType> equipment;
        Bounds<EndianType<std::int16_t>> grenade_count;
        EndianType<float> dont_drop_grenades_chance;
        Bounds<EndianType<float>> drop_weapon_loaded;
        Bounds<EndianType<std::int16_t>> drop_weapon_ammo;
        PAD(0xC);
        PAD(0x10);
        EndianType<float> body_vitality;
        EndianType<float> shield_vitality;
        EndianType<float> shield_sapping_radius;
        EndianType<Index> forced_shader_permutation;
        PAD(0x2);
        PAD(0x10);
        PAD(0xC);
        TagReflexive<EndianType, ActorVariantChangeColors> change_colors;
        ENDIAN_TEMPLATE(NewEndian) operator ActorVariant<NewEndian>() const {
            ActorVariant<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(actor_definition);
            COPY_THIS(unit);
            COPY_THIS(major_variant);
            COPY_THIS(metagame_type);
            COPY_THIS(metagame_class);
            COPY_THIS(movement_type);
            COPY_THIS(initial_crouch_chance);
            COPY_THIS(crouch_time);
            COPY_THIS(run_time);
            COPY_THIS(weapon);
            COPY_THIS(maximum_firing_distance);
            COPY_THIS(rate_of_fire);
            COPY_THIS(projectile_error);
            COPY_THIS(first_burst_delay_time);
            COPY_THIS(new_target_firing_pattern_time);
            COPY_THIS(surprise_delay_time);
            COPY_THIS(surprise_fire_wildly_time);
            COPY_THIS(death_fire_wildly_chance);
            COPY_THIS(death_fire_wildly_time);
            COPY_THIS(desired_combat_range);
            COPY_THIS(custom_stand_gun_offset);
            COPY_THIS(custom_crouch_gun_offset);
            COPY_THIS(target_tracking);
            COPY_THIS(target_leading);
            COPY_THIS(weapon_damage_modifier);
            COPY_THIS(damage_per_second);
            COPY_THIS(burst_origin_radius);
            COPY_THIS(burst_origin_angle);
            COPY_THIS(burst_return_length);
            COPY_THIS(burst_return_angle);
            COPY_THIS(burst_duration);
            COPY_THIS(burst_separation);
            COPY_THIS(burst_angular_velocity);
            COPY_THIS(special_damage_modifier);
            COPY_THIS(special_projectile_error);
            COPY_THIS(new_target_burst_duration);
            COPY_THIS(new_target_burst_separation);
            COPY_THIS(new_target_rate_of_fire);
            COPY_THIS(new_target_projectile_error);
            COPY_THIS(moving_burst_duration);
            COPY_THIS(moving_burst_separation);
            COPY_THIS(moving_rate_of_fire);
            COPY_THIS(moving_projectile_error);
            COPY_THIS(berserk_burst_duration);
            COPY_THIS(berserk_burst_separation);
            COPY_THIS(berserk_rate_of_fire);
            COPY_THIS(berserk_projectile_error);
            COPY_THIS(super_ballistic_range);
            COPY_THIS(bombardment_range);
            COPY_THIS(modified_vision_range);
            COPY_THIS(special_fire_mode);
            COPY_THIS(special_fire_situation);
            COPY_THIS(special_fire_chance);
            COPY_THIS(special_fire_delay);
            COPY_THIS(melee_range);
            COPY_THIS(melee_abort_range);
            COPY_THIS(berserk_firing_ranges);
            COPY_THIS(berserk_melee_range);
            COPY_THIS(berserk_melee_abort_range);
            COPY_THIS(grenade_type);
            COPY_THIS(trajectory_type);
            COPY_THIS(grenade_stimulus);
            COPY_THIS(minimum_enemy_count);
            COPY_THIS(enemy_radius);
            COPY_THIS(grenade_velocity);
            COPY_THIS(grenade_ranges);
            COPY_THIS(collateral_damage_radius);
            COPY_THIS(grenade_chance);
            COPY_THIS(grenade_check_time);
            COPY_THIS(encounter_grenade_timeout);
            COPY_THIS(equipment);
            COPY_THIS(grenade_count);
            COPY_THIS(dont_drop_grenades_chance);
            COPY_THIS(drop_weapon_loaded);
            COPY_THIS(drop_weapon_ammo);
            COPY_THIS(body_vitality);
            COPY_THIS(shield_vitality);
            COPY_THIS(shield_sapping_radius);
            COPY_THIS(forced_shader_permutation);
            COPY_THIS(change_colors);
            return copy;
        }
    };
    static_assert(sizeof(ActorVariant<NativeEndian>) == 0x238);

    ENDIAN_TEMPLATE(EndianType) struct AntennaVertex {
        EndianType<Fraction> spring_strength_coefficient;
        PAD(0x18);
        Euler2D<EndianType> angles;
        EndianType<float> length;
        EndianType<Index> sequence_index;
        PAD(0x2);
        ColorARGB<EndianType> color;
        ColorARGB<EndianType> lod_color;
        PAD(0x28);
        Point3D<LittleEndian> offset;
        ENDIAN_TEMPLATE(NewEndian) operator AntennaVertex<NewEndian>() const {
            AntennaVertex<NewEndian> copy = {};
            COPY_THIS(spring_strength_coefficient);
            COPY_THIS(angles);
            COPY_THIS(length);
            COPY_THIS(sequence_index);
            COPY_THIS(color);
            COPY_THIS(lod_color);
            COPY_THIS(offset);
            return copy;
        }
    };
    static_assert(sizeof(AntennaVertex<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct Antenna {
        TagString attachment_marker_name;
        TagDependency<EndianType> bitmaps;
        TagDependency<EndianType> physics;
        PAD(0x50);
        EndianType<Fraction> spring_strength_coefficient;
        EndianType<float> falloff_pixels;
        EndianType<float> cutoff_pixels;
        EndianType<float> length;
        PAD(0x24);
        TagReflexive<EndianType, AntennaVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator Antenna<NewEndian>() const {
            Antenna<NewEndian> copy = {};
            COPY_THIS(attachment_marker_name);
            COPY_THIS(bitmaps);
            COPY_THIS(physics);
            COPY_THIS(spring_strength_coefficient);
            COPY_THIS(falloff_pixels);
            COPY_THIS(cutoff_pixels);
            COPY_THIS(length);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(Antenna<NativeEndian>) == 0xD0);

    ENDIAN_TEMPLATE(EndianType) struct BipedContactPoint {
        PAD(0x20);
        TagString marker_name;
        ENDIAN_TEMPLATE(NewEndian) operator BipedContactPoint<NewEndian>() const {
            BipedContactPoint<NewEndian> copy = {};
            COPY_THIS(marker_name);
            return copy;
        }
    };
    static_assert(sizeof(BipedContactPoint<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ObjectAttachment {
        TagDependency<EndianType> type;
        TagString marker;
        EndianType<FunctionOut> primary_scale;
        EndianType<FunctionOut> secondary_scale;
        EndianType<FunctionNameNullable> change_color;
        PAD(0x2);
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ObjectAttachment<NewEndian>() const {
            ObjectAttachment<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(marker);
            COPY_THIS(primary_scale);
            COPY_THIS(secondary_scale);
            COPY_THIS(change_color);
            return copy;
        }
    };
    static_assert(sizeof(ObjectAttachment<NativeEndian>) == 0x48);

    ENDIAN_TEMPLATE(EndianType) struct ObjectWidget {
        TagDependency<EndianType> reference;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ObjectWidget<NewEndian>() const {
            ObjectWidget<NewEndian> copy = {};
            COPY_THIS(reference);
            return copy;
        }
    };
    static_assert(sizeof(ObjectWidget<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ObjectFunction {
        EndianType<ObjectFunctionFlags> flags;
        EndianType<float> period;
        EndianType<FunctionScaleBy> scale_period_by;
        EndianType<WaveFunction> function;
        EndianType<FunctionScaleBy> scale_function_by;
        EndianType<WaveFunction> wobble_function;
        EndianType<float> wobble_period;
        EndianType<float> wobble_magnitude;
        EndianType<Fraction> square_wave_threshold;
        EndianType<std::int16_t> step_count;
        EndianType<FunctionType> map_to;
        EndianType<std::int16_t> sawtooth_count;
        EndianType<FunctionScaleBy> add;
        EndianType<FunctionScaleBy> scale_result_by;
        EndianType<FunctionBoundsMode> bounds_mode;
        Bounds<EndianType<Fraction>> bounds;
        PAD(0x4);
        PAD(0x2);
        EndianType<std::int16_t> turn_off_with;
        EndianType<float> scale_by;
        PAD(0xFC);
        LittleEndian<float> inverse_bounds;
        LittleEndian<float> inverse_sawtooth;
        LittleEndian<float> inverse_step;
        LittleEndian<float> inverse_period;
        TagString usage;
        ENDIAN_TEMPLATE(NewEndian) operator ObjectFunction<NewEndian>() const {
            ObjectFunction<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(period);
            COPY_THIS(scale_period_by);
            COPY_THIS(function);
            COPY_THIS(scale_function_by);
            COPY_THIS(wobble_function);
            COPY_THIS(wobble_period);
            COPY_THIS(wobble_magnitude);
            COPY_THIS(square_wave_threshold);
            COPY_THIS(step_count);
            COPY_THIS(map_to);
            COPY_THIS(sawtooth_count);
            COPY_THIS(add);
            COPY_THIS(scale_result_by);
            COPY_THIS(bounds_mode);
            COPY_THIS(bounds);
            COPY_THIS(turn_off_with);
            COPY_THIS(scale_by);
            COPY_THIS(inverse_bounds);
            COPY_THIS(inverse_sawtooth);
            COPY_THIS(inverse_step);
            COPY_THIS(inverse_period);
            COPY_THIS(usage);
            return copy;
        }
    };
    static_assert(sizeof(ObjectFunction<NativeEndian>) == 0x168);

    ENDIAN_TEMPLATE(EndianType) struct ObjectChangeColorsPermutation {
        EndianType<float> weight;
        ColorRGB<EndianType> color_lower_bound;
        ColorRGB<EndianType> color_upper_bound;
        ENDIAN_TEMPLATE(NewEndian) operator ObjectChangeColorsPermutation<NewEndian>() const {
            ObjectChangeColorsPermutation<NewEndian> copy;
            COPY_THIS(weight);
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            return copy;
        }
    };
    static_assert(sizeof(ObjectChangeColorsPermutation<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct ObjectChangeColors {
        EndianType<FunctionScaleBy> darken_by;
        EndianType<FunctionScaleBy> scale_by;
        EndianType<ColorInterpolationFlags> flags;
        ColorRGB<EndianType> color_lower_bound;
        ColorRGB<EndianType> color_upper_bound;
        TagReflexive<EndianType, ObjectChangeColorsPermutation> permutations;
        ENDIAN_TEMPLATE(NewEndian) operator ObjectChangeColors<NewEndian>() const {
            ObjectChangeColors<NewEndian> copy;
            COPY_THIS(darken_by);
            COPY_THIS(scale_by);
            COPY_THIS(flags);
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            COPY_THIS(permutations);
            return copy;
        }
    };
    static_assert(sizeof(ObjectChangeColors<NativeEndian>) == 0x2C);

    ENDIAN_TEMPLATE(EndianType) struct PredictedResource {
        EndianType<PredictedResourceType> type;
        EndianType<Index> resource_index;
        EndianType<TagID> tag;
        ENDIAN_TEMPLATE(NewEndian) operator PredictedResource<NewEndian>() const {
            PredictedResource<NewEndian> copy;
            COPY_THIS(type);
            COPY_THIS(resource_index);
            COPY_THIS(tag);
            return copy;
        }
    };
    static_assert(sizeof(PredictedResource<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct Object {
        LittleEndian<ObjectType> object_type;
        EndianType<ObjectFlags> flags;
        EndianType<float> bounding_radius;
        Point3D<EndianType> bounding_offset;
        Point3D<EndianType> origin_offset;
        EndianType<float> acceleration_scale;
        LittleEndian<std::uint32_t> scales_change_colors;
        TagDependency<EndianType> model;
        TagDependency<EndianType> animation_graph;
        PAD(0x28);
        TagDependency<EndianType> collision_model;
        TagDependency<EndianType> physics;
        TagDependency<EndianType> modifier_shader;
        TagDependency<EndianType> creation_effect;
        PAD(0x54);
        EndianType<float> render_bounding_radius;
        EndianType<ObjectFunctionIn> a_in;
        EndianType<ObjectFunctionIn> b_in;
        EndianType<ObjectFunctionIn> c_in;
        EndianType<ObjectFunctionIn> d_in;
        PAD(0x2C);
        EndianType<std::int16_t> hud_text_message_index;
        EndianType<std::int16_t> forced_shader_permutation_index;
        TagReflexive<EndianType, ObjectAttachment> attachments;
        TagReflexive<EndianType, ObjectWidget> widgets;
        TagReflexive<EndianType, ObjectFunction> functions;
        TagReflexive<EndianType, ObjectChangeColors> change_colors;
        TagReflexive<EndianType, PredictedResource> predicted_resources;
        ENDIAN_TEMPLATE(NewEndian) operator Object<NewEndian>() const {
            Object<NewEndian> copy = {};
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Object<NativeEndian>) == 0x17C);

    ENDIAN_TEMPLATE(EndianType) struct UnitCameraTrack {
        TagDependency<EndianType> track;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator UnitCameraTrack<NewEndian>() const {
            UnitCameraTrack<NewEndian> copy = {};
            COPY_THIS(track);
            return copy;
        }
    };
    static_assert(sizeof(UnitCameraTrack<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct UnitUnitHudInterface {
        TagDependency<EndianType> hud;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator UnitUnitHudInterface<NewEndian>() const {
            UnitUnitHudInterface<NewEndian> copy = {};
            COPY_THIS(hud);
            return copy;
        }
    };
    static_assert(sizeof(UnitUnitHudInterface<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct UnitDialogueVariant {
        EndianType<std::int16_t> variant_number;
        PAD(0x2);
        PAD(0x4);
        TagDependency<EndianType> dialogue;
        ENDIAN_TEMPLATE(NewEndian) operator UnitDialogueVariant<NewEndian>() const {
            UnitDialogueVariant<NewEndian> copy = {};
            COPY_THIS(variant_number);
            COPY_THIS(dialogue);
            return copy;
        }
    };
    static_assert(sizeof(UnitDialogueVariant<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct UnitPoweredSeat {
        PAD(0x4);
        EndianType<float> driver_powerup_time;
        EndianType<float> driver_powerdown_time;
        PAD(0x38);
        ENDIAN_TEMPLATE(NewEndian) operator UnitPoweredSeat<NewEndian>() const {
            UnitPoweredSeat<NewEndian> copy = {};
            COPY_THIS(driver_powerup_time);
            COPY_THIS(driver_powerdown_time);
            return copy;
        }
    };
    static_assert(sizeof(UnitPoweredSeat<NativeEndian>) == 0x44);

    ENDIAN_TEMPLATE(EndianType) struct UnitWeapon {
        TagDependency<EndianType> weapon;
        PAD(0x14);
        ENDIAN_TEMPLATE(NewEndian) operator UnitWeapon<NewEndian>() const {
            UnitWeapon<NewEndian> copy = {};
            COPY_THIS(weapon);
            return copy;
        }
    };
    static_assert(sizeof(UnitWeapon<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct UnitSeat {
        EndianType<UnitSeatFlags> flags;
        TagString label;
        TagString marker_name;
        PAD(0x20);
        Vector3D<EndianType> acceleration_scale;
        PAD(0xC);
        EndianType<float> yaw_rate;
        EndianType<float> pitch_rate;
        TagString camera_marker_name;
        TagString camera_submerged_marker_name;
        EndianType<Angle> pitch_auto_level;
        Bounds<EndianType<Angle>> pitch_range;
        TagReflexive<EndianType, UnitCameraTrack> camera_tracks;
        TagReflexive<EndianType, UnitUnitHudInterface> unit_hud_interface;
        PAD(0x4);
        EndianType<Index> hud_text_message_index;
        PAD(0x2);
        EndianType<Angle> yaw_minimum;
        EndianType<Angle> yaw_maximum;
        TagDependency<EndianType> built_in_gunner;
        PAD(0x14);
        ENDIAN_TEMPLATE(NewEndian) operator UnitSeat<NewEndian>() const {
            UnitSeat<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(label);
            COPY_THIS(marker_name);
            COPY_THIS(acceleration_scale);
            COPY_THIS(yaw_rate);
            COPY_THIS(pitch_rate);
            COPY_THIS(camera_marker_name);
            COPY_THIS(camera_submerged_marker_name);
            COPY_THIS(pitch_auto_level);
            COPY_THIS(pitch_range);
            COPY_THIS(camera_tracks);
            COPY_THIS(unit_hud_interface);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(yaw_minimum);
            COPY_THIS(yaw_maximum);
            COPY_THIS(built_in_gunner);
            return copy;
        }
    };
    static_assert(sizeof(UnitSeat<NativeEndian>) == 0x11C);

    ENDIAN_TEMPLATE(EndianType) struct Unit : Object<EndianType> {
        EndianType<UnitFlags> unit_flags;
        EndianType<UnitDefaultTeam> default_team;
        EndianType<ObjectNoise> constant_sound_volume;
        EndianType<float> rider_damage_fraction;
        TagDependency<EndianType> integrated_light_toggle;
        EndianType<UnitFunctionIn> unit_a_in;
        EndianType<UnitFunctionIn> unit_b_in;
        EndianType<UnitFunctionIn> unit_c_in;
        EndianType<UnitFunctionIn> unit_d_in;
        EndianType<Angle> camera_field_of_view;
        EndianType<float> camera_stiffness;
        TagString camera_marker_name;
        TagString camera_submerged_marker_name;
        EndianType<Angle> pitch_auto_level;
        Bounds<EndianType<Angle>> pitch_range;
        TagReflexive<EndianType, UnitCameraTrack> camera_tracks;
        Point3D<EndianType> seat_acceleration_scale;
        PAD(0xC);
        EndianType<float> soft_ping_threshold;
        EndianType<float> soft_ping_interrupt_time;
        EndianType<float> hard_ping_threshold;
        EndianType<float> hard_ping_interrupt_time;
        EndianType<float> hard_death_threshold;
        EndianType<float> feign_death_threshold;
        EndianType<float> feign_death_time;
        EndianType<float> distance_of_evade_anim;
        EndianType<float> distance_of_dive_anim;
        PAD(0x4);
        EndianType<float> stunned_movement_threshold;
        EndianType<float> feign_death_chance;
        EndianType<float> feign_repeat_chance;
        TagDependency<EndianType> spawned_actor;
        Bounds<EndianType<std::int16_t>> spawned_actor_count;
        EndianType<float> spawned_velocity;
        EndianType<Angle> aiming_velocity_maximum;
        EndianType<Angle> aiming_acceleration_maximum;
        EndianType<Fraction> casual_aiming_modifier;
        EndianType<Angle> looking_velocity_maximum;
        EndianType<Angle> looking_acceleration_maximum;
        PAD(0x8);
        EndianType<float> ai_vehicle_radius;
        EndianType<float> ai_danger_radius;
        TagDependency<EndianType> melee_damage;
        EndianType<UnitMotionSensorBlipSize> motion_sensor_blip_size;
        PAD(0x2);
        EndianType<MetagameType> metagame_type;
        EndianType<MetagameClass> metagame_class;
        PAD(0x8);
        TagReflexive<EndianType, UnitUnitHudInterface> new_hud_interfaces;
        TagReflexive<EndianType, UnitDialogueVariant> dialogue_variants;
        EndianType<float> grenade_velocity;
        EndianType<GrenadeType> grenade_type;
        EndianType<std::int16_t> grenade_count;
        LittleEndian<std::int16_t> soft_ping_interrupt_ticks;
        LittleEndian<std::int16_t> hard_ping_interrupt_ticks;
        TagReflexive<EndianType, UnitPoweredSeat> powered_seats;
        TagReflexive<EndianType, UnitWeapon> weapons;
        TagReflexive<EndianType, UnitSeat> seats;
        ENDIAN_TEMPLATE(NewEndian) operator Unit<NewEndian>() const {
            Unit<NewEndian> copy = {};
            COPY_THIS(unit_flags);
            COPY_THIS(default_team);
            COPY_THIS(constant_sound_volume);
            COPY_THIS(rider_damage_fraction);
            COPY_THIS(integrated_light_toggle);
            COPY_THIS(unit_a_in);
            COPY_THIS(unit_b_in);
            COPY_THIS(unit_c_in);
            COPY_THIS(unit_d_in);
            COPY_THIS(camera_field_of_view);
            COPY_THIS(camera_stiffness);
            COPY_THIS(camera_marker_name);
            COPY_THIS(camera_submerged_marker_name);
            COPY_THIS(pitch_auto_level);
            COPY_THIS(pitch_range);
            COPY_THIS(camera_tracks);
            COPY_THIS(seat_acceleration_scale);
            COPY_THIS(soft_ping_threshold);
            COPY_THIS(soft_ping_interrupt_time);
            COPY_THIS(hard_ping_threshold);
            COPY_THIS(hard_ping_interrupt_time);
            COPY_THIS(hard_death_threshold);
            COPY_THIS(feign_death_threshold);
            COPY_THIS(feign_death_time);
            COPY_THIS(distance_of_evade_anim);
            COPY_THIS(distance_of_dive_anim);
            COPY_THIS(stunned_movement_threshold);
            COPY_THIS(feign_death_chance);
            COPY_THIS(feign_repeat_chance);
            COPY_THIS(spawned_actor);
            COPY_THIS(spawned_actor_count);
            COPY_THIS(spawned_velocity);
            COPY_THIS(aiming_velocity_maximum);
            COPY_THIS(aiming_acceleration_maximum);
            COPY_THIS(casual_aiming_modifier);
            COPY_THIS(looking_velocity_maximum);
            COPY_THIS(looking_acceleration_maximum);
            COPY_THIS(ai_vehicle_radius);
            COPY_THIS(ai_danger_radius);
            COPY_THIS(melee_damage);
            COPY_THIS(motion_sensor_blip_size);
            COPY_THIS(metagame_type);
            COPY_THIS(metagame_class);
            COPY_THIS(new_hud_interfaces);
            COPY_THIS(dialogue_variants);
            COPY_THIS(grenade_velocity);
            COPY_THIS(grenade_type);
            COPY_THIS(grenade_count);
            COPY_THIS(soft_ping_interrupt_ticks);
            COPY_THIS(hard_ping_interrupt_ticks);
            COPY_THIS(powered_seats);
            COPY_THIS(weapons);
            COPY_THIS(seats);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Unit<NativeEndian>) == 0x2F0);

    ENDIAN_TEMPLATE(EndianType) struct Biped : Unit<EndianType> {
        EndianType<Angle> moving_turning_speed;
        EndianType<BipedFlags> biped_flags;
        EndianType<Angle> stationary_turning_threshold;
        PAD(0x10);
        EndianType<BipedFunctionIn> biped_a_in;
        EndianType<BipedFunctionIn> biped_b_in;
        EndianType<BipedFunctionIn> biped_c_in;
        EndianType<BipedFunctionIn> biped_d_in;
        TagDependency<EndianType> dont_use;
        EndianType<Angle> bank_angle;
        EndianType<float> bank_apply_time;
        EndianType<float> bank_decay_time;
        EndianType<float> pitch_ratio;
        EndianType<float> max_velocity;
        EndianType<float> max_sidestep_velocity;
        EndianType<float> acceleration;
        EndianType<float> deceleration;
        EndianType<Angle> angular_velocity_maximum;
        EndianType<Angle> angular_acceleration_maximum;
        EndianType<float> crouch_velocity_modifier;
        PAD(0x8);
        EndianType<Angle> maximum_slope_angle;
        EndianType<Angle> downhill_falloff_angle;
        EndianType<Angle> downhill_cutoff_angle;
        EndianType<float> downhill_velocity_scale;
        EndianType<Angle> uphill_falloff_angle;
        EndianType<Angle> uphill_cutoff_angle;
        EndianType<float> uphill_velocity_scale;
        PAD(0x18);
        TagDependency<EndianType> footsteps;
        PAD(0x18);
        EndianType<float> jump_velocity;
        PAD(0x1C);
        EndianType<float> maximum_soft_landing_time;
        EndianType<float> maximum_hard_landing_time;
        EndianType<float> minimum_soft_landing_velocity;
        EndianType<float> minimum_hard_landing_velocity;
        EndianType<float> maximum_hard_landing_velocity;
        EndianType<float> death_hard_landing_velocity;
        PAD(0x14);
        EndianType<float> standing_camera_height;
        EndianType<float> crouching_camera_height;
        EndianType<float> crouch_transition_time;
        PAD(0x18);
        EndianType<float> standing_collision_height;
        EndianType<float> crouching_collision_height;
        EndianType<float> collision_radius;
        PAD(0x28);
        EndianType<float> autoaim_width;
        PAD(0x6C);
        LittleEndian<float> cosine_stationary_turning_threshold;
        LittleEndian<float> crouch_camera_velocity;
        LittleEndian<float> cosine_maximum_slope_angle;
        LittleEndian<float> negative_sine_downhill_falloff_angle;
        LittleEndian<float> negative_sine_downhill_cutoff_angle;
        LittleEndian<float> sine_uphill_falloff_angle;
        LittleEndian<float> sine_uphill_cutoff_angle;
        LittleEndian<Index> pelvis_model_node_index;
        LittleEndian<Index> head_model_node_index;
        TagReflexive<EndianType, BipedContactPoint> contact_point;
        ENDIAN_TEMPLATE(NewEndian) operator Biped<NewEndian>() const {
            Biped<NewEndian> copy = {};
            COPY_THIS(moving_turning_speed);
            COPY_THIS(biped_flags);
            COPY_THIS(stationary_turning_threshold);
            COPY_THIS(biped_a_in);
            COPY_THIS(biped_b_in);
            COPY_THIS(biped_c_in);
            COPY_THIS(biped_d_in);
            COPY_THIS(dont_use);
            COPY_THIS(bank_angle);
            COPY_THIS(bank_apply_time);
            COPY_THIS(bank_decay_time);
            COPY_THIS(pitch_ratio);
            COPY_THIS(max_velocity);
            COPY_THIS(max_sidestep_velocity);
            COPY_THIS(acceleration);
            COPY_THIS(deceleration);
            COPY_THIS(angular_velocity_maximum);
            COPY_THIS(angular_acceleration_maximum);
            COPY_THIS(crouch_velocity_modifier);
            COPY_THIS(maximum_slope_angle);
            COPY_THIS(downhill_falloff_angle);
            COPY_THIS(downhill_cutoff_angle);
            COPY_THIS(downhill_velocity_scale);
            COPY_THIS(uphill_falloff_angle);
            COPY_THIS(uphill_cutoff_angle);
            COPY_THIS(uphill_velocity_scale);
            COPY_THIS(footsteps);
            COPY_THIS(jump_velocity);
            COPY_THIS(maximum_soft_landing_time);
            COPY_THIS(maximum_hard_landing_time);
            COPY_THIS(minimum_soft_landing_velocity);
            COPY_THIS(minimum_hard_landing_velocity);
            COPY_THIS(maximum_hard_landing_velocity);
            COPY_THIS(death_hard_landing_velocity);
            COPY_THIS(standing_camera_height);
            COPY_THIS(crouching_camera_height);
            COPY_THIS(crouch_transition_time);
            COPY_THIS(standing_collision_height);
            COPY_THIS(crouching_collision_height);
            COPY_THIS(collision_radius);
            COPY_THIS(autoaim_width);
            COPY_THIS(cosine_stationary_turning_threshold);
            COPY_THIS(crouch_camera_velocity);
            COPY_THIS(cosine_maximum_slope_angle);
            COPY_THIS(negative_sine_downhill_falloff_angle);
            COPY_THIS(negative_sine_downhill_cutoff_angle);
            COPY_THIS(sine_uphill_falloff_angle);
            COPY_THIS(sine_uphill_cutoff_angle);
            COPY_THIS(pelvis_model_node_index);
            COPY_THIS(head_model_node_index);
            COPY_THIS(contact_point);
            COPY_THIS(unit_flags);
            COPY_THIS(default_team);
            COPY_THIS(constant_sound_volume);
            COPY_THIS(rider_damage_fraction);
            COPY_THIS(integrated_light_toggle);
            COPY_THIS(unit_a_in);
            COPY_THIS(unit_b_in);
            COPY_THIS(unit_c_in);
            COPY_THIS(unit_d_in);
            COPY_THIS(camera_field_of_view);
            COPY_THIS(camera_stiffness);
            COPY_THIS(camera_marker_name);
            COPY_THIS(camera_submerged_marker_name);
            COPY_THIS(pitch_auto_level);
            COPY_THIS(pitch_range);
            COPY_THIS(camera_tracks);
            COPY_THIS(seat_acceleration_scale);
            COPY_THIS(soft_ping_threshold);
            COPY_THIS(soft_ping_interrupt_time);
            COPY_THIS(hard_ping_threshold);
            COPY_THIS(hard_ping_interrupt_time);
            COPY_THIS(hard_death_threshold);
            COPY_THIS(feign_death_threshold);
            COPY_THIS(feign_death_time);
            COPY_THIS(distance_of_evade_anim);
            COPY_THIS(distance_of_dive_anim);
            COPY_THIS(stunned_movement_threshold);
            COPY_THIS(feign_death_chance);
            COPY_THIS(feign_repeat_chance);
            COPY_THIS(spawned_actor);
            COPY_THIS(spawned_actor_count);
            COPY_THIS(spawned_velocity);
            COPY_THIS(aiming_velocity_maximum);
            COPY_THIS(aiming_acceleration_maximum);
            COPY_THIS(casual_aiming_modifier);
            COPY_THIS(looking_velocity_maximum);
            COPY_THIS(looking_acceleration_maximum);
            COPY_THIS(ai_vehicle_radius);
            COPY_THIS(ai_danger_radius);
            COPY_THIS(melee_damage);
            COPY_THIS(motion_sensor_blip_size);
            COPY_THIS(metagame_type);
            COPY_THIS(metagame_class);
            COPY_THIS(new_hud_interfaces);
            COPY_THIS(dialogue_variants);
            COPY_THIS(grenade_velocity);
            COPY_THIS(grenade_type);
            COPY_THIS(grenade_count);
            COPY_THIS(soft_ping_interrupt_ticks);
            COPY_THIS(hard_ping_interrupt_ticks);
            COPY_THIS(powered_seats);
            COPY_THIS(weapons);
            COPY_THIS(seats);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Biped<NativeEndian>) == 0x4F4);

    ENDIAN_TEMPLATE(EndianType) struct BitmapGroupSprite {
        EndianType<Index> bitmap_index;
        PAD(0x2);
        PAD(0x4);
        EndianType<float> left;
        EndianType<float> right;
        EndianType<float> top;
        EndianType<float> bottom;
        Point2D<EndianType> registration_point;
        ENDIAN_TEMPLATE(NewEndian) operator BitmapGroupSprite<NewEndian>() const {
            BitmapGroupSprite<NewEndian> copy = {};
            COPY_THIS(bitmap_index);
            COPY_THIS(left);
            COPY_THIS(right);
            COPY_THIS(top);
            COPY_THIS(bottom);
            COPY_THIS(registration_point);
            return copy;
        }
    };
    static_assert(sizeof(BitmapGroupSprite<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct BitmapGroupSequence {
        TagString name;
        EndianType<Index> first_bitmap_index;
        EndianType<std::uint16_t> bitmap_count;
        PAD(0x10);
        TagReflexive<EndianType, BitmapGroupSprite> sprites;
        ENDIAN_TEMPLATE(NewEndian) operator BitmapGroupSequence<NewEndian>() const {
            BitmapGroupSequence<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(first_bitmap_index);
            COPY_THIS(bitmap_count);
            COPY_THIS(sprites);
            return copy;
        }
    };
    static_assert(sizeof(BitmapGroupSequence<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct BitmapData {
        EndianType<TagFourCC> bitmap_class;
        EndianType<std::uint16_t> width;
        EndianType<std::uint16_t> height;
        EndianType<std::uint16_t> depth;
        EndianType<BitmapDataType> type;
        EndianType<BitmapDataFormat> format;
        EndianType<BitmapDataFlags> flags;
        Point2DInt<EndianType> registration_point;
        EndianType<std::uint16_t> mipmap_count;
        PAD(0x2);
        EndianType<std::uint32_t> pixel_data_offset;
        LittleEndian<std::uint32_t> pixel_data_size;
        LittleEndian<TagID> bitmap_tag_id;
        LittleEndian<Pointer> pointer;
        PAD(0x4);
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator BitmapData<NewEndian>() const {
            BitmapData<NewEndian> copy = {};
            COPY_THIS(bitmap_class);
            COPY_THIS(width);
            COPY_THIS(height);
            COPY_THIS(depth);
            COPY_THIS(type);
            COPY_THIS(format);
            COPY_THIS(flags);
            COPY_THIS(registration_point);
            COPY_THIS(mipmap_count);
            COPY_THIS(pixel_data_offset);
            COPY_THIS(pixel_data_size);
            COPY_THIS(bitmap_tag_id);
            COPY_THIS(pointer);
            return copy;
        }
    };
    static_assert(sizeof(BitmapData<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct Bitmap {
        EndianType<BitmapType> type;
        EndianType<BitmapFormat> encoding_format;
        EndianType<BitmapUsage> usage;
        EndianType<BitmapFlags> flags;
        EndianType<Fraction> detail_fade_factor;
        EndianType<Fraction> sharpen_amount;
        EndianType<Fraction> bump_height;
        EndianType<BitmapSpriteBudgetSize> sprite_budget_size;
        EndianType<std::uint16_t> sprite_budget_count;
        EndianType<std::uint16_t> color_plate_width;
        EndianType<std::uint16_t> color_plate_height;
        TagDataOffset<EndianType> compressed_color_plate_data;
        TagDataOffset<EndianType> processed_pixel_data;
        EndianType<float> blur_filter_size;
        EndianType<float> alpha_bias;
        EndianType<std::uint16_t> mipmap_count;
        EndianType<BitmapSpriteUsage> sprite_usage;
        EndianType<std::uint16_t> sprite_spacing;
        PAD(0x2);
        TagReflexive<EndianType, BitmapGroupSequence> bitmap_group_sequence;
        TagReflexive<EndianType, BitmapData> bitmap_data;
        ENDIAN_TEMPLATE(NewEndian) operator Bitmap<NewEndian>() const {
            Bitmap<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(encoding_format);
            COPY_THIS(usage);
            COPY_THIS(flags);
            COPY_THIS(detail_fade_factor);
            COPY_THIS(sharpen_amount);
            COPY_THIS(bump_height);
            COPY_THIS(sprite_budget_size);
            COPY_THIS(sprite_budget_count);
            COPY_THIS(color_plate_width);
            COPY_THIS(color_plate_height);
            COPY_THIS(compressed_color_plate_data);
            COPY_THIS(processed_pixel_data);
            COPY_THIS(blur_filter_size);
            COPY_THIS(alpha_bias);
            COPY_THIS(mipmap_count);
            COPY_THIS(sprite_usage);
            COPY_THIS(sprite_spacing);
            COPY_THIS(bitmap_group_sequence);
            COPY_THIS(bitmap_data);
            return copy;
        }
    };
    static_assert(sizeof(Bitmap<NativeEndian>) == 0x6C);

    ENDIAN_TEMPLATE(EndianType) struct CameraTrackControlPoint {
        Point3D<EndianType> position;
        Quaternion<EndianType> orientation;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator CameraTrackControlPoint<NewEndian>() const {
            CameraTrackControlPoint<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(orientation);
            return copy;
        }
    };
    static_assert(sizeof(CameraTrackControlPoint<NativeEndian>) == 0x3C);

    ENDIAN_TEMPLATE(EndianType) struct CameraTrack {
        EndianType<IsUnusedFlag> flags;
        TagReflexive<EndianType, CameraTrackControlPoint> control_points;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator CameraTrack<NewEndian>() const {
            CameraTrack<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(control_points);
            return copy;
        }
    };
    static_assert(sizeof(CameraTrack<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ColorTableColor {
        TagString name;
        ColorARGB<EndianType> color;
        ENDIAN_TEMPLATE(NewEndian) operator ColorTableColor<NewEndian>() const {
            ColorTableColor<NewEndian> copy;
            COPY_THIS(name);
            COPY_THIS(color);
            return copy;
        }
    };
    static_assert(sizeof(ColorTableColor<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ColorTable {
        TagReflexive<EndianType, ColorTableColor> colors;
        ENDIAN_TEMPLATE(NewEndian) operator ColorTable<NewEndian>() const {
            ColorTable<NewEndian> copy;
            COPY_THIS(colors);
            return copy;
        }
    };
    static_assert(sizeof(ColorTable<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ContinuousDamageEffect {
        Bounds<EndianType<float>> radius;
        EndianType<float> cutoff_scale;
        PAD(0x18);
        EndianType<float> low_frequency_vibrate_frequency;
        EndianType<float> high_frequency_vibrate_frequency;
        PAD(0x18);
        EndianType<float> camera_shaking_random_translation;
        EndianType<Angle> camera_shaking_random_rotation;
        PAD(0xC);
        EndianType<WaveFunction> camera_shaking_wobble_function;
        PAD(0x2);
        EndianType<float> camera_shaking_wobble_period;
        EndianType<float> camera_shaking_wobble_weight;
        PAD(0x4);
        PAD(0x14);
        PAD(0x8);
        PAD(0xA0);
        EndianType<DamageEffectSideEffect> damage_side_effect;
        EndianType<DamageEffectCategory> damage_category;
        EndianType<DamageEffectDamageFlags> damage_flags;
        PAD(0x4);
        EndianType<float> damage_lower_bound;
        Bounds<EndianType<float>> damage_upper_bound;
        EndianType<float> damage_vehicle_passthrough_penalty;
        PAD(0x4);
        EndianType<float> damage_stun;
        EndianType<float> damage_maximum_stun;
        EndianType<float> damage_stun_time;
        PAD(0x4);
        Vector3D<EndianType> damage_instantaneous_acceleration;
        EndianType<float> dirt;
        EndianType<float> sand;
        EndianType<float> stone;
        EndianType<float> snow;
        EndianType<float> wood;
        EndianType<float> metal_hollow;
        EndianType<float> metal_thin;
        EndianType<float> metal_thick;
        EndianType<float> rubber;
        EndianType<float> glass;
        EndianType<float> force_field;
        EndianType<float> grunt;
        EndianType<float> hunter_armor;
        EndianType<float> hunter_skin;
        EndianType<float> elite;
        EndianType<float> jackal;
        EndianType<float> jackal_energy_shield;
        EndianType<float> engineer_skin;
        EndianType<float> engineer_force_field;
        EndianType<float> flood_combat_form;
        EndianType<float> flood_carrier_form;
        EndianType<float> cyborg_armor;
        EndianType<float> cyborg_energy_shield;
        EndianType<float> human_armor;
        EndianType<float> human_skin;
        EndianType<float> sentinel;
        EndianType<float> monitor;
        EndianType<float> plastic;
        EndianType<float> water;
        EndianType<float> leaves;
        EndianType<float> elite_energy_shield;
        EndianType<float> ice;
        EndianType<float> hunter_shield;
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator ContinuousDamageEffect<NewEndian>() const {
            ContinuousDamageEffect<NewEndian> copy = {};
            COPY_THIS(radius);
            COPY_THIS(cutoff_scale);
            COPY_THIS(low_frequency_vibrate_frequency);
            COPY_THIS(high_frequency_vibrate_frequency);
            COPY_THIS(camera_shaking_random_translation);
            COPY_THIS(camera_shaking_random_rotation);
            COPY_THIS(camera_shaking_wobble_function);
            COPY_THIS(camera_shaking_wobble_period);
            COPY_THIS(camera_shaking_wobble_weight);
            COPY_THIS(damage_side_effect);
            COPY_THIS(damage_category);
            COPY_THIS(damage_flags);
            COPY_THIS(damage_lower_bound);
            COPY_THIS(damage_upper_bound);
            COPY_THIS(damage_vehicle_passthrough_penalty);
            COPY_THIS(damage_stun);
            COPY_THIS(damage_maximum_stun);
            COPY_THIS(damage_stun_time);
            COPY_THIS(damage_instantaneous_acceleration);
            COPY_THIS(dirt);
            COPY_THIS(sand);
            COPY_THIS(stone);
            COPY_THIS(snow);
            COPY_THIS(wood);
            COPY_THIS(metal_hollow);
            COPY_THIS(metal_thin);
            COPY_THIS(metal_thick);
            COPY_THIS(rubber);
            COPY_THIS(glass);
            COPY_THIS(force_field);
            COPY_THIS(grunt);
            COPY_THIS(hunter_armor);
            COPY_THIS(hunter_skin);
            COPY_THIS(elite);
            COPY_THIS(jackal);
            COPY_THIS(jackal_energy_shield);
            COPY_THIS(engineer_skin);
            COPY_THIS(engineer_force_field);
            COPY_THIS(flood_combat_form);
            COPY_THIS(flood_carrier_form);
            COPY_THIS(cyborg_armor);
            COPY_THIS(cyborg_energy_shield);
            COPY_THIS(human_armor);
            COPY_THIS(human_skin);
            COPY_THIS(sentinel);
            COPY_THIS(monitor);
            COPY_THIS(plastic);
            COPY_THIS(water);
            COPY_THIS(leaves);
            COPY_THIS(elite_energy_shield);
            COPY_THIS(ice);
            COPY_THIS(hunter_shield);
            return copy;
        }
    };
    static_assert(sizeof(ContinuousDamageEffect<NativeEndian>) == 0x200);

    ENDIAN_TEMPLATE(EndianType) struct ContrailPointState {
        Bounds<EndianType<float>> duration;
        Bounds<EndianType<float>> transition_duration;
        TagDependency<EndianType> physics;
        PAD(0x20);
        EndianType<float> width;
        ColorARGB<EndianType> color_lower_bound;
        ColorARGB<EndianType> color_upper_bound;
        EndianType<ContrailPointStateScaleFlags> scale_flags;
        ENDIAN_TEMPLATE(NewEndian) operator ContrailPointState<NewEndian>() const {
            ContrailPointState<NewEndian> copy = {};
            COPY_THIS(duration);
            COPY_THIS(transition_duration);
            COPY_THIS(physics);
            COPY_THIS(width);
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            COPY_THIS(scale_flags);
            return copy;
        }
    };
    static_assert(sizeof(ContrailPointState<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct Contrail {
        EndianType<ContrailFlags> flags;
        EndianType<ContrailScaleFlags> scale_flags;
        EndianType<float> point_generation_rate;
        Bounds<EndianType<float>> point_velocity;
        EndianType<Angle> point_velocity_cone_angle;
        EndianType<Fraction> inherited_velocity_fraction;
        EndianType<ContrailRenderType> render_type;
        PAD(0x2);
        EndianType<float> texture_repeats_u;
        EndianType<float> texture_repeats_v;
        EndianType<float> texture_animation_u;
        EndianType<float> texture_animation_v;
        EndianType<float> animation_rate;
        TagDependency<EndianType> bitmap;
        EndianType<Index> first_sequence_index;
        EndianType<std::int16_t> sequence_count;
        PAD(0x40);
        PAD(0x24);
        EndianType<std::uint32_t> unknown_int;
        EndianType<ParticleShaderFlags> shader_flags;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<IsUnfilteredFlag> map_flags;
        PAD(0xC);
        PAD(0x10);
        TagDependency<EndianType> secondary_bitmap;
        EndianType<ParticleAnchor> anchor;
        EndianType<IsUnfilteredFlag> secondary_map_flags;
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<Angle> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        PAD(0x4);
        EndianType<float> zsprite_radius_scale;
        PAD(0x14);
        TagReflexive<EndianType, ContrailPointState> point_states;
        ENDIAN_TEMPLATE(NewEndian) operator Contrail<NewEndian>() const {
            Contrail<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(scale_flags);
            COPY_THIS(point_generation_rate);
            COPY_THIS(point_velocity);
            COPY_THIS(point_velocity_cone_angle);
            COPY_THIS(inherited_velocity_fraction);
            COPY_THIS(render_type);
            COPY_THIS(texture_repeats_u);
            COPY_THIS(texture_repeats_v);
            COPY_THIS(texture_animation_u);
            COPY_THIS(texture_animation_v);
            COPY_THIS(animation_rate);
            COPY_THIS(bitmap);
            COPY_THIS(first_sequence_index);
            COPY_THIS(sequence_count);
            COPY_THIS(unknown_int);
            COPY_THIS(shader_flags);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(map_flags);
            COPY_THIS(secondary_bitmap);
            COPY_THIS(anchor);
            COPY_THIS(secondary_map_flags);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            COPY_THIS(zsprite_radius_scale);
            COPY_THIS(point_states);
            return copy;
        }
    };
    static_assert(sizeof(Contrail<NativeEndian>) == 0x144);

    ENDIAN_TEMPLATE(EndianType) struct DamageEffect {
        Bounds<EndianType<float>> radius;
        EndianType<float> cutoff_scale;
        EndianType<DamageEffectFlags> flags;
        PAD(0x10);
        PAD(0x4);
        EndianType<DamageEffectScreenFlashType> type;
        EndianType<DamageEffectScreenFlashPriority> priority;
        PAD(0x8);
        PAD(0x4);
        EndianType<float> duration;
        EndianType<FunctionType> fade_function;
        PAD(0x2);
        PAD(0x4);
        PAD(0x4);
        EndianType<float> maximum_intensity;
        PAD(0x4);
        ColorARGB<EndianType> color;
        EndianType<float> low_frequency_vibrate_frequency;
        EndianType<float> low_frequency_vibrate_duration;
        EndianType<FunctionType> low_frequency_vibrate_fade_function;
        PAD(0x2);
        PAD(0x8);
        EndianType<float> high_frequency_vibrate_frequency;
        EndianType<float> high_frequency_vibrate_duration;
        EndianType<FunctionType> high_frequency_vibrate_fade_function;
        PAD(0x2);
        PAD(0x4);
        PAD(0x10);
        PAD(0x8);
        EndianType<float> temporary_camera_impulse_duration;
        EndianType<FunctionType> temporary_camera_impulse_fade_function;
        PAD(0x2);
        EndianType<Angle> temporary_camera_impulse_rotation;
        EndianType<float> temporary_camera_impulse_pushback;
        Bounds<EndianType<float>> jitter;
        PAD(0x8);
        EndianType<Angle> permanent_camera_impulse_angle;
        PAD(0x4);
        PAD(0xC);
        EndianType<float> camera_shaking_duration;
        EndianType<FunctionType> camera_shaking_falloff_function;
        PAD(0x2);
        EndianType<float> camera_shaking_random_translation;
        EndianType<Angle> camera_shaking_random_rotation;
        PAD(0x4);
        PAD(0x8);
        EndianType<WaveFunction> camera_shaking_wobble_function;
        PAD(0x2);
        EndianType<float> camera_shaking_wobble_period;
        EndianType<float> camera_shaking_wobble_weight;
        PAD(0xC);
        PAD(0x10);
        PAD(0x4);
        TagDependency<EndianType> sound;
        PAD(0x6C);
        PAD(0x4);
        EndianType<float> breaking_effect_forward_velocity;
        EndianType<float> breaking_effect_forward_radius;
        EndianType<float> breaking_effect_forward_exponent;
        PAD(0x4);
        PAD(0x8);
        EndianType<float> breaking_effect_outward_velocity;
        EndianType<float> breaking_effect_outward_radius;
        EndianType<float> breaking_effect_outward_exponent;
        PAD(0x8);
        PAD(0x4);
        EndianType<DamageEffectSideEffect> damage_side_effect;
        EndianType<DamageEffectCategory> damage_category;
        EndianType<DamageEffectDamageFlags> damage_flags;
        EndianType<float> damage_aoe_core_radius;
        EndianType<float> damage_lower_bound;
        Bounds<EndianType<float>> damage_upper_bound;
        EndianType<float> damage_vehicle_passthrough_penalty;
        EndianType<float> damage_active_camouflage_damage;
        EndianType<float> damage_stun;
        EndianType<float> damage_maximum_stun;
        EndianType<float> damage_stun_time;
        PAD(0x4);
        Vector3D<EndianType> damage_instantaneous_acceleration;
        EndianType<float> dirt;
        EndianType<float> sand;
        EndianType<float> stone;
        EndianType<float> snow;
        EndianType<float> wood;
        EndianType<float> metal_hollow;
        EndianType<float> metal_thin;
        EndianType<float> metal_thick;
        EndianType<float> rubber;
        EndianType<float> glass;
        EndianType<float> force_field;
        EndianType<float> grunt;
        EndianType<float> hunter_armor;
        EndianType<float> hunter_skin;
        EndianType<float> elite;
        EndianType<float> jackal;
        EndianType<float> jackal_energy_shield;
        EndianType<float> engineer_skin;
        EndianType<float> engineer_force_field;
        EndianType<float> flood_combat_form;
        EndianType<float> flood_carrier_form;
        EndianType<float> cyborg_armor;
        EndianType<float> cyborg_energy_shield;
        EndianType<float> human_armor;
        EndianType<float> human_skin;
        EndianType<float> sentinel;
        EndianType<float> monitor;
        EndianType<float> plastic;
        EndianType<float> water;
        EndianType<float> leaves;
        EndianType<float> elite_energy_shield;
        EndianType<float> ice;
        EndianType<float> hunter_shield;
        PAD(0xC);
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator DamageEffect<NewEndian>() const {
            DamageEffect<NewEndian> copy = {};
            COPY_THIS(radius);
            COPY_THIS(cutoff_scale);
            COPY_THIS(flags);
            COPY_THIS(type);
            COPY_THIS(priority);
            COPY_THIS(duration);
            COPY_THIS(fade_function);
            COPY_THIS(maximum_intensity);
            COPY_THIS(color);
            COPY_THIS(low_frequency_vibrate_frequency);
            COPY_THIS(low_frequency_vibrate_duration);
            COPY_THIS(low_frequency_vibrate_fade_function);
            COPY_THIS(high_frequency_vibrate_frequency);
            COPY_THIS(high_frequency_vibrate_duration);
            COPY_THIS(high_frequency_vibrate_fade_function);
            COPY_THIS(temporary_camera_impulse_duration);
            COPY_THIS(temporary_camera_impulse_fade_function);
            COPY_THIS(temporary_camera_impulse_rotation);
            COPY_THIS(temporary_camera_impulse_pushback);
            COPY_THIS(jitter);
            COPY_THIS(permanent_camera_impulse_angle);
            COPY_THIS(camera_shaking_duration);
            COPY_THIS(camera_shaking_falloff_function);
            COPY_THIS(camera_shaking_random_translation);
            COPY_THIS(camera_shaking_random_rotation);
            COPY_THIS(camera_shaking_wobble_function);
            COPY_THIS(camera_shaking_wobble_period);
            COPY_THIS(camera_shaking_wobble_weight);
            COPY_THIS(sound);
            COPY_THIS(breaking_effect_forward_velocity);
            COPY_THIS(breaking_effect_forward_radius);
            COPY_THIS(breaking_effect_forward_exponent);
            COPY_THIS(breaking_effect_outward_velocity);
            COPY_THIS(breaking_effect_outward_radius);
            COPY_THIS(breaking_effect_outward_exponent);
            COPY_THIS(damage_side_effect);
            COPY_THIS(damage_category);
            COPY_THIS(damage_flags);
            COPY_THIS(damage_aoe_core_radius);
            COPY_THIS(damage_lower_bound);
            COPY_THIS(damage_upper_bound);
            COPY_THIS(damage_vehicle_passthrough_penalty);
            COPY_THIS(damage_active_camouflage_damage);
            COPY_THIS(damage_stun);
            COPY_THIS(damage_maximum_stun);
            COPY_THIS(damage_stun_time);
            COPY_THIS(damage_instantaneous_acceleration);
            COPY_THIS(dirt);
            COPY_THIS(sand);
            COPY_THIS(stone);
            COPY_THIS(snow);
            COPY_THIS(wood);
            COPY_THIS(metal_hollow);
            COPY_THIS(metal_thin);
            COPY_THIS(metal_thick);
            COPY_THIS(rubber);
            COPY_THIS(glass);
            COPY_THIS(force_field);
            COPY_THIS(grunt);
            COPY_THIS(hunter_armor);
            COPY_THIS(hunter_skin);
            COPY_THIS(elite);
            COPY_THIS(jackal);
            COPY_THIS(jackal_energy_shield);
            COPY_THIS(engineer_skin);
            COPY_THIS(engineer_force_field);
            COPY_THIS(flood_combat_form);
            COPY_THIS(flood_carrier_form);
            COPY_THIS(cyborg_armor);
            COPY_THIS(cyborg_energy_shield);
            COPY_THIS(human_armor);
            COPY_THIS(human_skin);
            COPY_THIS(sentinel);
            COPY_THIS(monitor);
            COPY_THIS(plastic);
            COPY_THIS(water);
            COPY_THIS(leaves);
            COPY_THIS(elite_energy_shield);
            COPY_THIS(ice);
            COPY_THIS(hunter_shield);
            return copy;
        }
    };
    static_assert(sizeof(DamageEffect<NativeEndian>) == 0x2A0);

    ENDIAN_TEMPLATE(EndianType) struct Decal {
        EndianType<DecalFlags> flags;
        EndianType<DecalType> type;
        EndianType<DecalLayer> layer;
        PAD(0x2);
        TagDependency<EndianType> next_decal_in_chain;
        Bounds<EndianType<float>> radius;
        PAD(0xC);
        Bounds<EndianType<Fraction>> intensity;
        ColorRGB<EndianType> color_lower_bounds;
        ColorRGB<EndianType> color_upper_bounds;
        PAD(0xC);
        EndianType<std::int16_t> animation_loop_frame;
        EndianType<std::int16_t> animation_speed;
        PAD(0x1C);
        Bounds<EndianType<float>> lifetime;
        Bounds<EndianType<float>> decay_time;
        PAD(0xC);
        PAD(0x28);
        PAD(0x2);
        PAD(0x2);
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> map;
        PAD(0x14);
        EndianType<float> maximum_sprite_extent;
        PAD(0x4);
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator Decal<NewEndian>() const {
            Decal<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(type);
            COPY_THIS(layer);
            COPY_THIS(next_decal_in_chain);
            COPY_THIS(radius);
            COPY_THIS(intensity);
            COPY_THIS(color_lower_bounds);
            COPY_THIS(color_upper_bounds);
            COPY_THIS(animation_loop_frame);
            COPY_THIS(animation_speed);
            COPY_THIS(lifetime);
            COPY_THIS(decay_time);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(map);
            COPY_THIS(maximum_sprite_extent);
            return copy;
        }
    };
    static_assert(sizeof(Decal<NativeEndian>) == 0x10C);

    ENDIAN_TEMPLATE(EndianType) struct DetailObjectCollectionObjectType {
        TagString name;
        std::uint8_t sequence_index;
        DetailObjectCollectionTypeFlags flags;
        std::uint8_t first_sprite_index;
        std::uint8_t sprite_count;
        EndianType<Fraction> color_override_factor;
        PAD(0x8);
        EndianType<float> near_fade_distance;
        EndianType<float> far_fade_distance;
        EndianType<float> size;
        PAD(0x4);
        ColorRGB<EndianType> minimum_color;
        ColorRGB<EndianType> maximum_color;
        EndianType<ColorARGBInt> ambient_color;
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator DetailObjectCollectionObjectType<NewEndian>() const {
            DetailObjectCollectionObjectType<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(sequence_index);
            COPY_THIS(flags);
            COPY_THIS(first_sprite_index);
            COPY_THIS(sprite_count);
            COPY_THIS(color_override_factor);
            COPY_THIS(near_fade_distance);
            COPY_THIS(far_fade_distance);
            COPY_THIS(size);
            COPY_THIS(minimum_color);
            COPY_THIS(maximum_color);
            COPY_THIS(ambient_color);
            return copy;
        }
    };
    static_assert(sizeof(DetailObjectCollectionObjectType<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct DetailObjectCollection {
        EndianType<DetailObjectCollectionType> collection_type;
        PAD(0x2);
        EndianType<float> global_z_offset;
        PAD(0x2C);
        TagDependency<EndianType> sprite_plate;
        TagReflexive<EndianType, DetailObjectCollectionObjectType> types;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator DetailObjectCollection<NewEndian>() const {
            DetailObjectCollection<NewEndian> copy = {};
            COPY_THIS(collection_type);
            COPY_THIS(global_z_offset);
            COPY_THIS(sprite_plate);
            COPY_THIS(types);
            return copy;
        }
    };
    static_assert(sizeof(DetailObjectCollection<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct Device : Object<EndianType> {
        EndianType<DeviceFlags> device_flags;
        EndianType<float> power_transition_time;
        EndianType<float> power_acceleration_time;
        EndianType<float> position_transition_time;
        EndianType<float> position_acceleration_time;
        EndianType<float> depowered_position_transition_time;
        EndianType<float> depowered_position_acceleration_time;
        EndianType<DeviceIn> device_a_in;
        EndianType<DeviceIn> device_b_in;
        EndianType<DeviceIn> device_c_in;
        EndianType<DeviceIn> device_d_in;
        TagDependency<EndianType> open;
        TagDependency<EndianType> close;
        TagDependency<EndianType> opened;
        TagDependency<EndianType> closed;
        TagDependency<EndianType> depowered;
        TagDependency<EndianType> repowered;
        EndianType<float> delay_time;
        PAD(0x8);
        TagDependency<EndianType> delay_effect;
        EndianType<float> automatic_activation_radius;
        PAD(0x54);
        LittleEndian<float> inverse_power_acceleration_time;
        LittleEndian<float> inverse_power_transition_time;
        LittleEndian<float> inverse_depowered_position_acceleration_time;
        LittleEndian<float> inverse_depowered_position_transition_time;
        LittleEndian<float> inverse_position_acceleration_time;
        LittleEndian<float> inverse_position_transition_time;
        LittleEndian<float> delay_time_ticks;
        ENDIAN_TEMPLATE(NewEndian) operator Device<NewEndian>() const {
            Device<NewEndian> copy = {};
            COPY_THIS(device_flags);
            COPY_THIS(power_transition_time);
            COPY_THIS(power_acceleration_time);
            COPY_THIS(position_transition_time);
            COPY_THIS(position_acceleration_time);
            COPY_THIS(depowered_position_transition_time);
            COPY_THIS(depowered_position_acceleration_time);
            COPY_THIS(device_a_in);
            COPY_THIS(device_b_in);
            COPY_THIS(device_c_in);
            COPY_THIS(device_d_in);
            COPY_THIS(open);
            COPY_THIS(close);
            COPY_THIS(opened);
            COPY_THIS(closed);
            COPY_THIS(depowered);
            COPY_THIS(repowered);
            COPY_THIS(delay_time);
            COPY_THIS(delay_effect);
            COPY_THIS(automatic_activation_radius);
            COPY_THIS(inverse_power_acceleration_time);
            COPY_THIS(inverse_power_transition_time);
            COPY_THIS(inverse_depowered_position_acceleration_time);
            COPY_THIS(inverse_depowered_position_transition_time);
            COPY_THIS(inverse_position_acceleration_time);
            COPY_THIS(inverse_position_transition_time);
            COPY_THIS(delay_time_ticks);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Device<NativeEndian>) == 0x290);

    ENDIAN_TEMPLATE(EndianType) struct DeviceControl : Device<EndianType> {
        EndianType<DeviceType> type;
        EndianType<DeviceTriggersWhen> triggers_when;
        EndianType<float> call_value;
        PAD(0x50);
        TagDependency<EndianType> on;
        TagDependency<EndianType> off;
        TagDependency<EndianType> deny;
        ENDIAN_TEMPLATE(NewEndian) operator DeviceControl<NewEndian>() const {
            DeviceControl<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(triggers_when);
            COPY_THIS(call_value);
            COPY_THIS(on);
            COPY_THIS(off);
            COPY_THIS(deny);
            COPY_THIS(device_flags);
            COPY_THIS(power_transition_time);
            COPY_THIS(power_acceleration_time);
            COPY_THIS(position_transition_time);
            COPY_THIS(position_acceleration_time);
            COPY_THIS(depowered_position_transition_time);
            COPY_THIS(depowered_position_acceleration_time);
            COPY_THIS(device_a_in);
            COPY_THIS(device_b_in);
            COPY_THIS(device_c_in);
            COPY_THIS(device_d_in);
            COPY_THIS(open);
            COPY_THIS(close);
            COPY_THIS(opened);
            COPY_THIS(closed);
            COPY_THIS(depowered);
            COPY_THIS(repowered);
            COPY_THIS(delay_time);
            COPY_THIS(delay_effect);
            COPY_THIS(automatic_activation_radius);
            COPY_THIS(inverse_power_acceleration_time);
            COPY_THIS(inverse_power_transition_time);
            COPY_THIS(inverse_depowered_position_acceleration_time);
            COPY_THIS(inverse_depowered_position_transition_time);
            COPY_THIS(inverse_position_acceleration_time);
            COPY_THIS(inverse_position_transition_time);
            COPY_THIS(delay_time_ticks);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(DeviceControl<NativeEndian>) == 0x318);

    ENDIAN_TEMPLATE(EndianType) struct DeviceLightFixture : Device<EndianType> {
        PAD(0x40);
        ENDIAN_TEMPLATE(NewEndian) operator DeviceLightFixture<NewEndian>() const {
            DeviceLightFixture<NewEndian> copy = {};
            COPY_THIS(device_flags);
            COPY_THIS(power_transition_time);
            COPY_THIS(power_acceleration_time);
            COPY_THIS(position_transition_time);
            COPY_THIS(position_acceleration_time);
            COPY_THIS(depowered_position_transition_time);
            COPY_THIS(depowered_position_acceleration_time);
            COPY_THIS(device_a_in);
            COPY_THIS(device_b_in);
            COPY_THIS(device_c_in);
            COPY_THIS(device_d_in);
            COPY_THIS(open);
            COPY_THIS(close);
            COPY_THIS(opened);
            COPY_THIS(closed);
            COPY_THIS(depowered);
            COPY_THIS(repowered);
            COPY_THIS(delay_time);
            COPY_THIS(delay_effect);
            COPY_THIS(automatic_activation_radius);
            COPY_THIS(inverse_power_acceleration_time);
            COPY_THIS(inverse_power_transition_time);
            COPY_THIS(inverse_depowered_position_acceleration_time);
            COPY_THIS(inverse_depowered_position_transition_time);
            COPY_THIS(inverse_position_acceleration_time);
            COPY_THIS(inverse_position_transition_time);
            COPY_THIS(delay_time_ticks);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(DeviceLightFixture<NativeEndian>) == 0x2D0);

    ENDIAN_TEMPLATE(EndianType) struct DeviceMachine : Device<EndianType> {
        EndianType<MachineType> machine_type;
        EndianType<MachineFlags> machine_flags;
        EndianType<float> door_open_time;
        PAD(0x50);
        EndianType<MachineCollisionResponse> collision_response;
        EndianType<Index> elevator_node;
        PAD(0x34);
        LittleEndian<std::uint32_t> door_open_time_ticks;
        ENDIAN_TEMPLATE(NewEndian) operator DeviceMachine<NewEndian>() const {
            DeviceMachine<NewEndian> copy = {};
            COPY_THIS(machine_type);
            COPY_THIS(machine_flags);
            COPY_THIS(door_open_time);
            COPY_THIS(collision_response);
            COPY_THIS(elevator_node);
            COPY_THIS(door_open_time_ticks);
            COPY_THIS(device_flags);
            COPY_THIS(power_transition_time);
            COPY_THIS(power_acceleration_time);
            COPY_THIS(position_transition_time);
            COPY_THIS(position_acceleration_time);
            COPY_THIS(depowered_position_transition_time);
            COPY_THIS(depowered_position_acceleration_time);
            COPY_THIS(device_a_in);
            COPY_THIS(device_b_in);
            COPY_THIS(device_c_in);
            COPY_THIS(device_d_in);
            COPY_THIS(open);
            COPY_THIS(close);
            COPY_THIS(opened);
            COPY_THIS(closed);
            COPY_THIS(depowered);
            COPY_THIS(repowered);
            COPY_THIS(delay_time);
            COPY_THIS(delay_effect);
            COPY_THIS(automatic_activation_radius);
            COPY_THIS(inverse_power_acceleration_time);
            COPY_THIS(inverse_power_transition_time);
            COPY_THIS(inverse_depowered_position_acceleration_time);
            COPY_THIS(inverse_depowered_position_transition_time);
            COPY_THIS(inverse_position_acceleration_time);
            COPY_THIS(inverse_position_transition_time);
            COPY_THIS(delay_time_ticks);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(DeviceMachine<NativeEndian>) == 0x324);

    ENDIAN_TEMPLATE(EndianType) struct Dialogue {
        PAD(0x2);
        PAD(0x2);
        PAD(0xC);
        TagDependency<EndianType> idle_noncombat;
        TagDependency<EndianType> idle_combat;
        TagDependency<EndianType> idle_flee;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> pain_body_minor;
        TagDependency<EndianType> pain_body_major;
        TagDependency<EndianType> pain_shield;
        TagDependency<EndianType> pain_falling;
        TagDependency<EndianType> scream_fear;
        TagDependency<EndianType> scream_pain;
        TagDependency<EndianType> maimed_limb;
        TagDependency<EndianType> maimed_head;
        TagDependency<EndianType> death_quiet;
        TagDependency<EndianType> death_violent;
        TagDependency<EndianType> death_falling;
        TagDependency<EndianType> death_agonizing;
        TagDependency<EndianType> death_instant;
        TagDependency<EndianType> death_flying;
        PAD(0x10);
        TagDependency<EndianType> damaged_friend;
        TagDependency<EndianType> damaged_friend_player;
        TagDependency<EndianType> damaged_enemy;
        TagDependency<EndianType> damaged_enemy_cm;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> hurt_friend;
        TagDependency<EndianType> hurt_friend_re;
        TagDependency<EndianType> hurt_friend_player;
        TagDependency<EndianType> hurt_enemy;
        TagDependency<EndianType> hurt_enemy_re;
        TagDependency<EndianType> hurt_enemy_cm;
        TagDependency<EndianType> hurt_enemy_bullet;
        TagDependency<EndianType> hurt_enemy_needler;
        TagDependency<EndianType> hurt_enemy_plasma;
        TagDependency<EndianType> hurt_enemy_sniper;
        TagDependency<EndianType> hurt_enemy_grenade;
        TagDependency<EndianType> hurt_enemy_explosion;
        TagDependency<EndianType> hurt_enemy_melee;
        TagDependency<EndianType> hurt_enemy_flame;
        TagDependency<EndianType> hurt_enemy_shotgun;
        TagDependency<EndianType> hurt_enemy_vehicle;
        TagDependency<EndianType> hurt_enemy_mountedweapon;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> killed_friend;
        TagDependency<EndianType> killed_friend_cm;
        TagDependency<EndianType> killed_friend_player;
        TagDependency<EndianType> killed_friend_player_cm;
        TagDependency<EndianType> killed_enemy;
        TagDependency<EndianType> killed_enemy_cm;
        TagDependency<EndianType> killed_enemy_player;
        TagDependency<EndianType> killed_enemy_player_cm;
        TagDependency<EndianType> killed_enemy_covenant;
        TagDependency<EndianType> killed_enemy_covenant_cm;
        TagDependency<EndianType> killed_enemy_floodcombat;
        TagDependency<EndianType> killed_enemy_floodcombat_cm;
        TagDependency<EndianType> killed_enemy_floodcarrier;
        TagDependency<EndianType> killed_enemy_floodcarrier_cm;
        TagDependency<EndianType> killed_enemy_sentinel;
        TagDependency<EndianType> killed_enemy_sentinel_cm;
        TagDependency<EndianType> killed_enemy_bullet;
        TagDependency<EndianType> killed_enemy_needler;
        TagDependency<EndianType> killed_enemy_plasma;
        TagDependency<EndianType> killed_enemy_sniper;
        TagDependency<EndianType> killed_enemy_grenade;
        TagDependency<EndianType> killed_enemy_explosion;
        TagDependency<EndianType> killed_enemy_melee;
        TagDependency<EndianType> killed_enemy_flame;
        TagDependency<EndianType> killed_enemy_shotgun;
        TagDependency<EndianType> killed_enemy_vehicle;
        TagDependency<EndianType> killed_enemy_mountedweapon;
        TagDependency<EndianType> killing_spree;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> player_kill_cm;
        TagDependency<EndianType> player_kill_bullet_cm;
        TagDependency<EndianType> player_kill_needler_cm;
        TagDependency<EndianType> player_kill_plasma_cm;
        TagDependency<EndianType> player_kill_sniper_cm;
        TagDependency<EndianType> anyone_kill_grenade_cm;
        TagDependency<EndianType> player_kill_explosion_cm;
        TagDependency<EndianType> player_kill_melee_cm;
        TagDependency<EndianType> player_kill_flame_cm;
        TagDependency<EndianType> player_kill_shotgun_cm;
        TagDependency<EndianType> player_kill_vehicle_cm;
        TagDependency<EndianType> player_kill_mountedweapon_cm;
        TagDependency<EndianType> player_killling_spree_cm;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> friend_died;
        TagDependency<EndianType> friend_player_died;
        TagDependency<EndianType> friend_killed_by_friend;
        TagDependency<EndianType> friend_killed_by_friendly_player;
        TagDependency<EndianType> friend_killed_by_enemy;
        TagDependency<EndianType> friend_killed_by_enemy_player;
        TagDependency<EndianType> friend_killed_by_covenant;
        TagDependency<EndianType> friend_killed_by_flood;
        TagDependency<EndianType> friend_killed_by_sentinel;
        TagDependency<EndianType> friend_betrayed;
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> new_combat_alone;
        TagDependency<EndianType> new_enemy_recent_combat;
        TagDependency<EndianType> old_enemy_sighted;
        TagDependency<EndianType> unexpected_enemy;
        TagDependency<EndianType> dead_friend_found;
        TagDependency<EndianType> alliance_broken;
        TagDependency<EndianType> alliance_reformed;
        TagDependency<EndianType> grenade_throwing;
        TagDependency<EndianType> grenade_sighted;
        TagDependency<EndianType> grenade_startle;
        TagDependency<EndianType> grenade_danger_enemy;
        TagDependency<EndianType> grenade_danger_self;
        TagDependency<EndianType> grenade_danger_friend;
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> new_combat_group_re;
        TagDependency<EndianType> new_combat_nearby_re;
        TagDependency<EndianType> alert_friend;
        TagDependency<EndianType> alert_friend_re;
        TagDependency<EndianType> alert_lost_contact;
        TagDependency<EndianType> alert_lost_contact_re;
        TagDependency<EndianType> blocked;
        TagDependency<EndianType> blocked_re;
        TagDependency<EndianType> search_start;
        TagDependency<EndianType> search_query;
        TagDependency<EndianType> search_query_re;
        TagDependency<EndianType> search_report;
        TagDependency<EndianType> search_abandon;
        TagDependency<EndianType> search_group_abandon;
        TagDependency<EndianType> group_uncover;
        TagDependency<EndianType> group_uncover_re;
        TagDependency<EndianType> advance;
        TagDependency<EndianType> advance_re;
        TagDependency<EndianType> retreat;
        TagDependency<EndianType> retreat_re;
        TagDependency<EndianType> cover;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> sighted_friend_player;
        TagDependency<EndianType> shooting;
        TagDependency<EndianType> shooting_vehicle;
        TagDependency<EndianType> shooting_berserk;
        TagDependency<EndianType> shooting_group;
        TagDependency<EndianType> shooting_traitor;
        TagDependency<EndianType> taunt;
        TagDependency<EndianType> taunt_re;
        TagDependency<EndianType> flee;
        TagDependency<EndianType> flee_re;
        TagDependency<EndianType> flee_leader_died;
        TagDependency<EndianType> attempted_flee;
        TagDependency<EndianType> attempted_flee_re;
        TagDependency<EndianType> lost_contact;
        TagDependency<EndianType> hiding_finished;
        TagDependency<EndianType> vehicle_entry;
        TagDependency<EndianType> vehicle_exit;
        TagDependency<EndianType> vehicle_woohoo;
        TagDependency<EndianType> vehicle_scared;
        TagDependency<EndianType> vehicle_collision;
        TagDependency<EndianType> partially_sighted;
        TagDependency<EndianType> nothing_there;
        TagDependency<EndianType> pleading;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> surprise;
        TagDependency<EndianType> berserk;
        TagDependency<EndianType> melee_attack;
        TagDependency<EndianType> dive;
        TagDependency<EndianType> uncover_exclamation;
        TagDependency<EndianType> leap_attack;
        TagDependency<EndianType> resurrection;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> celebration;
        TagDependency<EndianType> check_body_enemy;
        TagDependency<EndianType> check_body_friend;
        TagDependency<EndianType> shooting_dead_enemy;
        TagDependency<EndianType> shooting_dead_enemy_player;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        TagDependency<EndianType> alone;
        TagDependency<EndianType> unscathed;
        TagDependency<EndianType> seriously_wounded;
        TagDependency<EndianType> seriously_wounded_re;
        TagDependency<EndianType> massacre;
        TagDependency<EndianType> massacre_re;
        TagDependency<EndianType> rout;
        TagDependency<EndianType> rout_re;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x2F0);
        ENDIAN_TEMPLATE(NewEndian) operator Dialogue<NewEndian>() const {
            Dialogue<NewEndian> copy = {};
            COPY_THIS(idle_noncombat);
            COPY_THIS(idle_combat);
            COPY_THIS(idle_flee);
            COPY_THIS(pain_body_minor);
            COPY_THIS(pain_body_major);
            COPY_THIS(pain_shield);
            COPY_THIS(pain_falling);
            COPY_THIS(scream_fear);
            COPY_THIS(scream_pain);
            COPY_THIS(maimed_limb);
            COPY_THIS(maimed_head);
            COPY_THIS(death_quiet);
            COPY_THIS(death_violent);
            COPY_THIS(death_falling);
            COPY_THIS(death_agonizing);
            COPY_THIS(death_instant);
            COPY_THIS(death_flying);
            COPY_THIS(damaged_friend);
            COPY_THIS(damaged_friend_player);
            COPY_THIS(damaged_enemy);
            COPY_THIS(damaged_enemy_cm);
            COPY_THIS(hurt_friend);
            COPY_THIS(hurt_friend_re);
            COPY_THIS(hurt_friend_player);
            COPY_THIS(hurt_enemy);
            COPY_THIS(hurt_enemy_re);
            COPY_THIS(hurt_enemy_cm);
            COPY_THIS(hurt_enemy_bullet);
            COPY_THIS(hurt_enemy_needler);
            COPY_THIS(hurt_enemy_plasma);
            COPY_THIS(hurt_enemy_sniper);
            COPY_THIS(hurt_enemy_grenade);
            COPY_THIS(hurt_enemy_explosion);
            COPY_THIS(hurt_enemy_melee);
            COPY_THIS(hurt_enemy_flame);
            COPY_THIS(hurt_enemy_shotgun);
            COPY_THIS(hurt_enemy_vehicle);
            COPY_THIS(hurt_enemy_mountedweapon);
            COPY_THIS(killed_friend);
            COPY_THIS(killed_friend_cm);
            COPY_THIS(killed_friend_player);
            COPY_THIS(killed_friend_player_cm);
            COPY_THIS(killed_enemy);
            COPY_THIS(killed_enemy_cm);
            COPY_THIS(killed_enemy_player);
            COPY_THIS(killed_enemy_player_cm);
            COPY_THIS(killed_enemy_covenant);
            COPY_THIS(killed_enemy_covenant_cm);
            COPY_THIS(killed_enemy_floodcombat);
            COPY_THIS(killed_enemy_floodcombat_cm);
            COPY_THIS(killed_enemy_floodcarrier);
            COPY_THIS(killed_enemy_floodcarrier_cm);
            COPY_THIS(killed_enemy_sentinel);
            COPY_THIS(killed_enemy_sentinel_cm);
            COPY_THIS(killed_enemy_bullet);
            COPY_THIS(killed_enemy_needler);
            COPY_THIS(killed_enemy_plasma);
            COPY_THIS(killed_enemy_sniper);
            COPY_THIS(killed_enemy_grenade);
            COPY_THIS(killed_enemy_explosion);
            COPY_THIS(killed_enemy_melee);
            COPY_THIS(killed_enemy_flame);
            COPY_THIS(killed_enemy_shotgun);
            COPY_THIS(killed_enemy_vehicle);
            COPY_THIS(killed_enemy_mountedweapon);
            COPY_THIS(killing_spree);
            COPY_THIS(player_kill_cm);
            COPY_THIS(player_kill_bullet_cm);
            COPY_THIS(player_kill_needler_cm);
            COPY_THIS(player_kill_plasma_cm);
            COPY_THIS(player_kill_sniper_cm);
            COPY_THIS(anyone_kill_grenade_cm);
            COPY_THIS(player_kill_explosion_cm);
            COPY_THIS(player_kill_melee_cm);
            COPY_THIS(player_kill_flame_cm);
            COPY_THIS(player_kill_shotgun_cm);
            COPY_THIS(player_kill_vehicle_cm);
            COPY_THIS(player_kill_mountedweapon_cm);
            COPY_THIS(player_killling_spree_cm);
            COPY_THIS(friend_died);
            COPY_THIS(friend_player_died);
            COPY_THIS(friend_killed_by_friend);
            COPY_THIS(friend_killed_by_friendly_player);
            COPY_THIS(friend_killed_by_enemy);
            COPY_THIS(friend_killed_by_enemy_player);
            COPY_THIS(friend_killed_by_covenant);
            COPY_THIS(friend_killed_by_flood);
            COPY_THIS(friend_killed_by_sentinel);
            COPY_THIS(friend_betrayed);
            COPY_THIS(new_combat_alone);
            COPY_THIS(new_enemy_recent_combat);
            COPY_THIS(old_enemy_sighted);
            COPY_THIS(unexpected_enemy);
            COPY_THIS(dead_friend_found);
            COPY_THIS(alliance_broken);
            COPY_THIS(alliance_reformed);
            COPY_THIS(grenade_throwing);
            COPY_THIS(grenade_sighted);
            COPY_THIS(grenade_startle);
            COPY_THIS(grenade_danger_enemy);
            COPY_THIS(grenade_danger_self);
            COPY_THIS(grenade_danger_friend);
            COPY_THIS(new_combat_group_re);
            COPY_THIS(new_combat_nearby_re);
            COPY_THIS(alert_friend);
            COPY_THIS(alert_friend_re);
            COPY_THIS(alert_lost_contact);
            COPY_THIS(alert_lost_contact_re);
            COPY_THIS(blocked);
            COPY_THIS(blocked_re);
            COPY_THIS(search_start);
            COPY_THIS(search_query);
            COPY_THIS(search_query_re);
            COPY_THIS(search_report);
            COPY_THIS(search_abandon);
            COPY_THIS(search_group_abandon);
            COPY_THIS(group_uncover);
            COPY_THIS(group_uncover_re);
            COPY_THIS(advance);
            COPY_THIS(advance_re);
            COPY_THIS(retreat);
            COPY_THIS(retreat_re);
            COPY_THIS(cover);
            COPY_THIS(sighted_friend_player);
            COPY_THIS(shooting);
            COPY_THIS(shooting_vehicle);
            COPY_THIS(shooting_berserk);
            COPY_THIS(shooting_group);
            COPY_THIS(shooting_traitor);
            COPY_THIS(taunt);
            COPY_THIS(taunt_re);
            COPY_THIS(flee);
            COPY_THIS(flee_re);
            COPY_THIS(flee_leader_died);
            COPY_THIS(attempted_flee);
            COPY_THIS(attempted_flee_re);
            COPY_THIS(lost_contact);
            COPY_THIS(hiding_finished);
            COPY_THIS(vehicle_entry);
            COPY_THIS(vehicle_exit);
            COPY_THIS(vehicle_woohoo);
            COPY_THIS(vehicle_scared);
            COPY_THIS(vehicle_collision);
            COPY_THIS(partially_sighted);
            COPY_THIS(nothing_there);
            COPY_THIS(pleading);
            COPY_THIS(surprise);
            COPY_THIS(berserk);
            COPY_THIS(melee_attack);
            COPY_THIS(dive);
            COPY_THIS(uncover_exclamation);
            COPY_THIS(leap_attack);
            COPY_THIS(resurrection);
            COPY_THIS(celebration);
            COPY_THIS(check_body_enemy);
            COPY_THIS(check_body_friend);
            COPY_THIS(shooting_dead_enemy);
            COPY_THIS(shooting_dead_enemy_player);
            COPY_THIS(alone);
            COPY_THIS(unscathed);
            COPY_THIS(seriously_wounded);
            COPY_THIS(seriously_wounded_re);
            COPY_THIS(massacre);
            COPY_THIS(massacre_re);
            COPY_THIS(rout);
            COPY_THIS(rout_re);
            return copy;
        }
    };
    static_assert(sizeof(Dialogue<NativeEndian>) == 0x1010);

    ENDIAN_TEMPLATE(EndianType) struct EffectLocation {
        TagString marker_name;
        ENDIAN_TEMPLATE(NewEndian) operator EffectLocation<NewEndian>() const {
            EffectLocation<NewEndian> copy;
            COPY_THIS(marker_name);
            return copy;
        }
    };
    static_assert(sizeof(EffectLocation<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct EffectPart {
        EndianType<EffectCreateIn> create_in;
        EndianType<EffectViolenceMode> violence_mode;
        EndianType<Index> location;
        EndianType<EffectPartFlags> flags;
        PAD(0xC);
        EndianType<std::uint32_t> type_class;
        TagDependency<EndianType> type;
        PAD(0x18);
        Bounds<EndianType<float>> velocity_bounds;
        EndianType<Angle> velocity_cone_angle;
        Bounds<EndianType<Angle>> angular_velocity_bounds;
        Bounds<EndianType<float>> radius_modifier_bounds;
        PAD(0x4);
        EndianType<EffectPartScalesValues> a_scales_values;
        EndianType<EffectPartScalesValues> b_scales_values;
        ENDIAN_TEMPLATE(NewEndian) operator EffectPart<NewEndian>() const {
            EffectPart<NewEndian> copy = {};
            COPY_THIS(create_in);
            COPY_THIS(violence_mode);
            COPY_THIS(location);
            COPY_THIS(flags);
            COPY_THIS(type_class);
            COPY_THIS(type);
            COPY_THIS(velocity_bounds);
            COPY_THIS(velocity_cone_angle);
            COPY_THIS(angular_velocity_bounds);
            COPY_THIS(radius_modifier_bounds);
            COPY_THIS(a_scales_values);
            COPY_THIS(b_scales_values);
            return copy;
        }
    };
    static_assert(sizeof(EffectPart<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct EffectParticle {
        EndianType<EffectCreateIn> create_in;
        EndianType<EffectViolenceMode> violence_mode;
        EndianType<EffectCreate> create;
        PAD(0x2);
        EndianType<Index> location;
        PAD(0x2);
        Euler2D<EndianType> relative_direction;
        Point3D<EndianType> relative_offset;
        Vector3D<LittleEndian> relative_direction_vector;
        PAD(0x28);
        TagDependency<EndianType> particle_type;
        EndianType<EffectParticleFlags> flags;
        EndianType<EffectDistributionFunction> distribution_function;
        PAD(0x2);
        Bounds<EndianType<std::int16_t>> count;
        Bounds<EndianType<float>> distribution_radius;
        PAD(0xC);
        Bounds<EndianType<float>> velocity;
        EndianType<Angle> velocity_cone_angle;
        Bounds<EndianType<Angle>> angular_velocity;
        PAD(0x8);
        Bounds<EndianType<float>> radius;
        PAD(0x8);
        ColorARGB<EndianType> tint_lower_bound;
        ColorARGB<EndianType> tint_upper_bound;
        PAD(0x10);
        EndianType<EffectParticleScalesValues> a_scales_values;
        EndianType<EffectParticleScalesValues> b_scales_values;
        ENDIAN_TEMPLATE(NewEndian) operator EffectParticle<NewEndian>() const {
            EffectParticle<NewEndian> copy = {};
            COPY_THIS(create_in);
            COPY_THIS(violence_mode);
            COPY_THIS(create);
            COPY_THIS(location);
            COPY_THIS(relative_direction);
            COPY_THIS(relative_offset);
            COPY_THIS(relative_direction_vector);
            COPY_THIS(particle_type);
            COPY_THIS(flags);
            COPY_THIS(distribution_function);
            COPY_THIS(count);
            COPY_THIS(distribution_radius);
            COPY_THIS(velocity);
            COPY_THIS(velocity_cone_angle);
            COPY_THIS(angular_velocity);
            COPY_THIS(radius);
            COPY_THIS(tint_lower_bound);
            COPY_THIS(tint_upper_bound);
            COPY_THIS(a_scales_values);
            COPY_THIS(b_scales_values);
            return copy;
        }
    };
    static_assert(sizeof(EffectParticle<NativeEndian>) == 0xE8);

    ENDIAN_TEMPLATE(EndianType) struct EffectEvent {
        PAD(0x4);
        EndianType<Fraction> skip_fraction;
        Bounds<EndianType<float>> delay_bounds;
        Bounds<EndianType<float>> duration_bounds;
        PAD(0x14);
        TagReflexive<EndianType, EffectPart> parts;
        TagReflexive<EndianType, EffectParticle> particles;
        ENDIAN_TEMPLATE(NewEndian) operator EffectEvent<NewEndian>() const {
            EffectEvent<NewEndian> copy = {};
            COPY_THIS(skip_fraction);
            COPY_THIS(delay_bounds);
            COPY_THIS(duration_bounds);
            COPY_THIS(parts);
            COPY_THIS(particles);
            return copy;
        }
    };
    static_assert(sizeof(EffectEvent<NativeEndian>) == 0x44);

    ENDIAN_TEMPLATE(EndianType) struct Effect {
        EndianType<EffectFlags> flags;
        EndianType<Index> loop_start_event;
        EndianType<Index> loop_stop_event;
        LittleEndian<float> maximum_damage_radius;
        PAD(0x1C);
        TagReflexive<EndianType, EffectLocation> locations;
        TagReflexive<EndianType, EffectEvent> events;
        ENDIAN_TEMPLATE(NewEndian) operator Effect<NewEndian>() const {
            Effect<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(loop_start_event);
            COPY_THIS(loop_stop_event);
            COPY_THIS(maximum_damage_radius);
            COPY_THIS(locations);
            COPY_THIS(events);
            return copy;
        }
    };
    static_assert(sizeof(Effect<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct Item : Object<EndianType> {
        EndianType<ItemFlags> item_flags;
        EndianType<Index> pickup_text_index;
        EndianType<std::int16_t> sort_order;
        EndianType<float> scale;
        EndianType<std::int16_t> hud_message_value_scale;
        PAD(0x2);
        PAD(0x10);
        EndianType<ItemFunctionIn> item_a_in;
        EndianType<ItemFunctionIn> item_b_in;
        EndianType<ItemFunctionIn> item_c_in;
        EndianType<ItemFunctionIn> item_d_in;
        PAD(0xA4);
        TagDependency<EndianType> material_effects;
        TagDependency<EndianType> collision_sound;
        PAD(0x78);
        Bounds<EndianType<float>> detonation_delay;
        TagDependency<EndianType> detonating_effect;
        TagDependency<EndianType> detonation_effect;
        ENDIAN_TEMPLATE(NewEndian) operator Item<NewEndian>() const {
            Item<NewEndian> copy = {};
            COPY_THIS(item_flags);
            COPY_THIS(pickup_text_index);
            COPY_THIS(sort_order);
            COPY_THIS(scale);
            COPY_THIS(hud_message_value_scale);
            COPY_THIS(item_a_in);
            COPY_THIS(item_b_in);
            COPY_THIS(item_c_in);
            COPY_THIS(item_d_in);
            COPY_THIS(material_effects);
            COPY_THIS(collision_sound);
            COPY_THIS(detonation_delay);
            COPY_THIS(detonating_effect);
            COPY_THIS(detonation_effect);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Item<NativeEndian>) == 0x308);

    ENDIAN_TEMPLATE(EndianType) struct Equipment : Item<EndianType> {
        EndianType<EquipmentPowerupType> powerup_type;
        EndianType<GrenadeType> grenade_type;
        EndianType<float> powerup_time;
        TagDependency<EndianType> pickup_sound;
        PAD(0x90);
        ENDIAN_TEMPLATE(NewEndian) operator Equipment<NewEndian>() const {
            Equipment<NewEndian> copy = {};
            COPY_THIS(powerup_type);
            COPY_THIS(grenade_type);
            COPY_THIS(powerup_time);
            COPY_THIS(pickup_sound);
            COPY_THIS(item_flags);
            COPY_THIS(pickup_text_index);
            COPY_THIS(sort_order);
            COPY_THIS(scale);
            COPY_THIS(hud_message_value_scale);
            COPY_THIS(item_a_in);
            COPY_THIS(item_b_in);
            COPY_THIS(item_c_in);
            COPY_THIS(item_d_in);
            COPY_THIS(material_effects);
            COPY_THIS(collision_sound);
            COPY_THIS(detonation_delay);
            COPY_THIS(detonating_effect);
            COPY_THIS(detonation_effect);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Equipment<NativeEndian>) == 0x3B0);

    ENDIAN_TEMPLATE(EndianType) struct FlagAttachmentPoint {
        EndianType<std::int16_t> height_to_next_attachment;
        PAD(0x2);
        PAD(0x10);
        TagString marker_name;
        ENDIAN_TEMPLATE(NewEndian) operator FlagAttachmentPoint<NewEndian>() const {
            FlagAttachmentPoint<NewEndian> copy = {};
            COPY_THIS(height_to_next_attachment);
            COPY_THIS(marker_name);
            return copy;
        }
    };
    static_assert(sizeof(FlagAttachmentPoint<NativeEndian>) == 0x34);

    ENDIAN_TEMPLATE(EndianType) struct Flag {
        EndianType<IsUnusedFlag> flags;
        EndianType<FlagTrailingEdgeShape> trailing_edge_shape;
        EndianType<std::int16_t> trailing_edge_shape_offset;
        EndianType<FlagAttachedEdgeShape> attached_edge_shape;
        PAD(0x2);
        EndianType<std::int16_t> width;
        EndianType<std::int16_t> height;
        EndianType<float> cell_width;
        EndianType<float> cell_height;
        TagDependency<EndianType> red_flag_shader;
        TagDependency<EndianType> physics;
        EndianType<float> wind_noise;
        PAD(0x8);
        TagDependency<EndianType> blue_flag_shader;
        TagReflexive<EndianType, FlagAttachmentPoint> attachment_points;
        ENDIAN_TEMPLATE(NewEndian) operator Flag<NewEndian>() const {
            Flag<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(trailing_edge_shape);
            COPY_THIS(trailing_edge_shape_offset);
            COPY_THIS(attached_edge_shape);
            COPY_THIS(width);
            COPY_THIS(height);
            COPY_THIS(cell_width);
            COPY_THIS(cell_height);
            COPY_THIS(red_flag_shader);
            COPY_THIS(physics);
            COPY_THIS(wind_noise);
            COPY_THIS(blue_flag_shader);
            COPY_THIS(attachment_points);
            return copy;
        }
    };
    static_assert(sizeof(Flag<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct Fog {
        EndianType<FogFlags> flags;
        PAD(0x4);
        PAD(0x4C);
        PAD(0x4);
        EndianType<Fraction> maximum_density;
        PAD(0x4);
        EndianType<float> opaque_distance;
        PAD(0x4);
        EndianType<float> opaque_depth;
        PAD(0x8);
        EndianType<float> distance_to_water_plane;
        ColorRGB<EndianType> color;
        EndianType<FogScreenFlags> flags_1;
        EndianType<std::int16_t> layer_count;
        Bounds<EndianType<float>> distance_gradient;
        Bounds<EndianType<Fraction>> density_gradient;
        EndianType<float> start_distance_from_fog_plane;
        PAD(0x4);
        EndianType<ColorARGBInt> screen_layers_color;
        EndianType<Fraction> rotation_multiplier;
        EndianType<Fraction> strafing_multiplier;
        EndianType<Fraction> zoom_multiplier;
        PAD(0x8);
        EndianType<float> map_scale;
        TagDependency<EndianType> map;
        EndianType<float> animation_period;
        PAD(0x4);
        Bounds<EndianType<float>> wind_velocity;
        Bounds<EndianType<float>> wind_period;
        EndianType<Fraction> wind_acceleration_weight;
        EndianType<Fraction> wind_perpendicular_weight;
        PAD(0x8);
        TagDependency<EndianType> background_sound;
        TagDependency<EndianType> sound_environment;
        PAD(0x78);
        ENDIAN_TEMPLATE(NewEndian) operator Fog<NewEndian>() const {
            Fog<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(maximum_density);
            COPY_THIS(opaque_distance);
            COPY_THIS(opaque_depth);
            COPY_THIS(distance_to_water_plane);
            COPY_THIS(color);
            COPY_THIS(flags_1);
            COPY_THIS(layer_count);
            COPY_THIS(distance_gradient);
            COPY_THIS(density_gradient);
            COPY_THIS(start_distance_from_fog_plane);
            COPY_THIS(screen_layers_color);
            COPY_THIS(rotation_multiplier);
            COPY_THIS(strafing_multiplier);
            COPY_THIS(zoom_multiplier);
            COPY_THIS(map_scale);
            COPY_THIS(map);
            COPY_THIS(animation_period);
            COPY_THIS(wind_velocity);
            COPY_THIS(wind_period);
            COPY_THIS(wind_acceleration_weight);
            COPY_THIS(wind_perpendicular_weight);
            COPY_THIS(background_sound);
            COPY_THIS(sound_environment);
            return copy;
        }
    };
    static_assert(sizeof(Fog<NativeEndian>) == 0x18C);

    ENDIAN_TEMPLATE(EndianType) struct FontCharacterIndex {
        EndianType<Index> character_index;
        ENDIAN_TEMPLATE(NewEndian) operator FontCharacterIndex<NewEndian>() const {
            FontCharacterIndex<NewEndian> copy;
            COPY_THIS(character_index);
            return copy;
        }
    };
    static_assert(sizeof(FontCharacterIndex<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct FontCharacterTables {
        TagReflexive<EndianType, FontCharacterIndex> character_table;
        ENDIAN_TEMPLATE(NewEndian) operator FontCharacterTables<NewEndian>() const {
            FontCharacterTables<NewEndian> copy;
            COPY_THIS(character_table);
            return copy;
        }
    };
    static_assert(sizeof(FontCharacterTables<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct FontCharacter {
        EndianType<std::uint16_t> character;
        EndianType<std::int16_t> character_width;
        EndianType<std::int16_t> bitmap_width;
        EndianType<std::int16_t> bitmap_height;
        EndianType<std::int16_t> bitmap_origin_x;
        EndianType<std::int16_t> bitmap_origin_y;
        EndianType<std::uint16_t> hardware_character_index;
        PAD(0x2);
        EndianType<std::int32_t> pixels_offset;
        ENDIAN_TEMPLATE(NewEndian) operator FontCharacter<NewEndian>() const {
            FontCharacter<NewEndian> copy = {};
            COPY_THIS(character);
            COPY_THIS(character_width);
            COPY_THIS(bitmap_width);
            COPY_THIS(bitmap_height);
            COPY_THIS(bitmap_origin_x);
            COPY_THIS(bitmap_origin_y);
            COPY_THIS(hardware_character_index);
            COPY_THIS(pixels_offset);
            return copy;
        }
    };
    static_assert(sizeof(FontCharacter<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct Font {
        EndianType<FontFlags> flags;
        EndianType<std::int16_t> ascending_height;
        EndianType<std::int16_t> descending_height;
        EndianType<std::int16_t> leading_height;
        EndianType<std::int16_t> leading_width;
        PAD(0x24);
        TagReflexive<EndianType, FontCharacterTables> character_tables;
        TagDependency<EndianType> bold;
        TagDependency<EndianType> italic;
        TagDependency<EndianType> condense;
        TagDependency<EndianType> underline;
        TagReflexive<EndianType, FontCharacter> characters;
        TagDataOffset<EndianType> pixels;
        ENDIAN_TEMPLATE(NewEndian) operator Font<NewEndian>() const {
            Font<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(ascending_height);
            COPY_THIS(descending_height);
            COPY_THIS(leading_height);
            COPY_THIS(leading_width);
            COPY_THIS(character_tables);
            COPY_THIS(bold);
            COPY_THIS(italic);
            COPY_THIS(condense);
            COPY_THIS(underline);
            COPY_THIS(characters);
            COPY_THIS(pixels);
            return copy;
        }
    };
    static_assert(sizeof(Font<NativeEndian>) == 0x9C);

    ENDIAN_TEMPLATE(EndianType) struct Garbage : Item<EndianType> {
        PAD(0xA8);
        ENDIAN_TEMPLATE(NewEndian) operator Garbage<NewEndian>() const {
            Garbage<NewEndian> copy = {};
            COPY_THIS(item_flags);
            COPY_THIS(pickup_text_index);
            COPY_THIS(sort_order);
            COPY_THIS(scale);
            COPY_THIS(hud_message_value_scale);
            COPY_THIS(item_a_in);
            COPY_THIS(item_b_in);
            COPY_THIS(item_c_in);
            COPY_THIS(item_d_in);
            COPY_THIS(material_effects);
            COPY_THIS(collision_sound);
            COPY_THIS(detonation_delay);
            COPY_THIS(detonating_effect);
            COPY_THIS(detonation_effect);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Garbage<NativeEndian>) == 0x3B0);

    ENDIAN_TEMPLATE(EndianType) struct ModelVertexUncompressed {
        Point3D<EndianType> position;
        Vector3D<EndianType> normal;
        Vector3D<EndianType> binormal;
        Vector3D<EndianType> tangent;
        Point2D<EndianType> texture_coords;
        EndianType<Index> node0_index;
        EndianType<Index> node1_index;
        EndianType<float> node0_weight;
        EndianType<float> node1_weight;
        ENDIAN_TEMPLATE(NewEndian) operator ModelVertexUncompressed<NewEndian>() const {
            ModelVertexUncompressed<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(normal);
            COPY_THIS(binormal);
            COPY_THIS(tangent);
            COPY_THIS(texture_coords);
            COPY_THIS(node0_index);
            COPY_THIS(node1_index);
            COPY_THIS(node0_weight);
            COPY_THIS(node1_weight);
            return copy;
        }
    };
    static_assert(sizeof(ModelVertexUncompressed<NativeEndian>) == 0x44);

    ENDIAN_TEMPLATE(EndianType) struct ModelVertexCompressed {
        Point3D<EndianType> position;
        EndianType<std::uint32_t> normal;
        EndianType<std::uint32_t> binormal;
        EndianType<std::uint32_t> tangent;
        EndianType<std::int16_t> texture_coordinate_u;
        EndianType<std::int16_t> texture_coordinate_v;
        std::int8_t node0_index;
        std::int8_t node1_index;
        EndianType<std::uint16_t> node0_weight;
        ENDIAN_TEMPLATE(NewEndian) operator ModelVertexCompressed<NewEndian>() const {
            ModelVertexCompressed<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(normal);
            COPY_THIS(binormal);
            COPY_THIS(tangent);
            COPY_THIS(texture_coordinate_u);
            COPY_THIS(texture_coordinate_v);
            COPY_THIS(node0_index);
            COPY_THIS(node1_index);
            COPY_THIS(node0_weight);
            return copy;
        }
    };
    static_assert(sizeof(ModelVertexCompressed<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ModelTriangle {
        EndianType<Index> vertex0_index;
        EndianType<Index> vertex1_index;
        EndianType<Index> vertex2_index;
        ENDIAN_TEMPLATE(NewEndian) operator ModelTriangle<NewEndian>() const {
            ModelTriangle<NewEndian> copy;
            COPY_THIS(vertex0_index);
            COPY_THIS(vertex1_index);
            COPY_THIS(vertex2_index);
            return copy;
        }
    };
    static_assert(sizeof(ModelTriangle<NativeEndian>) == 0x6);

    ENDIAN_TEMPLATE(EndianType) struct ModelGeometryPart {
        EndianType<ModelGeometryPartFlags> flags;
        EndianType<Index> shader_index;
        std::uint8_t prev_filthy_part_index;
        std::uint8_t next_filthy_part_index;
        EndianType<Index> centroid_primary_node;
        EndianType<Index> centroid_secondary_node;
        EndianType<Fraction> centroid_primary_weight;
        EndianType<Fraction> centroid_secondary_weight;
        Point3D<EndianType> centroid;
        TagReflexive<EndianType, ModelVertexUncompressed> uncompressed_vertices;
        TagReflexive<EndianType, ModelVertexCompressed> compressed_vertices;
        TagReflexive<EndianType, ModelTriangle> triangles;
        LittleEndian<TriangleBufferType> triangle_buffer_type;
        PAD(0x2);
        LittleEndian<std::uint32_t> triangle_count;
        LittleEndian<std::uint32_t> triangle_offset;
        LittleEndian<std::uint32_t> triangle_offset_2;
        LittleEndian<VertexType> vertex_type;
        PAD(0x2);
        LittleEndian<std::uint32_t> vertex_count;
        PAD(0x4);
        LittleEndian<Pointer> vertex_pointer;
        EndianType<std::uint32_t> vertex_offset;
        ENDIAN_TEMPLATE(NewEndian) operator ModelGeometryPart<NewEndian>() const {
            ModelGeometryPart<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(shader_index);
            COPY_THIS(prev_filthy_part_index);
            COPY_THIS(next_filthy_part_index);
            COPY_THIS(centroid_primary_node);
            COPY_THIS(centroid_secondary_node);
            COPY_THIS(centroid_primary_weight);
            COPY_THIS(centroid_secondary_weight);
            COPY_THIS(centroid);
            COPY_THIS(uncompressed_vertices);
            COPY_THIS(compressed_vertices);
            COPY_THIS(triangles);
            COPY_THIS(triangle_buffer_type);
            COPY_THIS(triangle_count);
            COPY_THIS(triangle_offset);
            COPY_THIS(triangle_offset_2);
            COPY_THIS(vertex_type);
            COPY_THIS(vertex_count);
            COPY_THIS(vertex_pointer);
            COPY_THIS(vertex_offset);
            return copy;
        }
    };
    static_assert(sizeof(ModelGeometryPart<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct GBXModelGeometryPart : ModelGeometryPart<EndianType> {
        PAD(0x1);
        PAD(0x1);
        PAD(0x1);
        std::uint8_t local_node_count;
        std::uint8_t local_node_indices[22];
        PAD(0x2);
        ENDIAN_TEMPLATE(NewEndian) operator GBXModelGeometryPart<NewEndian>() const {
            GBXModelGeometryPart<NewEndian> copy = {};
            COPY_THIS(local_node_count);
            COPY_THIS_ARRAY(local_node_indices);
            COPY_THIS(flags);
            COPY_THIS(shader_index);
            COPY_THIS(prev_filthy_part_index);
            COPY_THIS(next_filthy_part_index);
            COPY_THIS(centroid_primary_node);
            COPY_THIS(centroid_secondary_node);
            COPY_THIS(centroid_primary_weight);
            COPY_THIS(centroid_secondary_weight);
            COPY_THIS(centroid);
            COPY_THIS(uncompressed_vertices);
            COPY_THIS(compressed_vertices);
            COPY_THIS(triangles);
            COPY_THIS(triangle_buffer_type);
            COPY_THIS(triangle_count);
            COPY_THIS(triangle_offset);
            COPY_THIS(triangle_offset_2);
            COPY_THIS(vertex_type);
            COPY_THIS(vertex_count);
            COPY_THIS(vertex_pointer);
            COPY_THIS(vertex_offset);
            return copy;
        }
    };
    static_assert(sizeof(GBXModelGeometryPart<NativeEndian>) == 0x84);

    ENDIAN_TEMPLATE(EndianType) struct GBXModelGeometry {
        EndianType<IsUnusedFlag> flags;
        PAD(0x20);
        TagReflexive<EndianType, GBXModelGeometryPart> parts;
        ENDIAN_TEMPLATE(NewEndian) operator GBXModelGeometry<NewEndian>() const {
            GBXModelGeometry<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(parts);
            return copy;
        }
    };
    static_assert(sizeof(GBXModelGeometry<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ModelMarkerInstance {
        std::uint8_t region_index;
        std::uint8_t permutation_index;
        std::uint8_t node_index;
        PAD(0x1);
        Point3D<EndianType> translation;
        Quaternion<EndianType> rotation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelMarkerInstance<NewEndian>() const {
            ModelMarkerInstance<NewEndian> copy = {};
            COPY_THIS(region_index);
            COPY_THIS(permutation_index);
            COPY_THIS(node_index);
            COPY_THIS(translation);
            COPY_THIS(rotation);
            return copy;
        }
    };
    static_assert(sizeof(ModelMarkerInstance<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ModelMarker {
        TagString name;
        EndianType<std::int16_t> magic_identifier;
        PAD(0x2);
        PAD(0x10);
        TagReflexive<EndianType, ModelMarkerInstance> instances;
        ENDIAN_TEMPLATE(NewEndian) operator ModelMarker<NewEndian>() const {
            ModelMarker<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(magic_identifier);
            COPY_THIS(instances);
            return copy;
        }
    };
    static_assert(sizeof(ModelMarker<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ModelNode {
        TagString name;
        EndianType<Index> next_sibling_node_index;
        EndianType<Index> first_child_node_index;
        EndianType<Index> parent_node_index;
        PAD(0x2);
        Point3D<EndianType> default_translation;
        Quaternion<EndianType> default_rotation;
        EndianType<float> node_distance_from_parent;
        PAD(0x20);
        LittleEndian<float> scale;
        Matrix<LittleEndian> rotation;
        Point3D<LittleEndian> translation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelNode<NewEndian>() const {
            ModelNode<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(next_sibling_node_index);
            COPY_THIS(first_child_node_index);
            COPY_THIS(parent_node_index);
            COPY_THIS(default_translation);
            COPY_THIS(default_rotation);
            COPY_THIS(node_distance_from_parent);
            COPY_THIS(scale);
            COPY_THIS(rotation);
            COPY_THIS(translation);
            return copy;
        }
    };
    static_assert(sizeof(ModelNode<NativeEndian>) == 0x9C);

    ENDIAN_TEMPLATE(EndianType) struct ModelRegionPermutationMarker {
        TagString name;
        EndianType<Index> node_index;
        PAD(0x2);
        Quaternion<EndianType> rotation;
        Point3D<EndianType> translation;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ModelRegionPermutationMarker<NewEndian>() const {
            ModelRegionPermutationMarker<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(node_index);
            COPY_THIS(rotation);
            COPY_THIS(translation);
            return copy;
        }
    };
    static_assert(sizeof(ModelRegionPermutationMarker<NativeEndian>) == 0x50);

    ENDIAN_TEMPLATE(EndianType) struct ModelRegionPermutation {
        TagString name;
        EndianType<ModelRegionPermutationFlags> flags;
        EndianType<std::uint16_t> permutation_number;
        PAD(0x2);
        PAD(0x18);
        EndianType<Index> super_low;
        EndianType<Index> low;
        EndianType<Index> medium;
        EndianType<Index> high;
        EndianType<Index> super_high;
        PAD(0x2);
        TagReflexive<EndianType, ModelRegionPermutationMarker> markers;
        ENDIAN_TEMPLATE(NewEndian) operator ModelRegionPermutation<NewEndian>() const {
            ModelRegionPermutation<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(permutation_number);
            COPY_THIS(super_low);
            COPY_THIS(low);
            COPY_THIS(medium);
            COPY_THIS(high);
            COPY_THIS(super_high);
            COPY_THIS(markers);
            return copy;
        }
    };
    static_assert(sizeof(ModelRegionPermutation<NativeEndian>) == 0x58);

    ENDIAN_TEMPLATE(EndianType) struct ModelRegion {
        TagString name;
        PAD(0x20);
        TagReflexive<EndianType, ModelRegionPermutation> permutations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelRegion<NewEndian>() const {
            ModelRegion<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(permutations);
            return copy;
        }
    };
    static_assert(sizeof(ModelRegion<NativeEndian>) == 0x4C);

    ENDIAN_TEMPLATE(EndianType) struct ModelShaderReference {
        TagDependency<EndianType> shader;
        EndianType<Index> permutation;
        PAD(0x2);
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ModelShaderReference<NewEndian>() const {
            ModelShaderReference<NewEndian> copy = {};
            COPY_THIS(shader);
            COPY_THIS(permutation);
            return copy;
        }
    };
    static_assert(sizeof(ModelShaderReference<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct GBXModel {
        EndianType<ModelFlags> flags;
        EndianType<std::int32_t> node_list_checksum;
        EndianType<float> super_high_detail_cutoff;
        EndianType<float> high_detail_cutoff;
        EndianType<float> medium_detail_cutoff;
        EndianType<float> low_detail_cutoff;
        EndianType<float> super_low_detail_cutoff;
        EndianType<std::uint16_t> super_low_detail_node_count;
        EndianType<std::uint16_t> low_detail_node_count;
        EndianType<std::uint16_t> medium_detail_node_count;
        EndianType<std::uint16_t> high_detail_node_count;
        EndianType<std::uint16_t> super_high_detail_node_count;
        PAD(0x2);
        PAD(0x8);
        EndianType<float> base_map_u_scale;
        EndianType<float> base_map_v_scale;
        PAD(0x74);
        TagReflexive<EndianType, ModelMarker> markers;
        TagReflexive<EndianType, ModelNode> nodes;
        TagReflexive<EndianType, ModelRegion> regions;
        TagReflexive<EndianType, GBXModelGeometry> geometries;
        TagReflexive<EndianType, ModelShaderReference> shaders;
        ENDIAN_TEMPLATE(NewEndian) operator GBXModel<NewEndian>() const {
            GBXModel<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(node_list_checksum);
            COPY_THIS(super_high_detail_cutoff);
            COPY_THIS(high_detail_cutoff);
            COPY_THIS(medium_detail_cutoff);
            COPY_THIS(low_detail_cutoff);
            COPY_THIS(super_low_detail_cutoff);
            COPY_THIS(super_low_detail_node_count);
            COPY_THIS(low_detail_node_count);
            COPY_THIS(medium_detail_node_count);
            COPY_THIS(high_detail_node_count);
            COPY_THIS(super_high_detail_node_count);
            COPY_THIS(base_map_u_scale);
            COPY_THIS(base_map_v_scale);
            COPY_THIS(markers);
            COPY_THIS(nodes);
            COPY_THIS(regions);
            COPY_THIS(geometries);
            COPY_THIS(shaders);
            return copy;
        }
    };
    static_assert(sizeof(GBXModel<NativeEndian>) == 0xE8);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsSound {
        TagDependency<EndianType> sound;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsSound<NewEndian>() const {
            GlobalsSound<NewEndian> copy;
            COPY_THIS(sound);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsSound<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsCamera {
        TagDependency<EndianType> default_unit_camera_track;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsCamera<NewEndian>() const {
            GlobalsCamera<NewEndian> copy;
            COPY_THIS(default_unit_camera_track);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsCamera<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsLookFunction {
        EndianType<float> scale;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsLookFunction<NewEndian>() const {
            GlobalsLookFunction<NewEndian> copy;
            COPY_THIS(scale);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsLookFunction<NativeEndian>) == 0x4);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsPlayerControl {
        EndianType<float> magnetism_friction;
        EndianType<float> magnetism_adhesion;
        EndianType<float> inconsequential_target_scale;
        PAD(0x34);
        EndianType<float> look_acceleration_time;
        EndianType<float> look_acceleration_scale;
        EndianType<float> look_peg_threshold;
        EndianType<float> look_default_pitch_rate;
        EndianType<float> look_default_yaw_rate;
        EndianType<float> look_autolevelling_scale;
        PAD(0x14);
        EndianType<std::int16_t> minimum_weapon_swap_ticks;
        EndianType<std::int16_t> minimum_autolevelling_ticks;
        EndianType<Angle> minimum_angle_for_vehicle_flipping;
        TagReflexive<EndianType, GlobalsLookFunction> look_function;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsPlayerControl<NewEndian>() const {
            GlobalsPlayerControl<NewEndian> copy = {};
            COPY_THIS(magnetism_friction);
            COPY_THIS(magnetism_adhesion);
            COPY_THIS(inconsequential_target_scale);
            COPY_THIS(look_acceleration_time);
            COPY_THIS(look_acceleration_scale);
            COPY_THIS(look_peg_threshold);
            COPY_THIS(look_default_pitch_rate);
            COPY_THIS(look_default_yaw_rate);
            COPY_THIS(look_autolevelling_scale);
            COPY_THIS(minimum_weapon_swap_ticks);
            COPY_THIS(minimum_autolevelling_ticks);
            COPY_THIS(minimum_angle_for_vehicle_flipping);
            COPY_THIS(look_function);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsPlayerControl<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsDifficulty {
        EndianType<float> easy_enemy_damage;
        EndianType<float> normal_enemy_damage;
        EndianType<float> hard_enemy_damage;
        EndianType<float> imposs_enemy_damage;
        EndianType<float> easy_enemy_vitality;
        EndianType<float> normal_enemy_vitality;
        EndianType<float> hard_enemy_vitality;
        EndianType<float> imposs_enemy_vitality;
        EndianType<float> easy_enemy_shield;
        EndianType<float> normal_enemy_shield;
        EndianType<float> hard_enemy_shield;
        EndianType<float> imposs_enemy_shield;
        EndianType<float> easy_enemy_recharge;
        EndianType<float> normal_enemy_recharge;
        EndianType<float> hard_enemy_recharge;
        EndianType<float> imposs_enemy_recharge;
        EndianType<float> easy_friend_damage;
        EndianType<float> normal_friend_damage;
        EndianType<float> hard_friend_damage;
        EndianType<float> imposs_friend_damage;
        EndianType<float> easy_friend_vitality;
        EndianType<float> normal_friend_vitality;
        EndianType<float> hard_friend_vitality;
        EndianType<float> imposs_friend_vitality;
        EndianType<float> easy_friend_shield;
        EndianType<float> normal_friend_shield;
        EndianType<float> hard_friend_shield;
        EndianType<float> imposs_friend_shield;
        EndianType<float> easy_friend_recharge;
        EndianType<float> normal_friend_recharge;
        EndianType<float> hard_friend_recharge;
        EndianType<float> imposs_friend_recharge;
        EndianType<float> easy_infection_forms;
        EndianType<float> normal_infection_forms;
        EndianType<float> hard_infection_forms;
        EndianType<float> imposs_infection_forms;
        PAD(0x10);
        EndianType<float> easy_rate_of_fire;
        EndianType<float> normal_rate_of_fire;
        EndianType<float> hard_rate_of_fire;
        EndianType<float> imposs_rate_of_fire;
        EndianType<float> easy_projectile_error;
        EndianType<float> normal_projectile_error;
        EndianType<float> hard_projectile_error;
        EndianType<float> imposs_projectile_error;
        EndianType<float> easy_burst_error;
        EndianType<float> normal_burst_error;
        EndianType<float> hard_burst_error;
        EndianType<float> imposs_burst_error;
        EndianType<float> easy_new_target_delay;
        EndianType<float> normal_new_target_delay;
        EndianType<float> hard_new_target_delay;
        EndianType<float> imposs_new_target_delay;
        EndianType<float> easy_burst_separation;
        EndianType<float> normal_burst_separation;
        EndianType<float> hard_burst_separation;
        EndianType<float> imposs_burst_separation;
        EndianType<float> easy_target_tracking;
        EndianType<float> normal_target_tracking;
        EndianType<float> hard_target_tracking;
        EndianType<float> imposs_target_tracking;
        EndianType<float> easy_target_leading;
        EndianType<float> normal_target_leading;
        EndianType<float> hard_target_leading;
        EndianType<float> imposs_target_leading;
        EndianType<float> easy_overcharge_chance;
        EndianType<float> normal_overcharge_chance;
        EndianType<float> hard_overcharge_chance;
        EndianType<float> imposs_overcharge_chance;
        EndianType<float> easy_special_fire_delay;
        EndianType<float> normal_special_fire_delay;
        EndianType<float> hard_special_fire_delay;
        EndianType<float> imposs_special_fire_delay;
        EndianType<float> easy_guidance_vs_player;
        EndianType<float> normal_guidance_vs_player;
        EndianType<float> hard_guidance_vs_player;
        EndianType<float> imposs_guidance_vs_player;
        EndianType<float> easy_melee_delay_base;
        EndianType<float> normal_melee_delay_base;
        EndianType<float> hard_melee_delay_base;
        EndianType<float> imposs_melee_delay_base;
        EndianType<float> easy_melee_delay_scale;
        EndianType<float> normal_melee_delay_scale;
        EndianType<float> hard_melee_delay_scale;
        EndianType<float> imposs_melee_delay_scale;
        PAD(0x10);
        EndianType<float> easy_grenade_chance_scale;
        EndianType<float> normal_grenade_chance_scale;
        EndianType<float> hard_grenade_chance_scale;
        EndianType<float> imposs_grenade_chance_scale;
        EndianType<float> easy_grenade_timer_scale;
        EndianType<float> normal_grenade_timer_scale;
        EndianType<float> hard_grenade_timer_scale;
        EndianType<float> imposs_grenade_timer_scale;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        EndianType<float> easy_major_upgrade;
        EndianType<float> normal_major_upgrade;
        EndianType<float> hard_major_upgrade;
        EndianType<float> imposs_major_upgrade;
        EndianType<float> easy_major_upgrade_1;
        EndianType<float> normal_major_upgrade_1;
        EndianType<float> hard_major_upgrade_1;
        EndianType<float> imposs_major_upgrade_1;
        EndianType<float> easy_major_upgrade_2;
        EndianType<float> normal_major_upgrade_2;
        EndianType<float> hard_major_upgrade_2;
        EndianType<float> imposs_major_upgrade_2;
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x10);
        PAD(0x54);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsDifficulty<NewEndian>() const {
            GlobalsDifficulty<NewEndian> copy = {};
            COPY_THIS(easy_enemy_damage);
            COPY_THIS(normal_enemy_damage);
            COPY_THIS(hard_enemy_damage);
            COPY_THIS(imposs_enemy_damage);
            COPY_THIS(easy_enemy_vitality);
            COPY_THIS(normal_enemy_vitality);
            COPY_THIS(hard_enemy_vitality);
            COPY_THIS(imposs_enemy_vitality);
            COPY_THIS(easy_enemy_shield);
            COPY_THIS(normal_enemy_shield);
            COPY_THIS(hard_enemy_shield);
            COPY_THIS(imposs_enemy_shield);
            COPY_THIS(easy_enemy_recharge);
            COPY_THIS(normal_enemy_recharge);
            COPY_THIS(hard_enemy_recharge);
            COPY_THIS(imposs_enemy_recharge);
            COPY_THIS(easy_friend_damage);
            COPY_THIS(normal_friend_damage);
            COPY_THIS(hard_friend_damage);
            COPY_THIS(imposs_friend_damage);
            COPY_THIS(easy_friend_vitality);
            COPY_THIS(normal_friend_vitality);
            COPY_THIS(hard_friend_vitality);
            COPY_THIS(imposs_friend_vitality);
            COPY_THIS(easy_friend_shield);
            COPY_THIS(normal_friend_shield);
            COPY_THIS(hard_friend_shield);
            COPY_THIS(imposs_friend_shield);
            COPY_THIS(easy_friend_recharge);
            COPY_THIS(normal_friend_recharge);
            COPY_THIS(hard_friend_recharge);
            COPY_THIS(imposs_friend_recharge);
            COPY_THIS(easy_infection_forms);
            COPY_THIS(normal_infection_forms);
            COPY_THIS(hard_infection_forms);
            COPY_THIS(imposs_infection_forms);
            COPY_THIS(easy_rate_of_fire);
            COPY_THIS(normal_rate_of_fire);
            COPY_THIS(hard_rate_of_fire);
            COPY_THIS(imposs_rate_of_fire);
            COPY_THIS(easy_projectile_error);
            COPY_THIS(normal_projectile_error);
            COPY_THIS(hard_projectile_error);
            COPY_THIS(imposs_projectile_error);
            COPY_THIS(easy_burst_error);
            COPY_THIS(normal_burst_error);
            COPY_THIS(hard_burst_error);
            COPY_THIS(imposs_burst_error);
            COPY_THIS(easy_new_target_delay);
            COPY_THIS(normal_new_target_delay);
            COPY_THIS(hard_new_target_delay);
            COPY_THIS(imposs_new_target_delay);
            COPY_THIS(easy_burst_separation);
            COPY_THIS(normal_burst_separation);
            COPY_THIS(hard_burst_separation);
            COPY_THIS(imposs_burst_separation);
            COPY_THIS(easy_target_tracking);
            COPY_THIS(normal_target_tracking);
            COPY_THIS(hard_target_tracking);
            COPY_THIS(imposs_target_tracking);
            COPY_THIS(easy_target_leading);
            COPY_THIS(normal_target_leading);
            COPY_THIS(hard_target_leading);
            COPY_THIS(imposs_target_leading);
            COPY_THIS(easy_overcharge_chance);
            COPY_THIS(normal_overcharge_chance);
            COPY_THIS(hard_overcharge_chance);
            COPY_THIS(imposs_overcharge_chance);
            COPY_THIS(easy_special_fire_delay);
            COPY_THIS(normal_special_fire_delay);
            COPY_THIS(hard_special_fire_delay);
            COPY_THIS(imposs_special_fire_delay);
            COPY_THIS(easy_guidance_vs_player);
            COPY_THIS(normal_guidance_vs_player);
            COPY_THIS(hard_guidance_vs_player);
            COPY_THIS(imposs_guidance_vs_player);
            COPY_THIS(easy_melee_delay_base);
            COPY_THIS(normal_melee_delay_base);
            COPY_THIS(hard_melee_delay_base);
            COPY_THIS(imposs_melee_delay_base);
            COPY_THIS(easy_melee_delay_scale);
            COPY_THIS(normal_melee_delay_scale);
            COPY_THIS(hard_melee_delay_scale);
            COPY_THIS(imposs_melee_delay_scale);
            COPY_THIS(easy_grenade_chance_scale);
            COPY_THIS(normal_grenade_chance_scale);
            COPY_THIS(hard_grenade_chance_scale);
            COPY_THIS(imposs_grenade_chance_scale);
            COPY_THIS(easy_grenade_timer_scale);
            COPY_THIS(normal_grenade_timer_scale);
            COPY_THIS(hard_grenade_timer_scale);
            COPY_THIS(imposs_grenade_timer_scale);
            COPY_THIS(easy_major_upgrade);
            COPY_THIS(normal_major_upgrade);
            COPY_THIS(hard_major_upgrade);
            COPY_THIS(imposs_major_upgrade);
            COPY_THIS(easy_major_upgrade_1);
            COPY_THIS(normal_major_upgrade_1);
            COPY_THIS(hard_major_upgrade_1);
            COPY_THIS(imposs_major_upgrade_1);
            COPY_THIS(easy_major_upgrade_2);
            COPY_THIS(normal_major_upgrade_2);
            COPY_THIS(hard_major_upgrade_2);
            COPY_THIS(imposs_major_upgrade_2);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsDifficulty<NativeEndian>) == 0x284);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsGrenade {
        EndianType<std::int16_t> maximum_count;
        EndianType<std::int16_t> mp_spawn_default;
        TagDependency<EndianType> throwing_effect;
        TagDependency<EndianType> hud_interface;
        TagDependency<EndianType> equipment;
        TagDependency<EndianType> projectile;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsGrenade<NewEndian>() const {
            GlobalsGrenade<NewEndian> copy;
            COPY_THIS(maximum_count);
            COPY_THIS(mp_spawn_default);
            COPY_THIS(throwing_effect);
            COPY_THIS(hud_interface);
            COPY_THIS(equipment);
            COPY_THIS(projectile);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsGrenade<NativeEndian>) == 0x44);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsRasterizerData {
        TagDependency<EndianType> distance_attenuation;
        TagDependency<EndianType> vector_normalization;
        TagDependency<EndianType> atmospheric_fog_density;
        TagDependency<EndianType> planar_fog_density;
        TagDependency<EndianType> linear_corner_fade;
        TagDependency<EndianType> active_camouflage_distortion;
        TagDependency<EndianType> glow;
        PAD(0x3C);
        TagDependency<EndianType> default_2d;
        TagDependency<EndianType> default_3d;
        TagDependency<EndianType> default_cube_map;
        TagDependency<EndianType> test_0;
        TagDependency<EndianType> test_1;
        TagDependency<EndianType> test_2;
        TagDependency<EndianType> test_3;
        TagDependency<EndianType> video_scanline_map;
        TagDependency<EndianType> video_noise_map;
        PAD(0x34);
        EndianType<GlobalsRasterizerDataFlags> flags;
        PAD(0x2);
        EndianType<float> refraction_amount;
        EndianType<float> distance_falloff;
        ColorRGB<EndianType> tint_color;
        EndianType<float> hyper_stealth_refraction;
        EndianType<float> hyper_stealth_distance_falloff;
        ColorRGB<EndianType> hyper_stealth_tint_color;
        TagDependency<EndianType> distance_attenuation_2d;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsRasterizerData<NewEndian>() const {
            GlobalsRasterizerData<NewEndian> copy = {};
            COPY_THIS(distance_attenuation);
            COPY_THIS(vector_normalization);
            COPY_THIS(atmospheric_fog_density);
            COPY_THIS(planar_fog_density);
            COPY_THIS(linear_corner_fade);
            COPY_THIS(active_camouflage_distortion);
            COPY_THIS(glow);
            COPY_THIS(default_2d);
            COPY_THIS(default_3d);
            COPY_THIS(default_cube_map);
            COPY_THIS(test_0);
            COPY_THIS(test_1);
            COPY_THIS(test_2);
            COPY_THIS(test_3);
            COPY_THIS(video_scanline_map);
            COPY_THIS(video_noise_map);
            COPY_THIS(flags);
            COPY_THIS(refraction_amount);
            COPY_THIS(distance_falloff);
            COPY_THIS(tint_color);
            COPY_THIS(hyper_stealth_refraction);
            COPY_THIS(hyper_stealth_distance_falloff);
            COPY_THIS(hyper_stealth_tint_color);
            COPY_THIS(distance_attenuation_2d);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsRasterizerData<NativeEndian>) == 0x1AC);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsInterfaceBitmaps {
        TagDependency<EndianType> font_system;
        TagDependency<EndianType> font_terminal;
        TagDependency<EndianType> screen_color_table;
        TagDependency<EndianType> hud_color_table;
        TagDependency<EndianType> editor_color_table;
        TagDependency<EndianType> dialog_color_table;
        TagDependency<EndianType> hud_globals;
        TagDependency<EndianType> motion_sensor_sweep_bitmap;
        TagDependency<EndianType> motion_sensor_sweep_bitmap_mask;
        TagDependency<EndianType> multiplayer_hud_bitmap;
        TagDependency<EndianType> localization;
        TagDependency<EndianType> hud_digits_definition;
        TagDependency<EndianType> motion_sensor_blip_bitmap;
        TagDependency<EndianType> interface_goo_map1;
        TagDependency<EndianType> interface_goo_map2;
        TagDependency<EndianType> interface_goo_map3;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsInterfaceBitmaps<NewEndian>() const {
            GlobalsInterfaceBitmaps<NewEndian> copy = {};
            COPY_THIS(font_system);
            COPY_THIS(font_terminal);
            COPY_THIS(screen_color_table);
            COPY_THIS(hud_color_table);
            COPY_THIS(editor_color_table);
            COPY_THIS(dialog_color_table);
            COPY_THIS(hud_globals);
            COPY_THIS(motion_sensor_sweep_bitmap);
            COPY_THIS(motion_sensor_sweep_bitmap_mask);
            COPY_THIS(multiplayer_hud_bitmap);
            COPY_THIS(localization);
            COPY_THIS(hud_digits_definition);
            COPY_THIS(motion_sensor_blip_bitmap);
            COPY_THIS(interface_goo_map1);
            COPY_THIS(interface_goo_map2);
            COPY_THIS(interface_goo_map3);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsInterfaceBitmaps<NativeEndian>) == 0x130);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsWeapon {
        TagDependency<EndianType> weapon;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsWeapon<NewEndian>() const {
            GlobalsWeapon<NewEndian> copy;
            COPY_THIS(weapon);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsWeapon<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsCheatPowerup {
        TagDependency<EndianType> powerup;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsCheatPowerup<NewEndian>() const {
            GlobalsCheatPowerup<NewEndian> copy;
            COPY_THIS(powerup);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsCheatPowerup<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsVehicle {
        TagDependency<EndianType> vehicle;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsVehicle<NewEndian>() const {
            GlobalsVehicle<NewEndian> copy;
            COPY_THIS(vehicle);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsVehicle<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsMultiplayerInformation {
        TagDependency<EndianType> flag;
        TagDependency<EndianType> unit;
        TagReflexive<EndianType, GlobalsVehicle> vehicles;
        TagDependency<EndianType> hill_shader;
        TagDependency<EndianType> flag_shader;
        TagDependency<EndianType> ball;
        TagReflexive<EndianType, GlobalsSound> sounds;
        PAD(0x38);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsMultiplayerInformation<NewEndian>() const {
            GlobalsMultiplayerInformation<NewEndian> copy = {};
            COPY_THIS(flag);
            COPY_THIS(unit);
            COPY_THIS(vehicles);
            COPY_THIS(hill_shader);
            COPY_THIS(flag_shader);
            COPY_THIS(ball);
            COPY_THIS(sounds);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsMultiplayerInformation<NativeEndian>) == 0xA0);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsPlayerInformation {
        TagDependency<EndianType> unit;
        PAD(0x1C);
        EndianType<float> walking_speed;
        EndianType<float> double_speed_multiplier;
        EndianType<float> run_forward;
        EndianType<float> run_backward;
        EndianType<float> run_sideways;
        EndianType<float> run_acceleration;
        EndianType<float> sneak_forward;
        EndianType<float> sneak_backward;
        EndianType<float> sneak_sideways;
        EndianType<float> sneak_acceleration;
        EndianType<float> airborne_acceleration;
        EndianType<float> speed_multiplier;
        PAD(0xC);
        Point3D<EndianType> grenade_origin;
        PAD(0xC);
        EndianType<float> stun_movement_penalty;
        EndianType<float> stun_turning_penalty;
        EndianType<float> stun_jumping_penalty;
        EndianType<float> minimum_stun_time;
        EndianType<float> maximum_stun_time;
        PAD(0x8);
        Bounds<EndianType<float>> first_person_idle_time;
        EndianType<float> first_person_skip_fraction;
        PAD(0x10);
        TagDependency<EndianType> coop_respawn_effect;
        PAD(0x2C);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsPlayerInformation<NewEndian>() const {
            GlobalsPlayerInformation<NewEndian> copy = {};
            COPY_THIS(unit);
            COPY_THIS(walking_speed);
            COPY_THIS(double_speed_multiplier);
            COPY_THIS(run_forward);
            COPY_THIS(run_backward);
            COPY_THIS(run_sideways);
            COPY_THIS(run_acceleration);
            COPY_THIS(sneak_forward);
            COPY_THIS(sneak_backward);
            COPY_THIS(sneak_sideways);
            COPY_THIS(sneak_acceleration);
            COPY_THIS(airborne_acceleration);
            COPY_THIS(speed_multiplier);
            COPY_THIS(grenade_origin);
            COPY_THIS(stun_movement_penalty);
            COPY_THIS(stun_turning_penalty);
            COPY_THIS(stun_jumping_penalty);
            COPY_THIS(minimum_stun_time);
            COPY_THIS(maximum_stun_time);
            COPY_THIS(first_person_idle_time);
            COPY_THIS(first_person_skip_fraction);
            COPY_THIS(coop_respawn_effect);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsPlayerInformation<NativeEndian>) == 0xF4);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsFirstPersonInterface {
        TagDependency<EndianType> first_person_hands;
        TagDependency<EndianType> base_bitmap;
        TagDependency<EndianType> shield_meter;
        Point2DInt<EndianType> shield_meter_origin;
        TagDependency<EndianType> body_meter;
        Point2DInt<EndianType> body_meter_origin;
        TagDependency<EndianType> night_vision_on_effect;
        TagDependency<EndianType> night_vision_off_effect;
        PAD(0x58);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsFirstPersonInterface<NewEndian>() const {
            GlobalsFirstPersonInterface<NewEndian> copy = {};
            COPY_THIS(first_person_hands);
            COPY_THIS(base_bitmap);
            COPY_THIS(shield_meter);
            COPY_THIS(shield_meter_origin);
            COPY_THIS(body_meter);
            COPY_THIS(body_meter_origin);
            COPY_THIS(night_vision_on_effect);
            COPY_THIS(night_vision_off_effect);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsFirstPersonInterface<NativeEndian>) == 0xC0);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsFallingDamage {
        PAD(0x8);
        Bounds<EndianType<float>> harmful_falling_distance;
        TagDependency<EndianType> falling_damage;
        PAD(0x8);
        EndianType<float> maximum_falling_distance;
        TagDependency<EndianType> distance_damage;
        TagDependency<EndianType> vehicle_environment_collision_damage;
        TagDependency<EndianType> vehicle_killed_unit_damage;
        TagDependency<EndianType> vehicle_collision_damage;
        TagDependency<EndianType> flaming_death_damage;
        PAD(0x10);
        LittleEndian<float> maximum_falling_velocity;
        Bounds<LittleEndian<float>> harmful_falling_velocity;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsFallingDamage<NewEndian>() const {
            GlobalsFallingDamage<NewEndian> copy = {};
            COPY_THIS(harmful_falling_distance);
            COPY_THIS(falling_damage);
            COPY_THIS(maximum_falling_distance);
            COPY_THIS(distance_damage);
            COPY_THIS(vehicle_environment_collision_damage);
            COPY_THIS(vehicle_killed_unit_damage);
            COPY_THIS(vehicle_collision_damage);
            COPY_THIS(flaming_death_damage);
            COPY_THIS(maximum_falling_velocity);
            COPY_THIS(harmful_falling_velocity);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsFallingDamage<NativeEndian>) == 0x98);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsBreakableSurfaceParticleEffect {
        TagDependency<EndianType> particle_type;
        EndianType<GlobalsBreakableSurfaceParticleEffectFlags> flags;
        EndianType<float> density;
        Bounds<EndianType<float>> velocity_scale;
        PAD(0x4);
        Bounds<EndianType<float>> angular_velocity;
        PAD(0x8);
        Bounds<EndianType<float>> radius;
        PAD(0x8);
        ColorARGB<EndianType> tint_lower_bound;
        ColorARGB<EndianType> tint_upper_bound;
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsBreakableSurfaceParticleEffect<NewEndian>() const {
            GlobalsBreakableSurfaceParticleEffect<NewEndian> copy = {};
            COPY_THIS(particle_type);
            COPY_THIS(flags);
            COPY_THIS(density);
            COPY_THIS(velocity_scale);
            COPY_THIS(angular_velocity);
            COPY_THIS(radius);
            COPY_THIS(tint_lower_bound);
            COPY_THIS(tint_upper_bound);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsBreakableSurfaceParticleEffect<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsMaterial {
        PAD(0x64);
        PAD(0x30);
        EndianType<float> ground_friction_scale;
        EndianType<float> ground_friction_normal_k1_scale;
        EndianType<float> ground_friction_normal_k0_scale;
        EndianType<float> ground_depth_scale;
        EndianType<float> ground_damp_fraction_scale;
        PAD(0x4C);
        PAD(0x1E0);
        EndianType<float> maximum_vitality;
        PAD(0x8);
        PAD(0x4);
        TagDependency<EndianType> effect;
        TagDependency<EndianType> sound;
        PAD(0x18);
        TagReflexive<EndianType, GlobalsBreakableSurfaceParticleEffect> particle_effects;
        PAD(0x3C);
        TagDependency<EndianType> melee_hit_sound;
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsMaterial<NewEndian>() const {
            GlobalsMaterial<NewEndian> copy = {};
            COPY_THIS(ground_friction_scale);
            COPY_THIS(ground_friction_normal_k1_scale);
            COPY_THIS(ground_friction_normal_k0_scale);
            COPY_THIS(ground_depth_scale);
            COPY_THIS(ground_damp_fraction_scale);
            COPY_THIS(maximum_vitality);
            COPY_THIS(effect);
            COPY_THIS(sound);
            COPY_THIS(particle_effects);
            COPY_THIS(melee_hit_sound);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsMaterial<NativeEndian>) == 0x374);

    ENDIAN_TEMPLATE(EndianType) struct GlobalsPlaylistMember {
        TagString map_name;
        TagString game_variant;
        EndianType<std::int32_t> minimum_experience;
        EndianType<std::int32_t> maximum_experience;
        EndianType<std::int32_t> minimum_player_count;
        EndianType<std::int32_t> maximum_player_count;
        EndianType<std::int32_t> rating;
        PAD(0x40);
        ENDIAN_TEMPLATE(NewEndian) operator GlobalsPlaylistMember<NewEndian>() const {
            GlobalsPlaylistMember<NewEndian> copy = {};
            COPY_THIS(map_name);
            COPY_THIS(game_variant);
            COPY_THIS(minimum_experience);
            COPY_THIS(maximum_experience);
            COPY_THIS(minimum_player_count);
            COPY_THIS(maximum_player_count);
            COPY_THIS(rating);
            return copy;
        }
    };
    static_assert(sizeof(GlobalsPlaylistMember<NativeEndian>) == 0x94);

    ENDIAN_TEMPLATE(EndianType) struct Globals {
        PAD(0xF8);
        TagReflexive<EndianType, GlobalsSound> sounds;
        TagReflexive<EndianType, GlobalsCamera> camera;
        TagReflexive<EndianType, GlobalsPlayerControl> player_control;
        TagReflexive<EndianType, GlobalsDifficulty> difficulty;
        TagReflexive<EndianType, GlobalsGrenade> grenades;
        TagReflexive<EndianType, GlobalsRasterizerData> rasterizer_data;
        TagReflexive<EndianType, GlobalsInterfaceBitmaps> interface_bitmaps;
        TagReflexive<EndianType, GlobalsWeapon> weapon_list;
        TagReflexive<EndianType, GlobalsCheatPowerup> cheat_powerups;
        TagReflexive<EndianType, GlobalsMultiplayerInformation> multiplayer_information;
        TagReflexive<EndianType, GlobalsPlayerInformation> player_information;
        TagReflexive<EndianType, GlobalsFirstPersonInterface> first_person_interface;
        TagReflexive<EndianType, GlobalsFallingDamage> falling_damage;
        TagReflexive<EndianType, GlobalsMaterial> materials;
        TagReflexive<EndianType, GlobalsPlaylistMember> playlist_members;
        ENDIAN_TEMPLATE(NewEndian) operator Globals<NewEndian>() const {
            Globals<NewEndian> copy = {};
            COPY_THIS(sounds);
            COPY_THIS(camera);
            COPY_THIS(player_control);
            COPY_THIS(difficulty);
            COPY_THIS(grenades);
            COPY_THIS(rasterizer_data);
            COPY_THIS(interface_bitmaps);
            COPY_THIS(weapon_list);
            COPY_THIS(cheat_powerups);
            COPY_THIS(multiplayer_information);
            COPY_THIS(player_information);
            COPY_THIS(first_person_interface);
            COPY_THIS(falling_damage);
            COPY_THIS(materials);
            COPY_THIS(playlist_members);
            return copy;
        }
    };
    static_assert(sizeof(Globals<NativeEndian>) == 0x1AC);

    ENDIAN_TEMPLATE(EndianType) struct Glow {
        TagString attachment_marker;
        EndianType<std::int16_t> number_of_particles;
        EndianType<GlowBoundaryEffect> boundary_effect;
        EndianType<GlowNormalParticleDistribution> normal_particle_distribution;
        EndianType<GlowTrailingParticleDistribution> trailing_particle_distribution;
        EndianType<GlowFlags> glow_flags;
        PAD(0x1C);
        PAD(0x2);
        PAD(0x2);
        PAD(0x4);
        EndianType<FunctionOut> attachment_0;
        PAD(0x2);
        EndianType<float> particle_rotational_velocity;
        EndianType<float> particle_rot_vel_mul_low;
        EndianType<float> particle_rot_vel_mul_high;
        EndianType<FunctionOut> attachment_1;
        PAD(0x2);
        EndianType<float> effect_rotational_velocity;
        EndianType<float> effect_rot_vel_mul_low;
        EndianType<float> effect_rot_vel_mul_high;
        EndianType<FunctionOut> attachment_2;
        PAD(0x2);
        EndianType<float> effect_translational_velocity;
        EndianType<float> effect_trans_vel_mul_low;
        EndianType<float> effect_trans_vel_mul_high;
        EndianType<FunctionOut> attachment_3;
        PAD(0x2);
        EndianType<float> min_distance_particle_to_object;
        EndianType<float> max_distance_particle_to_object;
        EndianType<float> distance_to_object_mul_low;
        EndianType<float> distance_to_object_mul_high;
        PAD(0x8);
        EndianType<FunctionOut> attachment_4;
        PAD(0x2);
        Bounds<EndianType<float>> particle_size_bounds;
        Bounds<EndianType<float>> size_attachment_multiplier;
        EndianType<FunctionOut> attachment_5;
        PAD(0x2);
        ColorARGB<EndianType> color_bound_0;
        ColorARGB<EndianType> color_bound_1;
        ColorARGB<EndianType> scale_color_0;
        ColorARGB<EndianType> scale_color_1;
        EndianType<float> color_rate_of_change;
        EndianType<float> fading_percentage_of_glow;
        EndianType<float> particle_generation_freq;
        EndianType<float> lifetime_of_trailing_particles;
        EndianType<float> velocity_of_trailing_particles;
        EndianType<float> trailing_particle_minimum_t;
        EndianType<float> trailing_particle_maximum_t;
        PAD(0x34);
        TagDependency<EndianType> texture;
        ENDIAN_TEMPLATE(NewEndian) operator Glow<NewEndian>() const {
            Glow<NewEndian> copy = {};
            COPY_THIS(attachment_marker);
            COPY_THIS(number_of_particles);
            COPY_THIS(boundary_effect);
            COPY_THIS(normal_particle_distribution);
            COPY_THIS(trailing_particle_distribution);
            COPY_THIS(glow_flags);
            COPY_THIS(attachment_0);
            COPY_THIS(particle_rotational_velocity);
            COPY_THIS(particle_rot_vel_mul_low);
            COPY_THIS(particle_rot_vel_mul_high);
            COPY_THIS(attachment_1);
            COPY_THIS(effect_rotational_velocity);
            COPY_THIS(effect_rot_vel_mul_low);
            COPY_THIS(effect_rot_vel_mul_high);
            COPY_THIS(attachment_2);
            COPY_THIS(effect_translational_velocity);
            COPY_THIS(effect_trans_vel_mul_low);
            COPY_THIS(effect_trans_vel_mul_high);
            COPY_THIS(attachment_3);
            COPY_THIS(min_distance_particle_to_object);
            COPY_THIS(max_distance_particle_to_object);
            COPY_THIS(distance_to_object_mul_low);
            COPY_THIS(distance_to_object_mul_high);
            COPY_THIS(attachment_4);
            COPY_THIS(particle_size_bounds);
            COPY_THIS(size_attachment_multiplier);
            COPY_THIS(attachment_5);
            COPY_THIS(color_bound_0);
            COPY_THIS(color_bound_1);
            COPY_THIS(scale_color_0);
            COPY_THIS(scale_color_1);
            COPY_THIS(color_rate_of_change);
            COPY_THIS(fading_percentage_of_glow);
            COPY_THIS(particle_generation_freq);
            COPY_THIS(lifetime_of_trailing_particles);
            COPY_THIS(velocity_of_trailing_particles);
            COPY_THIS(trailing_particle_minimum_t);
            COPY_THIS(trailing_particle_maximum_t);
            COPY_THIS(texture);
            return copy;
        }
    };
    static_assert(sizeof(Glow<NativeEndian>) == 0x154);

    ENDIAN_TEMPLATE(EndianType) struct GrenadeHUDInterfaceOverlay {
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        EndianType<ColorARGBInt> default_color;
        EndianType<ColorARGBInt> flashing_color;
        EndianType<float> flash_period;
        EndianType<float> flash_delay;
        EndianType<std::int16_t> number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> flash_flags;
        EndianType<float> flash_length;
        EndianType<ColorARGBInt> disabled_color;
        PAD(0x4);
        EndianType<float> frame_rate;
        EndianType<Index> sequence_index;
        EndianType<GrenadeHUDInterfaceOverlayType> type;
        EndianType<HUDInterfaceOverlayFlashFlags> flags;
        PAD(0x10);
        PAD(0x28);
        ENDIAN_TEMPLATE(NewEndian) operator GrenadeHUDInterfaceOverlay<NewEndian>() const {
            GrenadeHUDInterfaceOverlay<NewEndian> copy = {};
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(default_color);
            COPY_THIS(flashing_color);
            COPY_THIS(flash_period);
            COPY_THIS(flash_delay);
            COPY_THIS(number_of_flashes);
            COPY_THIS(flash_flags);
            COPY_THIS(flash_length);
            COPY_THIS(disabled_color);
            COPY_THIS(frame_rate);
            COPY_THIS(sequence_index);
            COPY_THIS(type);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(GrenadeHUDInterfaceOverlay<NativeEndian>) == 0x88);

    ENDIAN_TEMPLATE(EndianType) struct GrenadeHUDInterfaceSound {
        TagDependency<EndianType> sound;
        EndianType<GrenadeHUDInterfaceSoundLatchedTo> latched_to;
        EndianType<float> scale;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator GrenadeHUDInterfaceSound<NewEndian>() const {
            GrenadeHUDInterfaceSound<NewEndian> copy = {};
            COPY_THIS(sound);
            COPY_THIS(latched_to);
            COPY_THIS(scale);
            return copy;
        }
    };
    static_assert(sizeof(GrenadeHUDInterfaceSound<NativeEndian>) == 0x38);

    ENDIAN_TEMPLATE(EndianType) struct HUDInterfaceMultitextureOverlayEffector {
        PAD(0x40);
        EndianType<HUDInterfaceDestinationType> destination_type;
        EndianType<HUDInterfaceDestination> destination;
        EndianType<HUDInterfaceSource> source;
        PAD(0x2);
        Bounds<EndianType<float>> in_bounds;
        Bounds<EndianType<float>> out_bounds;
        PAD(0x40);
        ColorRGB<EndianType> tint_color_lower_bound;
        ColorRGB<EndianType> tint_color_upper_bound;
        EndianType<WaveFunction> periodic_function;
        PAD(0x2);
        EndianType<float> function_period;
        EndianType<float> function_phase;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator HUDInterfaceMultitextureOverlayEffector<NewEndian>() const {
            HUDInterfaceMultitextureOverlayEffector<NewEndian> copy = {};
            COPY_THIS(destination_type);
            COPY_THIS(destination);
            COPY_THIS(source);
            COPY_THIS(in_bounds);
            COPY_THIS(out_bounds);
            COPY_THIS(tint_color_lower_bound);
            COPY_THIS(tint_color_upper_bound);
            COPY_THIS(periodic_function);
            COPY_THIS(function_period);
            COPY_THIS(function_phase);
            return copy;
        }
    };
    static_assert(sizeof(HUDInterfaceMultitextureOverlayEffector<NativeEndian>) == 0xDC);

    ENDIAN_TEMPLATE(EndianType) struct HUDInterfaceMultitextureOverlay {
        PAD(0x2);
        EndianType<std::int16_t> type;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        PAD(0x2);
        PAD(0x20);
        EndianType<HUDInterfaceMultitextureOverlayAnchor> primary_anchor;
        EndianType<HUDInterfaceMultitextureOverlayAnchor> secondary_anchor;
        EndianType<HUDInterfaceMultitextureOverlayAnchor> tertiary_anchor;
        EndianType<HUDInterfaceZeroToOneBlendFunction> zero_to_one_blend_function;
        EndianType<HUDInterfaceZeroToOneBlendFunction> one_to_two_blend_function;
        PAD(0x2);
        Point2D<EndianType> primary_scale;
        Point2D<EndianType> secondary_scale;
        Point2D<EndianType> tertiary_scale;
        Point2D<EndianType> primary_offset;
        Point2D<EndianType> secondary_offset;
        Point2D<EndianType> tertiary_offset;
        TagDependency<EndianType> primary;
        TagDependency<EndianType> secondary;
        TagDependency<EndianType> tertiary;
        EndianType<HUDInterfaceWrapMode> primary_wrap_mode;
        EndianType<HUDInterfaceWrapMode> secondary_wrap_mode;
        EndianType<HUDInterfaceWrapMode> tertiary_wrap_mode;
        PAD(0x2);
        PAD(0xB8);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlayEffector> effectors;
        PAD(0x80);
        ENDIAN_TEMPLATE(NewEndian) operator HUDInterfaceMultitextureOverlay<NewEndian>() const {
            HUDInterfaceMultitextureOverlay<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(primary_anchor);
            COPY_THIS(secondary_anchor);
            COPY_THIS(tertiary_anchor);
            COPY_THIS(zero_to_one_blend_function);
            COPY_THIS(one_to_two_blend_function);
            COPY_THIS(primary_scale);
            COPY_THIS(secondary_scale);
            COPY_THIS(tertiary_scale);
            COPY_THIS(primary_offset);
            COPY_THIS(secondary_offset);
            COPY_THIS(tertiary_offset);
            COPY_THIS(primary);
            COPY_THIS(secondary);
            COPY_THIS(tertiary);
            COPY_THIS(primary_wrap_mode);
            COPY_THIS(secondary_wrap_mode);
            COPY_THIS(tertiary_wrap_mode);
            COPY_THIS(effectors);
            return copy;
        }
    };
    static_assert(sizeof(HUDInterfaceMultitextureOverlay<NativeEndian>) == 0x1E0);

    ENDIAN_TEMPLATE(EndianType) struct GrenadeHUDInterface {
        EndianType<HUDInterfaceAnchor> anchor;
        PAD(0x2);
        PAD(0x20);
        Point2DInt<EndianType> background_anchor_offset;
        EndianType<float> background_width_scale;
        EndianType<float> background_height_scale;
        EndianType<HUDInterfaceScalingFlags> background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> background_interface_bitmap;
        EndianType<ColorARGBInt> background_default_color;
        EndianType<ColorARGBInt> background_flashing_color;
        EndianType<float> background_flash_period;
        EndianType<float> background_flash_delay;
        EndianType<std::int16_t> background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> background_flash_flags;
        EndianType<float> background_flash_length;
        EndianType<ColorARGBInt> background_disabled_color;
        PAD(0x4);
        EndianType<Index> background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> total_grenades_background_anchor_offset;
        EndianType<float> total_grenades_background_width_scale;
        EndianType<float> total_grenades_background_height_scale;
        EndianType<HUDInterfaceScalingFlags> total_grenades_background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> total_grenades_background_interface_bitmap;
        EndianType<ColorARGBInt> total_grenades_background_default_color;
        EndianType<ColorARGBInt> total_grenades_background_flashing_color;
        EndianType<float> total_grenades_background_flash_period;
        EndianType<float> total_grenades_background_flash_delay;
        EndianType<std::int16_t> total_grenades_background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> total_grenades_background_flash_flags;
        EndianType<float> total_grenades_background_flash_length;
        EndianType<ColorARGBInt> total_grenades_background_disabled_color;
        PAD(0x4);
        EndianType<Index> total_grenades_background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> total_grenades_background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> total_grenades_numbers_anchor_offset;
        EndianType<float> total_grenades_numbers_width_scale;
        EndianType<float> total_grenades_numbers_height_scale;
        EndianType<HUDInterfaceScalingFlags> total_grenades_numbers_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        EndianType<ColorARGBInt> total_grenades_numbers_default_color;
        EndianType<ColorARGBInt> total_grenades_numbers_flashing_color;
        EndianType<float> total_grenades_numbers_flash_period;
        EndianType<float> total_grenades_numbers_flash_delay;
        EndianType<std::int16_t> total_grenades_numbers_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> total_grenades_numbers_flash_flags;
        EndianType<float> total_grenades_numbers_flash_length;
        EndianType<ColorARGBInt> total_grenades_numbers_disabled_color;
        PAD(0x4);
        std::int8_t total_grenades_numbers_maximum_number_of_digits;
        HUDInterfaceNumberFlags total_grenades_numbers_flags;
        std::int8_t total_grenades_numbers_number_of_fractional_digits;
        PAD(0x1);
        PAD(0xC);
        EndianType<std::int16_t> flash_cutoff;
        PAD(0x2);
        TagDependency<EndianType> total_grenades_overlay_bitmap;
        TagReflexive<EndianType, GrenadeHUDInterfaceOverlay> total_grenades_overlays;
        TagReflexive<EndianType, GrenadeHUDInterfaceSound> total_grenades_warning_sounds;
        PAD(0x44);
        EndianType<Index> messaging_information_sequence_index;
        EndianType<std::int16_t> messaging_information_width_offset;
        Point2DInt<EndianType> messaging_information_offset_from_reference_corner;
        EndianType<ColorARGBInt> messaging_information_override_icon_color;
        std::int8_t messaging_information_frame_rate;
        HUDInterfaceMessagingFlags messaging_information_flags;
        EndianType<Index> messaging_information_text_index;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator GrenadeHUDInterface<NewEndian>() const {
            GrenadeHUDInterface<NewEndian> copy = {};
            COPY_THIS(anchor);
            COPY_THIS(background_anchor_offset);
            COPY_THIS(background_width_scale);
            COPY_THIS(background_height_scale);
            COPY_THIS(background_scaling_flags);
            COPY_THIS(background_interface_bitmap);
            COPY_THIS(background_default_color);
            COPY_THIS(background_flashing_color);
            COPY_THIS(background_flash_period);
            COPY_THIS(background_flash_delay);
            COPY_THIS(background_number_of_flashes);
            COPY_THIS(background_flash_flags);
            COPY_THIS(background_flash_length);
            COPY_THIS(background_disabled_color);
            COPY_THIS(background_sequence_index);
            COPY_THIS(background_multitexture_overlays);
            COPY_THIS(total_grenades_background_anchor_offset);
            COPY_THIS(total_grenades_background_width_scale);
            COPY_THIS(total_grenades_background_height_scale);
            COPY_THIS(total_grenades_background_scaling_flags);
            COPY_THIS(total_grenades_background_interface_bitmap);
            COPY_THIS(total_grenades_background_default_color);
            COPY_THIS(total_grenades_background_flashing_color);
            COPY_THIS(total_grenades_background_flash_period);
            COPY_THIS(total_grenades_background_flash_delay);
            COPY_THIS(total_grenades_background_number_of_flashes);
            COPY_THIS(total_grenades_background_flash_flags);
            COPY_THIS(total_grenades_background_flash_length);
            COPY_THIS(total_grenades_background_disabled_color);
            COPY_THIS(total_grenades_background_sequence_index);
            COPY_THIS(total_grenades_background_multitexture_overlays);
            COPY_THIS(total_grenades_numbers_anchor_offset);
            COPY_THIS(total_grenades_numbers_width_scale);
            COPY_THIS(total_grenades_numbers_height_scale);
            COPY_THIS(total_grenades_numbers_scaling_flags);
            COPY_THIS(total_grenades_numbers_default_color);
            COPY_THIS(total_grenades_numbers_flashing_color);
            COPY_THIS(total_grenades_numbers_flash_period);
            COPY_THIS(total_grenades_numbers_flash_delay);
            COPY_THIS(total_grenades_numbers_number_of_flashes);
            COPY_THIS(total_grenades_numbers_flash_flags);
            COPY_THIS(total_grenades_numbers_flash_length);
            COPY_THIS(total_grenades_numbers_disabled_color);
            COPY_THIS(total_grenades_numbers_maximum_number_of_digits);
            COPY_THIS(total_grenades_numbers_flags);
            COPY_THIS(total_grenades_numbers_number_of_fractional_digits);
            COPY_THIS(flash_cutoff);
            COPY_THIS(total_grenades_overlay_bitmap);
            COPY_THIS(total_grenades_overlays);
            COPY_THIS(total_grenades_warning_sounds);
            COPY_THIS(messaging_information_sequence_index);
            COPY_THIS(messaging_information_width_offset);
            COPY_THIS(messaging_information_offset_from_reference_corner);
            COPY_THIS(messaging_information_override_icon_color);
            COPY_THIS(messaging_information_frame_rate);
            COPY_THIS(messaging_information_flags);
            COPY_THIS(messaging_information_text_index);
            return copy;
        }
    };
    static_assert(sizeof(GrenadeHUDInterface<NativeEndian>) == 0x1F8);

    ENDIAN_TEMPLATE(EndianType) struct HUDGlobalsButtonIcon {
        EndianType<Index> sequence_index;
        EndianType<std::int16_t> width_offset;
        Point2DInt<EndianType> offset_from_reference_corner;
        EndianType<ColorARGBInt> override_icon_color;
        std::int8_t frame_rate;
        HUDInterfaceMessagingFlags flags;
        EndianType<Index> text_index;
        ENDIAN_TEMPLATE(NewEndian) operator HUDGlobalsButtonIcon<NewEndian>() const {
            HUDGlobalsButtonIcon<NewEndian> copy;
            COPY_THIS(sequence_index);
            COPY_THIS(width_offset);
            COPY_THIS(offset_from_reference_corner);
            COPY_THIS(override_icon_color);
            COPY_THIS(frame_rate);
            COPY_THIS(flags);
            COPY_THIS(text_index);
            return copy;
        }
    };
    static_assert(sizeof(HUDGlobalsButtonIcon<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct HUDGlobalsAnniversaryRemapTarget {
        TagDependency<EndianType> target_bitmap;
        EndianType<HUDGlobalsAnniversaryRemapTargetLanguage> language;
        EndianType<HUDGlobalsAnniversaryRemapTargetFlags> flags;
        ENDIAN_TEMPLATE(NewEndian) operator HUDGlobalsAnniversaryRemapTarget<NewEndian>() const {
            HUDGlobalsAnniversaryRemapTarget<NewEndian> copy;
            COPY_THIS(target_bitmap);
            COPY_THIS(language);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(HUDGlobalsAnniversaryRemapTarget<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct HUDGlobalsAnniversaryRemap {
        TagDependency<EndianType> source_bitmap;
        TagReflexive<EndianType, HUDGlobalsAnniversaryRemapTarget> targets;
        ENDIAN_TEMPLATE(NewEndian) operator HUDGlobalsAnniversaryRemap<NewEndian>() const {
            HUDGlobalsAnniversaryRemap<NewEndian> copy;
            COPY_THIS(source_bitmap);
            COPY_THIS(targets);
            return copy;
        }
    };
    static_assert(sizeof(HUDGlobalsAnniversaryRemap<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct HUDGlobalsWaypointArrow {
        TagString name;
        PAD(0x8);
        EndianType<ColorARGBInt> color;
        EndianType<float> opacity;
        EndianType<float> translucency;
        EndianType<Index> on_screen_sequence_index;
        EndianType<Index> off_screen_sequence_index;
        EndianType<Index> occluded_sequence_index;
        PAD(0x2);
        PAD(0x10);
        EndianType<HUDGlobalsWaypointArrowFlags> flags;
        PAD(0x18);
        ENDIAN_TEMPLATE(NewEndian) operator HUDGlobalsWaypointArrow<NewEndian>() const {
            HUDGlobalsWaypointArrow<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(color);
            COPY_THIS(opacity);
            COPY_THIS(translucency);
            COPY_THIS(on_screen_sequence_index);
            COPY_THIS(off_screen_sequence_index);
            COPY_THIS(occluded_sequence_index);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(HUDGlobalsWaypointArrow<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct HUDGlobals {
        EndianType<HUDInterfaceAnchor> anchor;
        PAD(0x2);
        PAD(0x20);
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> fullscreen_font;
        TagDependency<EndianType> splitscreen_font;
        EndianType<float> up_time;
        EndianType<float> fade_time;
        ColorARGB<EndianType> icon_color;
        ColorARGB<EndianType> text_color;
        EndianType<float> text_spacing;
        TagDependency<EndianType> item_message_text;
        TagDependency<EndianType> icon_bitmap;
        TagDependency<EndianType> alternate_icon_text;
        TagReflexive<EndianType, HUDGlobalsButtonIcon> button_icons;
        EndianType<ColorARGBInt> hud_help_default_color;
        EndianType<ColorARGBInt> hud_help_flashing_color;
        EndianType<float> hud_help_flash_period;
        EndianType<float> hud_help_flash_delay;
        EndianType<std::int16_t> hud_help_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> hud_help_flash_flags;
        EndianType<float> hud_help_flash_length;
        EndianType<ColorARGBInt> hud_help_disabled_color;
        PAD(0x4);
        TagDependency<EndianType> hud_messages;
        EndianType<ColorARGBInt> objective_default_color;
        EndianType<ColorARGBInt> objective_flashing_color;
        EndianType<float> objective_flash_period;
        EndianType<float> objective_flash_delay;
        EndianType<std::int16_t> objective_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> objective_flash_flags;
        EndianType<float> objective_flash_length;
        EndianType<ColorARGBInt> objective_disabled_color;
        EndianType<std::int16_t> objective_uptime_ticks;
        EndianType<std::int16_t> objective_fade_ticks;
        EndianType<float> top_offset;
        EndianType<float> bottom_offset;
        EndianType<float> left_offset;
        EndianType<float> right_offset;
        PAD(0x20);
        TagDependency<EndianType> arrow_bitmap;
        TagReflexive<EndianType, HUDGlobalsWaypointArrow> waypoint_arrows;
        PAD(0x50);
        EndianType<float> hud_scale_in_multiplayer;
        PAD(0x100);
        TagDependency<EndianType> default_weapon_hud;
        EndianType<float> motion_sensor_range;
        EndianType<float> motion_sensor_velocity_sensitivity;
        EndianType<float> motion_sensor_scale;
        Rectangle2D<EndianType> default_chapter_title_bounds;
        PAD(0x2C);
        EndianType<std::int16_t> hud_damage_top_offset;
        EndianType<std::int16_t> hud_damage_bottom_offset;
        EndianType<std::int16_t> hud_damage_left_offset;
        EndianType<std::int16_t> hud_damage_right_offset;
        PAD(0x20);
        TagDependency<EndianType> hud_damage_indicator_bitmap;
        EndianType<Index> hud_damage_sequence_index;
        EndianType<Index> hud_damage_multiplayer_sequence_index;
        EndianType<ColorARGBInt> hud_damage_color;
        PAD(0x10);
        EndianType<ColorARGBInt> not_much_time_left_default_color;
        EndianType<ColorARGBInt> not_much_time_left_flashing_color;
        EndianType<float> not_much_time_left_flash_period;
        EndianType<float> not_much_time_left_flash_delay;
        EndianType<std::int16_t> not_much_time_left_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> not_much_time_left_flash_flags;
        EndianType<float> not_much_time_left_flash_length;
        EndianType<ColorARGBInt> not_much_time_left_disabled_color;
        PAD(0x4);
        EndianType<ColorARGBInt> time_out_flash_default_color;
        EndianType<ColorARGBInt> time_out_flash_flashing_color;
        EndianType<float> time_out_flash_flash_period;
        EndianType<float> time_out_flash_flash_delay;
        EndianType<std::int16_t> time_out_flash_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> time_out_flash_flash_flags;
        EndianType<float> time_out_flash_flash_length;
        EndianType<ColorARGBInt> time_out_flash_disabled_color;
        PAD(0x4);
        PAD(0x28);
        TagDependency<EndianType> carnage_report_bitmap;
        EndianType<Index> loading_begin_text;
        EndianType<Index> loading_end_text;
        EndianType<Index> checkpoint_begin_text;
        EndianType<Index> checkpoint_end_text;
        TagDependency<EndianType> checkpoint_sound;
        TagReflexive<EndianType, HUDGlobalsAnniversaryRemap> anniversary_hud_remaps;
        PAD(0x54);
        ENDIAN_TEMPLATE(NewEndian) operator HUDGlobals<NewEndian>() const {
            HUDGlobals<NewEndian> copy = {};
            COPY_THIS(anchor);
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(fullscreen_font);
            COPY_THIS(splitscreen_font);
            COPY_THIS(up_time);
            COPY_THIS(fade_time);
            COPY_THIS(icon_color);
            COPY_THIS(text_color);
            COPY_THIS(text_spacing);
            COPY_THIS(item_message_text);
            COPY_THIS(icon_bitmap);
            COPY_THIS(alternate_icon_text);
            COPY_THIS(button_icons);
            COPY_THIS(hud_help_default_color);
            COPY_THIS(hud_help_flashing_color);
            COPY_THIS(hud_help_flash_period);
            COPY_THIS(hud_help_flash_delay);
            COPY_THIS(hud_help_number_of_flashes);
            COPY_THIS(hud_help_flash_flags);
            COPY_THIS(hud_help_flash_length);
            COPY_THIS(hud_help_disabled_color);
            COPY_THIS(hud_messages);
            COPY_THIS(objective_default_color);
            COPY_THIS(objective_flashing_color);
            COPY_THIS(objective_flash_period);
            COPY_THIS(objective_flash_delay);
            COPY_THIS(objective_number_of_flashes);
            COPY_THIS(objective_flash_flags);
            COPY_THIS(objective_flash_length);
            COPY_THIS(objective_disabled_color);
            COPY_THIS(objective_uptime_ticks);
            COPY_THIS(objective_fade_ticks);
            COPY_THIS(top_offset);
            COPY_THIS(bottom_offset);
            COPY_THIS(left_offset);
            COPY_THIS(right_offset);
            COPY_THIS(arrow_bitmap);
            COPY_THIS(waypoint_arrows);
            COPY_THIS(hud_scale_in_multiplayer);
            COPY_THIS(default_weapon_hud);
            COPY_THIS(motion_sensor_range);
            COPY_THIS(motion_sensor_velocity_sensitivity);
            COPY_THIS(motion_sensor_scale);
            COPY_THIS(default_chapter_title_bounds);
            COPY_THIS(hud_damage_top_offset);
            COPY_THIS(hud_damage_bottom_offset);
            COPY_THIS(hud_damage_left_offset);
            COPY_THIS(hud_damage_right_offset);
            COPY_THIS(hud_damage_indicator_bitmap);
            COPY_THIS(hud_damage_sequence_index);
            COPY_THIS(hud_damage_multiplayer_sequence_index);
            COPY_THIS(hud_damage_color);
            COPY_THIS(not_much_time_left_default_color);
            COPY_THIS(not_much_time_left_flashing_color);
            COPY_THIS(not_much_time_left_flash_period);
            COPY_THIS(not_much_time_left_flash_delay);
            COPY_THIS(not_much_time_left_number_of_flashes);
            COPY_THIS(not_much_time_left_flash_flags);
            COPY_THIS(not_much_time_left_flash_length);
            COPY_THIS(not_much_time_left_disabled_color);
            COPY_THIS(time_out_flash_default_color);
            COPY_THIS(time_out_flash_flashing_color);
            COPY_THIS(time_out_flash_flash_period);
            COPY_THIS(time_out_flash_flash_delay);
            COPY_THIS(time_out_flash_number_of_flashes);
            COPY_THIS(time_out_flash_flash_flags);
            COPY_THIS(time_out_flash_flash_length);
            COPY_THIS(time_out_flash_disabled_color);
            COPY_THIS(carnage_report_bitmap);
            COPY_THIS(loading_begin_text);
            COPY_THIS(loading_end_text);
            COPY_THIS(checkpoint_begin_text);
            COPY_THIS(checkpoint_end_text);
            COPY_THIS(checkpoint_sound);
            COPY_THIS(anniversary_hud_remaps);
            return copy;
        }
    };
    static_assert(sizeof(HUDGlobals<NativeEndian>) == 0x450);

    ENDIAN_TEMPLATE(EndianType) struct HUDMessageTextElement {
        std::int8_t type;
        std::uint8_t data;
        ENDIAN_TEMPLATE(NewEndian) operator HUDMessageTextElement<NewEndian>() const {
            HUDMessageTextElement<NewEndian> copy;
            COPY_THIS(type);
            COPY_THIS(data);
            return copy;
        }
    };
    static_assert(sizeof(HUDMessageTextElement<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct HUDMessageTextMessage {
        TagString name;
        EndianType<Index> start_index_into_text_blob;
        EndianType<Index> start_index_of_message_block;
        std::uint8_t panel_count;
        PAD(0x3);
        PAD(0x18);
        ENDIAN_TEMPLATE(NewEndian) operator HUDMessageTextMessage<NewEndian>() const {
            HUDMessageTextMessage<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(start_index_into_text_blob);
            COPY_THIS(start_index_of_message_block);
            COPY_THIS(panel_count);
            return copy;
        }
    };
    static_assert(sizeof(HUDMessageTextMessage<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct HUDMessageText {
        TagDataOffset<EndianType> text_data;
        TagReflexive<EndianType, HUDMessageTextElement> message_elements;
        TagReflexive<EndianType, HUDMessageTextMessage> messages;
        PAD(0x54);
        ENDIAN_TEMPLATE(NewEndian) operator HUDMessageText<NewEndian>() const {
            HUDMessageText<NewEndian> copy = {};
            COPY_THIS(text_data);
            COPY_THIS(message_elements);
            COPY_THIS(messages);
            return copy;
        }
    };
    static_assert(sizeof(HUDMessageText<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct HUDNumber {
        TagDependency<EndianType> digits_bitmap;
        std::int8_t bitmap_digit_width;
        std::int8_t screen_digit_width;
        std::int8_t x_offset;
        std::int8_t y_offset;
        std::int8_t decimal_point_width;
        std::int8_t colon_width;
        PAD(0x2);
        PAD(0x4C);
        ENDIAN_TEMPLATE(NewEndian) operator HUDNumber<NewEndian>() const {
            HUDNumber<NewEndian> copy = {};
            COPY_THIS(digits_bitmap);
            COPY_THIS(bitmap_digit_width);
            COPY_THIS(screen_digit_width);
            COPY_THIS(x_offset);
            COPY_THIS(y_offset);
            COPY_THIS(decimal_point_width);
            COPY_THIS(colon_width);
            return copy;
        }
    };
    static_assert(sizeof(HUDNumber<NativeEndian>) == 0x64);

    ENDIAN_TEMPLATE(EndianType) struct InputDeviceDefaults {
        EndianType<InputDeviceDefaultsDeviceType> device_type;
        EndianType<InputDeviceDefaultsFlags> flags;
        TagDataOffset<EndianType> device_id;
        TagDataOffset<EndianType> profile;
        ENDIAN_TEMPLATE(NewEndian) operator InputDeviceDefaults<NewEndian>() const {
            InputDeviceDefaults<NewEndian> copy;
            COPY_THIS(device_type);
            COPY_THIS(flags);
            COPY_THIS(device_id);
            COPY_THIS(profile);
            return copy;
        }
    };
    static_assert(sizeof(InputDeviceDefaults<NativeEndian>) == 0x2C);

    ENDIAN_TEMPLATE(EndianType) struct ItemCollectionPermutation {
        PAD(0x20);
        EndianType<float> weight;
        TagDependency<EndianType> item;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ItemCollectionPermutation<NewEndian>() const {
            ItemCollectionPermutation<NewEndian> copy = {};
            COPY_THIS(weight);
            COPY_THIS(item);
            return copy;
        }
    };
    static_assert(sizeof(ItemCollectionPermutation<NativeEndian>) == 0x54);

    ENDIAN_TEMPLATE(EndianType) struct ItemCollection {
        TagReflexive<EndianType, ItemCollectionPermutation> permutations;
        EndianType<std::int16_t> default_spawn_time;
        PAD(0x2);
        PAD(0x4C);
        ENDIAN_TEMPLATE(NewEndian) operator ItemCollection<NewEndian>() const {
            ItemCollection<NewEndian> copy = {};
            COPY_THIS(permutations);
            COPY_THIS(default_spawn_time);
            return copy;
        }
    };
    static_assert(sizeof(ItemCollection<NativeEndian>) == 0x5C);

    ENDIAN_TEMPLATE(EndianType) struct LensFlareReflection {
        EndianType<LensFlareReflectionFlags> flags;
        PAD(0x2);
        EndianType<Index> bitmap_index;
        PAD(0x2);
        PAD(0x14);
        EndianType<float> position;
        EndianType<float> rotation_offset;
        PAD(0x4);
        Bounds<EndianType<float>> radius;
        EndianType<LensFlareRadiusScaledBy> radius_scaled_by;
        PAD(0x2);
        Bounds<EndianType<Fraction>> brightness;
        EndianType<LensFlareRadiusScaledBy> brightness_scaled_by;
        PAD(0x2);
        ColorARGB<EndianType> tint_color;
        ColorARGB<EndianType> color_lower_bound;
        ColorARGB<EndianType> color_upper_bound;
        EndianType<LensFlareReflectionMoreFlags> more_flags;
        EndianType<WaveFunction> animation_function;
        EndianType<float> animation_period;
        EndianType<float> animation_phase;
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator LensFlareReflection<NewEndian>() const {
            LensFlareReflection<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(bitmap_index);
            COPY_THIS(position);
            COPY_THIS(rotation_offset);
            COPY_THIS(radius);
            COPY_THIS(radius_scaled_by);
            COPY_THIS(brightness);
            COPY_THIS(brightness_scaled_by);
            COPY_THIS(tint_color);
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            COPY_THIS(more_flags);
            COPY_THIS(animation_function);
            COPY_THIS(animation_period);
            COPY_THIS(animation_phase);
            return copy;
        }
    };
    static_assert(sizeof(LensFlareReflection<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct LensFlare {
        EndianType<Angle> falloff_angle;
        EndianType<Angle> cutoff_angle;
        LittleEndian<float> cos_falloff_angle;
        LittleEndian<float> cos_cutoff_angle;
        EndianType<float> occlusion_radius;
        EndianType<LensFlareOcclusionOffsetDirection> occlusion_offset_direction;
        PAD(0x2);
        EndianType<float> near_fade_distance;
        EndianType<float> far_fade_distance;
        TagDependency<EndianType> bitmap;
        EndianType<LensFlareFlags> flags;
        PAD(0x2);
        PAD(0x4C);
        EndianType<LensFlareRotationFunction> rotation_function;
        PAD(0x2);
        EndianType<Angle> rotation_function_scale;
        PAD(0x18);
        EndianType<float> horizontal_scale;
        EndianType<float> vertical_scale;
        PAD(0x1C);
        TagReflexive<EndianType, LensFlareReflection> reflections;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator LensFlare<NewEndian>() const {
            LensFlare<NewEndian> copy = {};
            COPY_THIS(falloff_angle);
            COPY_THIS(cutoff_angle);
            COPY_THIS(cos_falloff_angle);
            COPY_THIS(cos_cutoff_angle);
            COPY_THIS(occlusion_radius);
            COPY_THIS(occlusion_offset_direction);
            COPY_THIS(near_fade_distance);
            COPY_THIS(far_fade_distance);
            COPY_THIS(bitmap);
            COPY_THIS(flags);
            COPY_THIS(rotation_function);
            COPY_THIS(rotation_function_scale);
            COPY_THIS(horizontal_scale);
            COPY_THIS(vertical_scale);
            COPY_THIS(reflections);
            return copy;
        }
    };
    static_assert(sizeof(LensFlare<NativeEndian>) == 0xF0);

    ENDIAN_TEMPLATE(EndianType) struct Light {
        EndianType<LightFlags> flags;
        EndianType<float> radius;
        Bounds<EndianType<float>> radius_modifer;
        EndianType<Angle> falloff_angle;
        EndianType<Angle> cutoff_angle;
        EndianType<float> lens_flare_only_radius;
        LittleEndian<float> cos_falloff_angle;
        LittleEndian<float> cos_cutoff_angle;
        LittleEndian<float> unknown_two;
        LittleEndian<float> sin_cutoff_angle;
        PAD(0x8);
        EndianType<ColorInterpolationFlags> interpolation_flags;
        ColorARGB<EndianType> color_lower_bound;
        ColorARGB<EndianType> color_upper_bound;
        PAD(0xC);
        TagDependency<EndianType> primary_cube_map;
        PAD(0x2);
        EndianType<WaveFunction> texture_animation_function;
        EndianType<float> texture_animation_period;
        TagDependency<EndianType> secondary_cube_map;
        PAD(0x2);
        EndianType<WaveFunction> yaw_function;
        EndianType<float> yaw_period;
        PAD(0x2);
        EndianType<WaveFunction> roll_function;
        EndianType<float> roll_period;
        PAD(0x2);
        EndianType<WaveFunction> pitch_function;
        EndianType<float> pitch_period;
        PAD(0x8);
        TagDependency<EndianType> lens_flare;
        PAD(0x18);
        EndianType<float> intensity;
        ColorRGB<EndianType> color;
        PAD(0x10);
        EndianType<float> duration;
        PAD(0x2);
        EndianType<FunctionType> falloff_function;
        PAD(0x8);
        PAD(0x5C);
        ENDIAN_TEMPLATE(NewEndian) operator Light<NewEndian>() const {
            Light<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(radius);
            COPY_THIS(radius_modifer);
            COPY_THIS(falloff_angle);
            COPY_THIS(cutoff_angle);
            COPY_THIS(lens_flare_only_radius);
            COPY_THIS(cos_falloff_angle);
            COPY_THIS(cos_cutoff_angle);
            COPY_THIS(unknown_two);
            COPY_THIS(sin_cutoff_angle);
            COPY_THIS(interpolation_flags);
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            COPY_THIS(primary_cube_map);
            COPY_THIS(texture_animation_function);
            COPY_THIS(texture_animation_period);
            COPY_THIS(secondary_cube_map);
            COPY_THIS(yaw_function);
            COPY_THIS(yaw_period);
            COPY_THIS(roll_function);
            COPY_THIS(roll_period);
            COPY_THIS(pitch_function);
            COPY_THIS(pitch_period);
            COPY_THIS(lens_flare);
            COPY_THIS(intensity);
            COPY_THIS(color);
            COPY_THIS(duration);
            COPY_THIS(falloff_function);
            return copy;
        }
    };
    static_assert(sizeof(Light<NativeEndian>) == 0x160);

    ENDIAN_TEMPLATE(EndianType) struct LightVolumeFrame {
        PAD(0x10);
        EndianType<float> offset_from_marker;
        EndianType<float> offset_exponent;
        EndianType<float> length;
        PAD(0x20);
        EndianType<float> radius_hither;
        EndianType<float> radius_yon;
        EndianType<float> radius_exponent;
        PAD(0x20);
        ColorARGB<EndianType> tint_color_hither;
        ColorARGB<EndianType> tint_color_yon;
        EndianType<float> tint_color_exponent;
        EndianType<float> brightness_exponent;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator LightVolumeFrame<NewEndian>() const {
            LightVolumeFrame<NewEndian> copy = {};
            COPY_THIS(offset_from_marker);
            COPY_THIS(offset_exponent);
            COPY_THIS(length);
            COPY_THIS(radius_hither);
            COPY_THIS(radius_yon);
            COPY_THIS(radius_exponent);
            COPY_THIS(tint_color_hither);
            COPY_THIS(tint_color_yon);
            COPY_THIS(tint_color_exponent);
            COPY_THIS(brightness_exponent);
            return copy;
        }
    };
    static_assert(sizeof(LightVolumeFrame<NativeEndian>) == 0xB0);

    ENDIAN_TEMPLATE(EndianType) struct LightVolume {
        TagString attachment_marker;
        PAD(0x2);
        EndianType<LightVolumeFlags> flags;
        PAD(0x10);
        EndianType<float> near_fade_distance;
        EndianType<float> far_fade_distance;
        EndianType<Fraction> perpendicular_brightness_scale;
        EndianType<Fraction> parallel_brightness_scale;
        EndianType<FunctionOut> brightness_scale_source;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> map;
        EndianType<Index> sequence_index;
        EndianType<std::int16_t> count;
        PAD(0x48);
        EndianType<FunctionOut> frame_animation_source;
        PAD(0x2);
        PAD(0x24);
        PAD(0x40);
        TagReflexive<EndianType, LightVolumeFrame> frames;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator LightVolume<NewEndian>() const {
            LightVolume<NewEndian> copy = {};
            COPY_THIS(attachment_marker);
            COPY_THIS(flags);
            COPY_THIS(near_fade_distance);
            COPY_THIS(far_fade_distance);
            COPY_THIS(perpendicular_brightness_scale);
            COPY_THIS(parallel_brightness_scale);
            COPY_THIS(brightness_scale_source);
            COPY_THIS(map);
            COPY_THIS(sequence_index);
            COPY_THIS(count);
            COPY_THIS(frame_animation_source);
            COPY_THIS(frames);
            return copy;
        }
    };
    static_assert(sizeof(LightVolume<NativeEndian>) == 0x14C);

    ENDIAN_TEMPLATE(EndianType) struct LightningMarker {
        TagString attachment_marker;
        EndianType<LightningMarkerFlag> flags;
        PAD(0x2);
        EndianType<std::int16_t> octaves_to_next_marker;
        PAD(0x2);
        PAD(0x4C);
        Vector3D<EndianType> random_position_bounds;
        EndianType<float> random_jitter;
        EndianType<float> thickness;
        ColorARGB<EndianType> tint;
        PAD(0x4C);
        ENDIAN_TEMPLATE(NewEndian) operator LightningMarker<NewEndian>() const {
            LightningMarker<NewEndian> copy = {};
            COPY_THIS(attachment_marker);
            COPY_THIS(flags);
            COPY_THIS(octaves_to_next_marker);
            COPY_THIS(random_position_bounds);
            COPY_THIS(random_jitter);
            COPY_THIS(thickness);
            COPY_THIS(tint);
            return copy;
        }
    };
    static_assert(sizeof(LightningMarker<NativeEndian>) == 0xE4);

    ENDIAN_TEMPLATE(EndianType) struct LightningShader {
        PAD(0x24);
        LittleEndian<std::uint32_t> make_it_work;
        EndianType<ParticleShaderFlags> shader_flags;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<IsUnfilteredFlag> map_flags;
        PAD(0x1C);
        PAD(0xC);
        LittleEndian<std::uint32_t> some_more_stuff_that_should_be_set_for_some_reason;
        PAD(0x2);
        PAD(0x2);
        PAD(0x38);
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator LightningShader<NewEndian>() const {
            LightningShader<NewEndian> copy = {};
            COPY_THIS(make_it_work);
            COPY_THIS(shader_flags);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(map_flags);
            COPY_THIS(some_more_stuff_that_should_be_set_for_some_reason);
            return copy;
        }
    };
    static_assert(sizeof(LightningShader<NativeEndian>) == 0xB4);

    ENDIAN_TEMPLATE(EndianType) struct Lightning {
        PAD(0x2);
        EndianType<std::int16_t> count;
        PAD(0x10);
        EndianType<float> near_fade_distance;
        EndianType<float> far_fade_distance;
        PAD(0x10);
        EndianType<FunctionOut> jitter_scale_source;
        EndianType<FunctionOut> thickness_scale_source;
        EndianType<FunctionNameNullable> tint_modulation_source;
        EndianType<FunctionOut> brightness_scale_source;
        TagDependency<EndianType> bitmap;
        PAD(0x54);
        TagReflexive<EndianType, LightningMarker> markers;
        TagReflexive<EndianType, LightningShader> shader;
        PAD(0x58);
        ENDIAN_TEMPLATE(NewEndian) operator Lightning<NewEndian>() const {
            Lightning<NewEndian> copy = {};
            COPY_THIS(count);
            COPY_THIS(near_fade_distance);
            COPY_THIS(far_fade_distance);
            COPY_THIS(jitter_scale_source);
            COPY_THIS(thickness_scale_source);
            COPY_THIS(tint_modulation_source);
            COPY_THIS(brightness_scale_source);
            COPY_THIS(bitmap);
            COPY_THIS(markers);
            COPY_THIS(shader);
            return copy;
        }
    };
    static_assert(sizeof(Lightning<NativeEndian>) == 0x108);

    ENDIAN_TEMPLATE(EndianType) struct MaterialEffectsMaterialEffectMaterial {
        TagDependency<EndianType> effect;
        TagDependency<EndianType> sound;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator MaterialEffectsMaterialEffectMaterial<NewEndian>() const {
            MaterialEffectsMaterialEffectMaterial<NewEndian> copy = {};
            COPY_THIS(effect);
            COPY_THIS(sound);
            return copy;
        }
    };
    static_assert(sizeof(MaterialEffectsMaterialEffectMaterial<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct MaterialEffectsMaterialEffect {
        TagReflexive<EndianType, MaterialEffectsMaterialEffectMaterial> materials;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator MaterialEffectsMaterialEffect<NewEndian>() const {
            MaterialEffectsMaterialEffect<NewEndian> copy = {};
            COPY_THIS(materials);
            return copy;
        }
    };
    static_assert(sizeof(MaterialEffectsMaterialEffect<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct MaterialEffects {
        TagReflexive<EndianType, MaterialEffectsMaterialEffect> effects;
        PAD(0x80);
        ENDIAN_TEMPLATE(NewEndian) operator MaterialEffects<NewEndian>() const {
            MaterialEffects<NewEndian> copy = {};
            COPY_THIS(effects);
            return copy;
        }
    };
    static_assert(sizeof(MaterialEffects<NativeEndian>) == 0x8C);

    ENDIAN_TEMPLATE(EndianType) struct Meter {
        EndianType<IsUnusedFlag> flags;
        TagDependency<EndianType> stencil_bitmaps;
        TagDependency<EndianType> source_bitmap;
        EndianType<std::uint16_t> stencil_sequence_index;
        EndianType<std::uint16_t> source_sequence_index;
        PAD(0x10);
        PAD(0x4);
        EndianType<MeterInterpolateColors> interpolate_colors;
        EndianType<MeterAnchorColors> anchor_colors;
        PAD(0x8);
        ColorARGB<EndianType> empty_color;
        ColorARGB<EndianType> full_color;
        PAD(0x14);
        EndianType<float> unmask_distance;
        EndianType<float> mask_distance;
        PAD(0x14);
        TagDataOffset<EndianType> encoded_stencil;
        ENDIAN_TEMPLATE(NewEndian) operator Meter<NewEndian>() const {
            Meter<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(stencil_bitmaps);
            COPY_THIS(source_bitmap);
            COPY_THIS(stencil_sequence_index);
            COPY_THIS(source_sequence_index);
            COPY_THIS(interpolate_colors);
            COPY_THIS(anchor_colors);
            COPY_THIS(empty_color);
            COPY_THIS(full_color);
            COPY_THIS(unmask_distance);
            COPY_THIS(mask_distance);
            COPY_THIS(encoded_stencil);
            return copy;
        }
    };
    static_assert(sizeof(Meter<NativeEndian>) == 0xAC);

    ENDIAN_TEMPLATE(EndianType) struct ModelGeometry {
        EndianType<IsUnusedFlag> flags;
        PAD(0x20);
        TagReflexive<EndianType, ModelGeometryPart> parts;
        ENDIAN_TEMPLATE(NewEndian) operator ModelGeometry<NewEndian>() const {
            ModelGeometry<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(parts);
            return copy;
        }
    };
    static_assert(sizeof(ModelGeometry<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct Model {
        EndianType<ModelFlags> flags;
        EndianType<std::int32_t> node_list_checksum;
        EndianType<float> super_high_detail_cutoff;
        EndianType<float> high_detail_cutoff;
        EndianType<float> medium_detail_cutoff;
        EndianType<float> low_detail_cutoff;
        EndianType<float> super_low_detail_cutoff;
        EndianType<std::uint16_t> super_low_detail_node_count;
        EndianType<std::uint16_t> low_detail_node_count;
        EndianType<std::uint16_t> medium_detail_node_count;
        EndianType<std::uint16_t> high_detail_node_count;
        EndianType<std::uint16_t> super_high_detail_node_count;
        PAD(0x2);
        PAD(0x8);
        EndianType<float> base_map_u_scale;
        EndianType<float> base_map_v_scale;
        PAD(0x74);
        TagReflexive<EndianType, ModelMarker> markers;
        TagReflexive<EndianType, ModelNode> nodes;
        TagReflexive<EndianType, ModelRegion> regions;
        TagReflexive<EndianType, ModelGeometry> geometries;
        TagReflexive<EndianType, ModelShaderReference> shaders;
        ENDIAN_TEMPLATE(NewEndian) operator Model<NewEndian>() const {
            Model<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(node_list_checksum);
            COPY_THIS(super_high_detail_cutoff);
            COPY_THIS(high_detail_cutoff);
            COPY_THIS(medium_detail_cutoff);
            COPY_THIS(low_detail_cutoff);
            COPY_THIS(super_low_detail_cutoff);
            COPY_THIS(super_low_detail_node_count);
            COPY_THIS(low_detail_node_count);
            COPY_THIS(medium_detail_node_count);
            COPY_THIS(high_detail_node_count);
            COPY_THIS(super_high_detail_node_count);
            COPY_THIS(base_map_u_scale);
            COPY_THIS(base_map_v_scale);
            COPY_THIS(markers);
            COPY_THIS(nodes);
            COPY_THIS(regions);
            COPY_THIS(geometries);
            COPY_THIS(shaders);
            return copy;
        }
    };
    static_assert(sizeof(Model<NativeEndian>) == 0xE8);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsRotation {
        EndianType<std::int16_t> rotation[4];
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsRotation<NewEndian>() const {
            ModelAnimationsRotation<NewEndian> copy;
            COPY_THIS_ARRAY(rotation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsRotation<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsTransform {
        Point3D<EndianType> transform;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsTransform<NewEndian>() const {
            ModelAnimationsTransform<NewEndian> copy;
            COPY_THIS(transform);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsTransform<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationscale {
        EndianType<Fraction> scale;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationscale<NewEndian>() const {
            ModelAnimationscale<NewEndian> copy;
            COPY_THIS(scale);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationscale<NativeEndian>) == 0x4);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsFrameInfoDxDy {
        EndianType<float> dx;
        EndianType<float> dy;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsFrameInfoDxDy<NewEndian>() const {
            ModelAnimationsFrameInfoDxDy<NewEndian> copy;
            COPY_THIS(dx);
            COPY_THIS(dy);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsFrameInfoDxDy<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsFrameInfoDxDyDyaw {
        EndianType<float> dx;
        EndianType<float> dy;
        EndianType<float> dyaw;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsFrameInfoDxDyDyaw<NewEndian>() const {
            ModelAnimationsFrameInfoDxDyDyaw<NewEndian> copy;
            COPY_THIS(dx);
            COPY_THIS(dy);
            COPY_THIS(dyaw);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsFrameInfoDxDyDyaw<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsFrameInfoDxDyDzDyaw {
        EndianType<float> dx;
        EndianType<float> dy;
        EndianType<float> dz;
        EndianType<float> dyaw;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsFrameInfoDxDyDzDyaw<NewEndian>() const {
            ModelAnimationsFrameInfoDxDyDzDyaw<NewEndian> copy;
            COPY_THIS(dx);
            COPY_THIS(dy);
            COPY_THIS(dz);
            COPY_THIS(dyaw);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsFrameInfoDxDyDzDyaw<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphObjectOverlay {
        EndianType<Index> animation;
        EndianType<AnimationFunction> function;
        EndianType<AnimationFunctionControls> function_controls;
        PAD(0x2);
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphObjectOverlay<NewEndian>() const {
            ModelAnimationsAnimationGraphObjectOverlay<NewEndian> copy = {};
            COPY_THIS(animation);
            COPY_THIS(function);
            COPY_THIS(function_controls);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphObjectOverlay<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsUnitSeatAnimation {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsUnitSeatAnimation<NewEndian>() const {
            ModelAnimationsUnitSeatAnimation<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsUnitSeatAnimation<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphUnitSeatikPoint {
        TagString marker;
        TagString attach_to_marker;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphUnitSeatikPoint<NewEndian>() const {
            ModelAnimationsAnimationGraphUnitSeatikPoint<NewEndian> copy;
            COPY_THIS(marker);
            COPY_THIS(attach_to_marker);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphUnitSeatikPoint<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationWeaponClassAnimation {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationWeaponClassAnimation<NewEndian>() const {
            ModelAnimationsAnimationWeaponClassAnimation<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationWeaponClassAnimation<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationWeaponTypeAnimation {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationWeaponTypeAnimation<NewEndian>() const {
            ModelAnimationsAnimationWeaponTypeAnimation<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationWeaponTypeAnimation<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphWeaponType {
        TagString label;
        PAD(0x10);
        TagReflexive<EndianType, ModelAnimationsAnimationWeaponTypeAnimation> animations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphWeaponType<NewEndian>() const {
            ModelAnimationsAnimationGraphWeaponType<NewEndian> copy = {};
            COPY_THIS(label);
            COPY_THIS(animations);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphWeaponType<NativeEndian>) == 0x3C);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphWeapon {
        TagString name;
        TagString grip_marker;
        TagString hand_marker;
        EndianType<Angle> right_yaw_per_frame;
        EndianType<Angle> left_yaw_per_frame;
        EndianType<std::uint16_t> right_frame_count;
        EndianType<std::uint16_t> left_frame_count;
        EndianType<Angle> down_pitch_per_frame;
        EndianType<Angle> up_pitch_per_frame;
        EndianType<std::uint16_t> down_pitch_frame_count;
        EndianType<std::uint16_t> up_pitch_frame_count;
        PAD(0x20);
        TagReflexive<EndianType, ModelAnimationsAnimationWeaponClassAnimation> animations;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphUnitSeatikPoint> ik_point;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphWeaponType> weapon_types;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphWeapon<NewEndian>() const {
            ModelAnimationsAnimationGraphWeapon<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(grip_marker);
            COPY_THIS(hand_marker);
            COPY_THIS(right_yaw_per_frame);
            COPY_THIS(left_yaw_per_frame);
            COPY_THIS(right_frame_count);
            COPY_THIS(left_frame_count);
            COPY_THIS(down_pitch_per_frame);
            COPY_THIS(up_pitch_per_frame);
            COPY_THIS(down_pitch_frame_count);
            COPY_THIS(up_pitch_frame_count);
            COPY_THIS(animations);
            COPY_THIS(ik_point);
            COPY_THIS(weapon_types);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphWeapon<NativeEndian>) == 0xBC);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphUnitSeat {
        TagString label;
        EndianType<Angle> right_yaw_per_frame;
        EndianType<Angle> left_yaw_per_frame;
        EndianType<std::uint16_t> right_frame_count;
        EndianType<std::uint16_t> left_frame_count;
        EndianType<Angle> down_pitch_per_frame;
        EndianType<Angle> up_pitch_per_frame;
        EndianType<std::uint16_t> down_pitch_frame_count;
        EndianType<std::uint16_t> up_pitch_frame_count;
        PAD(0x8);
        TagReflexive<EndianType, ModelAnimationsAnimationWeaponClassAnimation> animations;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphUnitSeatikPoint> ik_points;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphWeapon> weapons;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphUnitSeat<NewEndian>() const {
            ModelAnimationsAnimationGraphUnitSeat<NewEndian> copy = {};
            COPY_THIS(label);
            COPY_THIS(right_yaw_per_frame);
            COPY_THIS(left_yaw_per_frame);
            COPY_THIS(right_frame_count);
            COPY_THIS(left_frame_count);
            COPY_THIS(down_pitch_per_frame);
            COPY_THIS(up_pitch_per_frame);
            COPY_THIS(down_pitch_frame_count);
            COPY_THIS(up_pitch_frame_count);
            COPY_THIS(animations);
            COPY_THIS(ik_points);
            COPY_THIS(weapons);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphUnitSeat<NativeEndian>) == 0x64);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsWeaponAnimation {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsWeaponAnimation<NewEndian>() const {
            ModelAnimationsWeaponAnimation<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsWeaponAnimation<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphWeaponAnimations {
        PAD(0x10);
        TagReflexive<EndianType, ModelAnimationsWeaponAnimation> animations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphWeaponAnimations<NewEndian>() const {
            ModelAnimationsAnimationGraphWeaponAnimations<NewEndian> copy = {};
            COPY_THIS(animations);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphWeaponAnimations<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsVehicleAnimation {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsVehicleAnimation<NewEndian>() const {
            ModelAnimationsVehicleAnimation<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsVehicleAnimation<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationSuspensionAnimation {
        EndianType<Index> mass_point_index;
        EndianType<Index> animation;
        EndianType<float> full_extension_ground_depth;
        EndianType<float> full_compression_ground_depth;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationSuspensionAnimation<NewEndian>() const {
            ModelAnimationSuspensionAnimation<NewEndian> copy = {};
            COPY_THIS(mass_point_index);
            COPY_THIS(animation);
            COPY_THIS(full_extension_ground_depth);
            COPY_THIS(full_compression_ground_depth);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationSuspensionAnimation<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphVehicleAnimations {
        EndianType<Angle> right_yaw_per_frame;
        EndianType<Angle> left_yaw_per_frame;
        EndianType<std::uint16_t> right_frame_count;
        EndianType<std::uint16_t> left_frame_count;
        EndianType<Angle> down_pitch_per_frame;
        EndianType<Angle> up_pitch_per_frame;
        EndianType<std::uint16_t> down_pitch_frame_count;
        EndianType<std::uint16_t> up_pitch_frame_count;
        PAD(0x44);
        TagReflexive<EndianType, ModelAnimationsVehicleAnimation> animations;
        TagReflexive<EndianType, ModelAnimationSuspensionAnimation> suspension_animations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphVehicleAnimations<NewEndian>() const {
            ModelAnimationsAnimationGraphVehicleAnimations<NewEndian> copy = {};
            COPY_THIS(right_yaw_per_frame);
            COPY_THIS(left_yaw_per_frame);
            COPY_THIS(right_frame_count);
            COPY_THIS(left_frame_count);
            COPY_THIS(down_pitch_per_frame);
            COPY_THIS(up_pitch_per_frame);
            COPY_THIS(down_pitch_frame_count);
            COPY_THIS(up_pitch_frame_count);
            COPY_THIS(animations);
            COPY_THIS(suspension_animations);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphVehicleAnimations<NativeEndian>) == 0x74);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsDeviceAnimation {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsDeviceAnimation<NewEndian>() const {
            ModelAnimationsDeviceAnimation<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsDeviceAnimation<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsDeviceAnimations {
        PAD(0x54);
        TagReflexive<EndianType, ModelAnimationsDeviceAnimation> animations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsDeviceAnimations<NewEndian>() const {
            ModelAnimationsDeviceAnimations<NewEndian> copy = {};
            COPY_THIS(animations);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsDeviceAnimations<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsUnitDamageAnimations {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsUnitDamageAnimations<NewEndian>() const {
            ModelAnimationsUnitDamageAnimations<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsUnitDamageAnimations<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsFirstPersonWeapon {
        EndianType<Index> animation;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsFirstPersonWeapon<NewEndian>() const {
            ModelAnimationsFirstPersonWeapon<NewEndian> copy;
            COPY_THIS(animation);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsFirstPersonWeapon<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphFirstPersonWeaponAnimations {
        PAD(0x10);
        TagReflexive<EndianType, ModelAnimationsFirstPersonWeapon> animations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphFirstPersonWeaponAnimations<NewEndian>() const {
            ModelAnimationsAnimationGraphFirstPersonWeaponAnimations<NewEndian> copy = {};
            COPY_THIS(animations);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphFirstPersonWeaponAnimations<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphSoundReference {
        TagDependency<EndianType> sound;
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphSoundReference<NewEndian>() const {
            ModelAnimationsAnimationGraphSoundReference<NewEndian> copy = {};
            COPY_THIS(sound);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphSoundReference<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimationGraphNode {
        TagString name;
        EndianType<Index> next_sibling_node_index;
        EndianType<Index> first_child_node_index;
        EndianType<Index> parent_node_index;
        PAD(0x2);
        EndianType<ModelAnimationsAnimationGraphNodeFlags> node_joint_flags;
        Vector3D<EndianType> base_vector;
        EndianType<float> vector_range;
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimationGraphNode<NewEndian>() const {
            ModelAnimationsAnimationGraphNode<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(next_sibling_node_index);
            COPY_THIS(first_child_node_index);
            COPY_THIS(parent_node_index);
            COPY_THIS(node_joint_flags);
            COPY_THIS(base_vector);
            COPY_THIS(vector_range);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimationGraphNode<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimationsAnimation {
        TagString name;
        EndianType<AnimationType> type;
        EndianType<std::uint16_t> frame_count;
        EndianType<std::uint16_t> frame_size;
        EndianType<AnimationFrameInfoType> frame_info_type;
        EndianType<std::int32_t> node_list_checksum;
        EndianType<std::uint16_t> node_count;
        EndianType<Index> loop_frame_index;
        EndianType<Fraction> weight;
        EndianType<Index> key_frame_index;
        EndianType<Index> second_key_frame_index;
        EndianType<Index> next_animation;
        EndianType<ModelAnimationsAnimationFlags> flags;
        EndianType<Index> sound;
        EndianType<Index> sound_frame_index;
        std::int8_t left_foot_frame_index;
        std::int8_t right_foot_frame_index;
        LittleEndian<std::uint16_t> main_animation_index;
        LittleEndian<float> relative_weight;
        TagDataOffset<EndianType> frame_info;
        EndianType<std::uint32_t> node_transform_flag_data[2];
        PAD(0x8);
        EndianType<std::uint32_t> node_rotation_flag_data[2];
        PAD(0x8);
        EndianType<std::uint32_t> node_scale_flag_data[2];
        PAD(0x4);
        EndianType<std::uint32_t> offset_to_compressed_data;
        TagDataOffset<EndianType> default_data;
        TagDataOffset<EndianType> frame_data;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimationsAnimation<NewEndian>() const {
            ModelAnimationsAnimation<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(type);
            COPY_THIS(frame_count);
            COPY_THIS(frame_size);
            COPY_THIS(frame_info_type);
            COPY_THIS(node_list_checksum);
            COPY_THIS(node_count);
            COPY_THIS(loop_frame_index);
            COPY_THIS(weight);
            COPY_THIS(key_frame_index);
            COPY_THIS(second_key_frame_index);
            COPY_THIS(next_animation);
            COPY_THIS(flags);
            COPY_THIS(sound);
            COPY_THIS(sound_frame_index);
            COPY_THIS(left_foot_frame_index);
            COPY_THIS(right_foot_frame_index);
            COPY_THIS(main_animation_index);
            COPY_THIS(relative_weight);
            COPY_THIS(frame_info);
            COPY_THIS_ARRAY(node_transform_flag_data);
            COPY_THIS_ARRAY(node_rotation_flag_data);
            COPY_THIS_ARRAY(node_scale_flag_data);
            COPY_THIS(offset_to_compressed_data);
            COPY_THIS(default_data);
            COPY_THIS(frame_data);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimationsAnimation<NativeEndian>) == 0xB4);

    ENDIAN_TEMPLATE(EndianType) struct ModelAnimations {
        TagReflexive<EndianType, ModelAnimationsAnimationGraphObjectOverlay> objects;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphUnitSeat> units;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphWeaponAnimations> weapons;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphVehicleAnimations> vehicles;
        TagReflexive<EndianType, ModelAnimationsDeviceAnimations> devices;
        TagReflexive<EndianType, ModelAnimationsUnitDamageAnimations> unit_damage;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphFirstPersonWeaponAnimations> first_person_weapons;
        TagReflexive<EndianType, ModelAnimationsAnimationGraphSoundReference> sound_references;
        EndianType<float> limp_body_node_radius;
        EndianType<ModelAnimationsFlags> flags;
        PAD(0x2);
        TagReflexive<EndianType, ModelAnimationsAnimationGraphNode> nodes;
        TagReflexive<EndianType, ModelAnimationsAnimation> animations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelAnimations<NewEndian>() const {
            ModelAnimations<NewEndian> copy = {};
            COPY_THIS(objects);
            COPY_THIS(units);
            COPY_THIS(weapons);
            COPY_THIS(vehicles);
            COPY_THIS(devices);
            COPY_THIS(unit_damage);
            COPY_THIS(first_person_weapons);
            COPY_THIS(sound_references);
            COPY_THIS(limp_body_node_radius);
            COPY_THIS(flags);
            COPY_THIS(nodes);
            COPY_THIS(animations);
            return copy;
        }
    };
    static_assert(sizeof(ModelAnimations<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryMaterial {
        TagString name;
        EndianType<ModelCollisionGeometryMaterialFlags> flags;
        EndianType<MaterialType> material_type;
        PAD(0x2);
        EndianType<Fraction> shield_leak_percentage;
        EndianType<float> shield_damage_multiplier;
        PAD(0xC);
        EndianType<float> body_damage_multiplier;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryMaterial<NewEndian>() const {
            ModelCollisionGeometryMaterial<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(material_type);
            COPY_THIS(shield_leak_percentage);
            COPY_THIS(shield_damage_multiplier);
            COPY_THIS(body_damage_multiplier);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryMaterial<NativeEndian>) == 0x48);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryPermutation {
        TagString name;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryPermutation<NewEndian>() const {
            ModelCollisionGeometryPermutation<NewEndian> copy;
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryPermutation<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryRegion {
        TagString name;
        EndianType<ModelCollisionGeometryRegionFlags> flags;
        PAD(0x4);
        EndianType<float> damage_threshold;
        PAD(0xC);
        TagDependency<EndianType> destroyed_effect;
        TagReflexive<EndianType, ModelCollisionGeometryPermutation> permutations;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryRegion<NewEndian>() const {
            ModelCollisionGeometryRegion<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(damage_threshold);
            COPY_THIS(destroyed_effect);
            COPY_THIS(permutations);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryRegion<NativeEndian>) == 0x54);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryModifier {
        PAD(0x34);
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryModifier<NewEndian>() const {
            ModelCollisionGeometryModifier<NewEndian> copy = {};
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryModifier<NativeEndian>) == 0x34);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometrySphere {
        EndianType<Index> node;
        PAD(0x2);
        PAD(0xC);
        Point3D<EndianType> center;
        EndianType<float> radius;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometrySphere<NewEndian>() const {
            ModelCollisionGeometrySphere<NewEndian> copy = {};
            COPY_THIS(node);
            COPY_THIS(center);
            COPY_THIS(radius);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometrySphere<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSP3DNode {
        EndianType<std::uint32_t> plane;
        EndianType<FlaggedInt<std::uint32_t>> back_child;
        EndianType<FlaggedInt<std::uint32_t>> front_child;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSP3DNode<NewEndian>() const {
            ModelCollisionGeometryBSP3DNode<NewEndian> copy;
            COPY_THIS(plane);
            COPY_THIS(back_child);
            COPY_THIS(front_child);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSP3DNode<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSPPlane {
        Plane3D<EndianType> plane;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSPPlane<NewEndian>() const {
            ModelCollisionGeometryBSPPlane<NewEndian> copy;
            COPY_THIS(plane);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSPPlane<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSPLeaf {
        EndianType<ModelCollisionGeometryBSPLeafFlags> flags;
        EndianType<std::uint16_t> bsp2d_reference_count;
        EndianType<std::uint32_t> first_bsp2d_reference;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSPLeaf<NewEndian>() const {
            ModelCollisionGeometryBSPLeaf<NewEndian> copy;
            COPY_THIS(flags);
            COPY_THIS(bsp2d_reference_count);
            COPY_THIS(first_bsp2d_reference);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSPLeaf<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSP2DReference {
        EndianType<FlaggedInt<std::uint32_t>> plane;
        EndianType<FlaggedInt<std::uint32_t>> bsp2d_node;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSP2DReference<NewEndian>() const {
            ModelCollisionGeometryBSP2DReference<NewEndian> copy;
            COPY_THIS(plane);
            COPY_THIS(bsp2d_node);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSP2DReference<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSP2DNode {
        Plane2D<EndianType> plane;
        EndianType<FlaggedInt<std::uint32_t>> left_child;
        EndianType<FlaggedInt<std::uint32_t>> right_child;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSP2DNode<NewEndian>() const {
            ModelCollisionGeometryBSP2DNode<NewEndian> copy;
            COPY_THIS(plane);
            COPY_THIS(left_child);
            COPY_THIS(right_child);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSP2DNode<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSPSurface {
        EndianType<FlaggedInt<std::uint32_t>> plane;
        EndianType<std::uint32_t> first_edge;
        ModelCollisionGeometryBSPSurfaceFlags flags;
        std::int8_t breakable_surface;
        EndianType<Index> material;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSPSurface<NewEndian>() const {
            ModelCollisionGeometryBSPSurface<NewEndian> copy;
            COPY_THIS(plane);
            COPY_THIS(first_edge);
            COPY_THIS(flags);
            COPY_THIS(breakable_surface);
            COPY_THIS(material);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSPSurface<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSPEdge {
        EndianType<std::uint32_t> start_vertex;
        EndianType<std::uint32_t> end_vertex;
        EndianType<std::uint32_t> forward_edge;
        EndianType<std::uint32_t> reverse_edge;
        EndianType<std::uint32_t> left_surface;
        EndianType<std::uint32_t> right_surface;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSPEdge<NewEndian>() const {
            ModelCollisionGeometryBSPEdge<NewEndian> copy;
            COPY_THIS(start_vertex);
            COPY_THIS(end_vertex);
            COPY_THIS(forward_edge);
            COPY_THIS(reverse_edge);
            COPY_THIS(left_surface);
            COPY_THIS(right_surface);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSPEdge<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSPVertex {
        Point3D<EndianType> point;
        EndianType<std::uint32_t> first_edge;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSPVertex<NewEndian>() const {
            ModelCollisionGeometryBSPVertex<NewEndian> copy;
            COPY_THIS(point);
            COPY_THIS(first_edge);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSPVertex<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryBSP {
        TagReflexive<EndianType, ModelCollisionGeometryBSP3DNode> bsp3d_nodes;
        TagReflexive<EndianType, ModelCollisionGeometryBSPPlane> planes;
        TagReflexive<EndianType, ModelCollisionGeometryBSPLeaf> leaves;
        TagReflexive<EndianType, ModelCollisionGeometryBSP2DReference> bsp2d_references;
        TagReflexive<EndianType, ModelCollisionGeometryBSP2DNode> bsp2d_nodes;
        TagReflexive<EndianType, ModelCollisionGeometryBSPSurface> surfaces;
        TagReflexive<EndianType, ModelCollisionGeometryBSPEdge> edges;
        TagReflexive<EndianType, ModelCollisionGeometryBSPVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryBSP<NewEndian>() const {
            ModelCollisionGeometryBSP<NewEndian> copy;
            COPY_THIS(bsp3d_nodes);
            COPY_THIS(planes);
            COPY_THIS(leaves);
            COPY_THIS(bsp2d_references);
            COPY_THIS(bsp2d_nodes);
            COPY_THIS(surfaces);
            COPY_THIS(edges);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryBSP<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometryNode {
        TagString name;
        EndianType<Index> region;
        EndianType<Index> parent_node;
        EndianType<Index> next_sibling_node;
        EndianType<Index> first_child_node;
        PAD(0xA);
        EndianType<std::int16_t> name_thing;
        TagReflexive<EndianType, ModelCollisionGeometryBSP> bsps;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometryNode<NewEndian>() const {
            ModelCollisionGeometryNode<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(region);
            COPY_THIS(parent_node);
            COPY_THIS(next_sibling_node);
            COPY_THIS(first_child_node);
            COPY_THIS(name_thing);
            COPY_THIS(bsps);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometryNode<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ModelCollisionGeometry {
        EndianType<ModelCollisionGeometryFlags> flags;
        EndianType<Index> indirect_damage_material;
        PAD(0x2);
        EndianType<float> maximum_body_vitality;
        EndianType<float> body_system_shock;
        PAD(0x18);
        PAD(0x1C);
        EndianType<Fraction> friendly_damage_resistance;
        PAD(0x8);
        PAD(0x20);
        TagDependency<EndianType> localized_damage_effect;
        EndianType<float> area_damage_effect_threshold;
        TagDependency<EndianType> area_damage_effect;
        EndianType<float> body_damaged_threshold;
        TagDependency<EndianType> body_damaged_effect;
        TagDependency<EndianType> body_depleted_effect;
        EndianType<float> body_destroyed_threshold;
        TagDependency<EndianType> body_destroyed_effect;
        EndianType<float> maximum_shield_vitality;
        PAD(0x2);
        EndianType<MaterialType> shield_material_type;
        PAD(0x18);
        EndianType<FunctionType> shield_failure_function;
        PAD(0x2);
        EndianType<Fraction> shield_failure_threshold;
        EndianType<Fraction> failing_shield_leak_fraction;
        PAD(0x10);
        EndianType<float> minimum_stun_damage;
        EndianType<float> stun_time;
        EndianType<float> recharge_time;
        PAD(0x10);
        PAD(0x60);
        EndianType<float> shield_damaged_threshold;
        TagDependency<EndianType> shield_damaged_effect;
        TagDependency<EndianType> shield_depleted_effect;
        TagDependency<EndianType> shield_recharging_effect;
        PAD(0x8);
        LittleEndian<float> shield_recharge_rate;
        PAD(0x70);
        TagReflexive<EndianType, ModelCollisionGeometryMaterial> materials;
        TagReflexive<EndianType, ModelCollisionGeometryRegion> regions;
        TagReflexive<EndianType, ModelCollisionGeometryModifier> modifiers;
        PAD(0x10);
        Bounds<EndianType<float>> x;
        Bounds<EndianType<float>> y;
        Bounds<EndianType<float>> z;
        TagReflexive<EndianType, ModelCollisionGeometrySphere> pathfinding_spheres;
        TagReflexive<EndianType, ModelCollisionGeometryNode> nodes;
        ENDIAN_TEMPLATE(NewEndian) operator ModelCollisionGeometry<NewEndian>() const {
            ModelCollisionGeometry<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(indirect_damage_material);
            COPY_THIS(maximum_body_vitality);
            COPY_THIS(body_system_shock);
            COPY_THIS(friendly_damage_resistance);
            COPY_THIS(localized_damage_effect);
            COPY_THIS(area_damage_effect_threshold);
            COPY_THIS(area_damage_effect);
            COPY_THIS(body_damaged_threshold);
            COPY_THIS(body_damaged_effect);
            COPY_THIS(body_depleted_effect);
            COPY_THIS(body_destroyed_threshold);
            COPY_THIS(body_destroyed_effect);
            COPY_THIS(maximum_shield_vitality);
            COPY_THIS(shield_material_type);
            COPY_THIS(shield_failure_function);
            COPY_THIS(shield_failure_threshold);
            COPY_THIS(failing_shield_leak_fraction);
            COPY_THIS(minimum_stun_damage);
            COPY_THIS(stun_time);
            COPY_THIS(recharge_time);
            COPY_THIS(shield_damaged_threshold);
            COPY_THIS(shield_damaged_effect);
            COPY_THIS(shield_depleted_effect);
            COPY_THIS(shield_recharging_effect);
            COPY_THIS(shield_recharge_rate);
            COPY_THIS(materials);
            COPY_THIS(regions);
            COPY_THIS(modifiers);
            COPY_THIS(x);
            COPY_THIS(y);
            COPY_THIS(z);
            COPY_THIS(pathfinding_spheres);
            COPY_THIS(nodes);
            return copy;
        }
    };
    static_assert(sizeof(ModelCollisionGeometry<NativeEndian>) == 0x298);

    ENDIAN_TEMPLATE(EndianType) struct MultiplayerScenarioDescriptionScenarioDescription {
        TagDependency<EndianType> descriptive_bitmap;
        TagDependency<EndianType> displayed_map_name;
        TagString scenario_tag_directory_path;
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator MultiplayerScenarioDescriptionScenarioDescription<NewEndian>() const {
            MultiplayerScenarioDescriptionScenarioDescription<NewEndian> copy = {};
            COPY_THIS(descriptive_bitmap);
            COPY_THIS(displayed_map_name);
            COPY_THIS(scenario_tag_directory_path);
            return copy;
        }
    };
    static_assert(sizeof(MultiplayerScenarioDescriptionScenarioDescription<NativeEndian>) == 0x44);

    ENDIAN_TEMPLATE(EndianType) struct MultiplayerScenarioDescription {
        TagReflexive<EndianType, MultiplayerScenarioDescriptionScenarioDescription> multiplayer_scenarios;
        ENDIAN_TEMPLATE(NewEndian) operator MultiplayerScenarioDescription<NewEndian>() const {
            MultiplayerScenarioDescription<NewEndian> copy;
            COPY_THIS(multiplayer_scenarios);
            return copy;
        }
    };
    static_assert(sizeof(MultiplayerScenarioDescription<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct BasicObject : Object<EndianType> {
        PAD(0x2);
        EndianType<BaseObjectFlags> more_flags;
        PAD(0x7C);
        ENDIAN_TEMPLATE(NewEndian) operator BasicObject<NewEndian>() const {
            BasicObject<NewEndian> copy = {};
            COPY_THIS(more_flags);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(BasicObject<NativeEndian>) == 0x1FC);

    ENDIAN_TEMPLATE(EndianType) struct Particle {
        EndianType<ParticleFlags> flags;
        TagDependency<EndianType> bitmap;
        TagDependency<EndianType> physics;
        TagDependency<EndianType> sir_marty_exchanged_his_children_for_thine;
        PAD(0x4);
        Bounds<EndianType<float>> lifespan;
        EndianType<float> fade_in_time;
        EndianType<float> fade_out_time;
        TagDependency<EndianType> collision_effect;
        TagDependency<EndianType> death_effect;
        EndianType<float> minimum_size;
        PAD(0x8);
        Bounds<EndianType<float>> radius_animation;
        PAD(0x4);
        Bounds<EndianType<float>> animation_rate;
        EndianType<float> contact_deterioration;
        EndianType<float> fade_start_size;
        EndianType<float> fade_end_size;
        PAD(0x4);
        EndianType<Index> first_sequence_index;
        EndianType<std::int16_t> initial_sequence_count;
        EndianType<std::int16_t> looping_sequence_count;
        EndianType<std::int16_t> final_sequence_count;
        PAD(0x8);
        LittleEndian<float> sprite_size;
        EndianType<ParticleOrientation> orientation;
        PAD(0x2);
        PAD(0x24);
        LittleEndian<std::uint32_t> make_it_actually_work;
        EndianType<ParticleShaderFlags> shader_flags;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<IsUnfilteredFlag> map_flags;
        PAD(0x1C);
        TagDependency<EndianType> secondary_bitmap;
        EndianType<ParticleAnchor> anchor;
        EndianType<IsUnfilteredFlag> secondary_map_flags;
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<float> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        PAD(0x4);
        EndianType<float> zsprite_radius_scale;
        PAD(0x14);
        ENDIAN_TEMPLATE(NewEndian) operator Particle<NewEndian>() const {
            Particle<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(bitmap);
            COPY_THIS(physics);
            COPY_THIS(sir_marty_exchanged_his_children_for_thine);
            COPY_THIS(lifespan);
            COPY_THIS(fade_in_time);
            COPY_THIS(fade_out_time);
            COPY_THIS(collision_effect);
            COPY_THIS(death_effect);
            COPY_THIS(minimum_size);
            COPY_THIS(radius_animation);
            COPY_THIS(animation_rate);
            COPY_THIS(contact_deterioration);
            COPY_THIS(fade_start_size);
            COPY_THIS(fade_end_size);
            COPY_THIS(first_sequence_index);
            COPY_THIS(initial_sequence_count);
            COPY_THIS(looping_sequence_count);
            COPY_THIS(final_sequence_count);
            COPY_THIS(sprite_size);
            COPY_THIS(orientation);
            COPY_THIS(make_it_actually_work);
            COPY_THIS(shader_flags);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(map_flags);
            COPY_THIS(secondary_bitmap);
            COPY_THIS(anchor);
            COPY_THIS(secondary_map_flags);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            COPY_THIS(zsprite_radius_scale);
            return copy;
        }
    };
    static_assert(sizeof(Particle<NativeEndian>) == 0x164);

    ENDIAN_TEMPLATE(EndianType) struct ParticleSystemPhysicsConstant {
        EndianType<float> k;
        ENDIAN_TEMPLATE(NewEndian) operator ParticleSystemPhysicsConstant<NewEndian>() const {
            ParticleSystemPhysicsConstant<NewEndian> copy;
            COPY_THIS(k);
            return copy;
        }
    };
    static_assert(sizeof(ParticleSystemPhysicsConstant<NativeEndian>) == 0x4);

    ENDIAN_TEMPLATE(EndianType) struct ParticleSystemTypeStates {
        TagString name;
        Bounds<EndianType<float>> duration_bounds;
        Bounds<EndianType<float>> transition_time_bounds;
        PAD(0x4);
        EndianType<float> scale_multiplier;
        EndianType<float> animation_rate_multiplier;
        EndianType<float> rotation_rate_multiplier;
        ColorARGB<EndianType> color_multiplier;
        EndianType<float> radius_multiplier;
        EndianType<float> minimum_particle_count;
        EndianType<float> particle_creation_rate;
        PAD(0x54);
        EndianType<ParticleSystemParticleCreationPhysics> particle_creation_physics;
        EndianType<ParticleSystemParticleUpdatePhysics> particle_update_physics;
        TagReflexive<EndianType, ParticleSystemPhysicsConstant> physics_constants;
        ENDIAN_TEMPLATE(NewEndian) operator ParticleSystemTypeStates<NewEndian>() const {
            ParticleSystemTypeStates<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(duration_bounds);
            COPY_THIS(transition_time_bounds);
            COPY_THIS(scale_multiplier);
            COPY_THIS(animation_rate_multiplier);
            COPY_THIS(rotation_rate_multiplier);
            COPY_THIS(color_multiplier);
            COPY_THIS(radius_multiplier);
            COPY_THIS(minimum_particle_count);
            COPY_THIS(particle_creation_rate);
            COPY_THIS(particle_creation_physics);
            COPY_THIS(particle_update_physics);
            COPY_THIS(physics_constants);
            return copy;
        }
    };
    static_assert(sizeof(ParticleSystemTypeStates<NativeEndian>) == 0xC0);

    ENDIAN_TEMPLATE(EndianType) struct ParticleSystemTypeParticleState {
        TagString name;
        Bounds<EndianType<float>> duration_bounds;
        Bounds<EndianType<float>> transition_time_bounds;
        TagDependency<EndianType> bitmaps;
        EndianType<Index> sequence_index;
        PAD(0x2);
        PAD(0x4);
        Bounds<EndianType<float>> scale;
        Bounds<EndianType<float>> animation_rate;
        Bounds<EndianType<Angle>> rotation_rate;
        ColorARGB<EndianType> color_1;
        ColorARGB<EndianType> color_2;
        EndianType<float> radius_multiplier;
        TagDependency<EndianType> point_physics;
        PAD(0x24);
        PAD(0x24);
        LittleEndian<std::uint32_t> unknown_int;
        EndianType<ParticleShaderFlags> shader_flags;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<IsUnfilteredFlag> map_flags;
        PAD(0x1C);
        TagDependency<EndianType> secondary_map_bitmap;
        EndianType<ParticleAnchor> anchor;
        EndianType<IsUnfilteredFlag> flags;
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<float> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        PAD(0x4);
        EndianType<float> zsprite_radius_scale;
        PAD(0x14);
        TagReflexive<EndianType, ParticleSystemPhysicsConstant> physics_constants;
        ENDIAN_TEMPLATE(NewEndian) operator ParticleSystemTypeParticleState<NewEndian>() const {
            ParticleSystemTypeParticleState<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(duration_bounds);
            COPY_THIS(transition_time_bounds);
            COPY_THIS(bitmaps);
            COPY_THIS(sequence_index);
            COPY_THIS(scale);
            COPY_THIS(animation_rate);
            COPY_THIS(rotation_rate);
            COPY_THIS(color_1);
            COPY_THIS(color_2);
            COPY_THIS(radius_multiplier);
            COPY_THIS(point_physics);
            COPY_THIS(unknown_int);
            COPY_THIS(shader_flags);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(map_flags);
            COPY_THIS(secondary_map_bitmap);
            COPY_THIS(anchor);
            COPY_THIS(flags);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            COPY_THIS(zsprite_radius_scale);
            COPY_THIS(physics_constants);
            return copy;
        }
    };
    static_assert(sizeof(ParticleSystemTypeParticleState<NativeEndian>) == 0x178);

    ENDIAN_TEMPLATE(EndianType) struct ParticleSystemType {
        TagString name;
        EndianType<ParticleSystemTypeFlags> flags;
        EndianType<std::uint16_t> initial_particle_count;
        PAD(0x2);
        EndianType<ParticleSystemComplexSpriteRenderMode> complex_sprite_render_mode;
        PAD(0x2);
        EndianType<float> radius;
        PAD(0x24);
        EndianType<ParticleSystemParticleCreationPhysics> particle_creation_physics;
        PAD(0x2);
        EndianType<IsUnusedFlag> physics_flags;
        TagReflexive<EndianType, ParticleSystemPhysicsConstant> physics_constants;
        TagReflexive<EndianType, ParticleSystemTypeStates> states;
        TagReflexive<EndianType, ParticleSystemTypeParticleState> particle_states;
        ENDIAN_TEMPLATE(NewEndian) operator ParticleSystemType<NewEndian>() const {
            ParticleSystemType<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(initial_particle_count);
            COPY_THIS(complex_sprite_render_mode);
            COPY_THIS(radius);
            COPY_THIS(particle_creation_physics);
            COPY_THIS(physics_flags);
            COPY_THIS(physics_constants);
            COPY_THIS(states);
            COPY_THIS(particle_states);
            return copy;
        }
    };
    static_assert(sizeof(ParticleSystemType<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct ParticleSystem {
        PAD(0x4);
        PAD(0x34);
        TagDependency<EndianType> point_physics;
        EndianType<ParticleSystemSystemUpdatePhysics> system_update_physics;
        PAD(0x2);
        EndianType<IsUnusedFlag> physics_flags;
        TagReflexive<EndianType, ParticleSystemPhysicsConstant> physics_constants;
        TagReflexive<EndianType, ParticleSystemType> particle_types;
        ENDIAN_TEMPLATE(NewEndian) operator ParticleSystem<NewEndian>() const {
            ParticleSystem<NewEndian> copy = {};
            COPY_THIS(point_physics);
            COPY_THIS(system_update_physics);
            COPY_THIS(physics_flags);
            COPY_THIS(physics_constants);
            COPY_THIS(particle_types);
            return copy;
        }
    };
    static_assert(sizeof(ParticleSystem<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct PhysicsInertialMatrix {
        Matrix<EndianType> matrix;
        ENDIAN_TEMPLATE(NewEndian) operator PhysicsInertialMatrix<NewEndian>() const {
            PhysicsInertialMatrix<NewEndian> copy;
            COPY_THIS(matrix);
            return copy;
        }
    };
    static_assert(sizeof(PhysicsInertialMatrix<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct PhysicsPoweredMassPoint {
        TagString name;
        EndianType<PhysicsPoweredMassPointFlags> flags;
        EndianType<float> antigrav_strength;
        EndianType<float> antigrav_offset;
        EndianType<float> antigrav_height;
        EndianType<float> antigrav_damp_fraction;
        EndianType<float> antigrav_normal_k1;
        EndianType<float> antigrav_normal_k0;
        PAD(0x44);
        ENDIAN_TEMPLATE(NewEndian) operator PhysicsPoweredMassPoint<NewEndian>() const {
            PhysicsPoweredMassPoint<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(antigrav_strength);
            COPY_THIS(antigrav_offset);
            COPY_THIS(antigrav_height);
            COPY_THIS(antigrav_damp_fraction);
            COPY_THIS(antigrav_normal_k1);
            COPY_THIS(antigrav_normal_k0);
            return copy;
        }
    };
    static_assert(sizeof(PhysicsPoweredMassPoint<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct PhysicsMassPoint {
        TagString name;
        EndianType<std::int16_t> powered_mass_point;
        EndianType<std::int16_t> model_node;
        EndianType<PhysicsMassPointFlags> flags;
        EndianType<float> relative_mass;
        EndianType<float> mass;
        EndianType<float> relative_density;
        EndianType<float> density;
        Point3D<EndianType> position;
        Vector3D<EndianType> forward;
        Vector3D<EndianType> up;
        EndianType<PhysicsFrictionType> friction_type;
        PAD(0x2);
        EndianType<float> friction_parallel_scale;
        EndianType<float> friction_perpendicular_scale;
        EndianType<float> radius;
        PAD(0x14);
        ENDIAN_TEMPLATE(NewEndian) operator PhysicsMassPoint<NewEndian>() const {
            PhysicsMassPoint<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(powered_mass_point);
            COPY_THIS(model_node);
            COPY_THIS(flags);
            COPY_THIS(relative_mass);
            COPY_THIS(mass);
            COPY_THIS(relative_density);
            COPY_THIS(density);
            COPY_THIS(position);
            COPY_THIS(forward);
            COPY_THIS(up);
            COPY_THIS(friction_type);
            COPY_THIS(friction_parallel_scale);
            COPY_THIS(friction_perpendicular_scale);
            COPY_THIS(radius);
            return copy;
        }
    };
    static_assert(sizeof(PhysicsMassPoint<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct Physics {
        EndianType<float> radius;
        EndianType<Fraction> moment_scale;
        EndianType<float> mass;
        Point3D<EndianType> center_of_mass;
        EndianType<float> density;
        EndianType<float> gravity_scale;
        EndianType<float> ground_friction;
        EndianType<float> ground_depth;
        EndianType<Fraction> ground_damp_fraction;
        EndianType<float> ground_normal_k1;
        EndianType<float> ground_normal_k0;
        PAD(0x4);
        EndianType<float> water_friction;
        EndianType<float> water_depth;
        EndianType<float> water_density;
        PAD(0x4);
        EndianType<Fraction> air_friction;
        PAD(0x4);
        EndianType<float> xx_moment;
        EndianType<float> yy_moment;
        EndianType<float> zz_moment;
        TagReflexive<EndianType, PhysicsInertialMatrix> inertial_matrix_and_inverse;
        TagReflexive<EndianType, PhysicsPoweredMassPoint> powered_mass_points;
        TagReflexive<EndianType, PhysicsMassPoint> mass_points;
        ENDIAN_TEMPLATE(NewEndian) operator Physics<NewEndian>() const {
            Physics<NewEndian> copy = {};
            COPY_THIS(radius);
            COPY_THIS(moment_scale);
            COPY_THIS(mass);
            COPY_THIS(center_of_mass);
            COPY_THIS(density);
            COPY_THIS(gravity_scale);
            COPY_THIS(ground_friction);
            COPY_THIS(ground_depth);
            COPY_THIS(ground_damp_fraction);
            COPY_THIS(ground_normal_k1);
            COPY_THIS(ground_normal_k0);
            COPY_THIS(water_friction);
            COPY_THIS(water_depth);
            COPY_THIS(water_density);
            COPY_THIS(air_friction);
            COPY_THIS(xx_moment);
            COPY_THIS(yy_moment);
            COPY_THIS(zz_moment);
            COPY_THIS(inertial_matrix_and_inverse);
            COPY_THIS(powered_mass_points);
            COPY_THIS(mass_points);
            return copy;
        }
    };
    static_assert(sizeof(Physics<NativeEndian>) == 0x80);

    ENDIAN_TEMPLATE(EndianType) struct Placeholder : BasicObject<EndianType> {
        ENDIAN_TEMPLATE(NewEndian) operator Placeholder<NewEndian>() const {
            Placeholder<NewEndian> copy = {};
            COPY_THIS(more_flags);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Placeholder<NativeEndian>) == 0x1FC);

    ENDIAN_TEMPLATE(EndianType) struct PointPhysics {
        EndianType<PointPhysicsFlags> flags;
        LittleEndian<float> unknown_constant;
        LittleEndian<float> water_gravity_scale;
        LittleEndian<float> air_gravity_scale;
        PAD(0x10);
        EndianType<float> density;
        EndianType<float> air_friction;
        EndianType<float> water_friction;
        EndianType<float> surface_friction;
        EndianType<float> elasticity;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator PointPhysics<NewEndian>() const {
            PointPhysics<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(unknown_constant);
            COPY_THIS(water_gravity_scale);
            COPY_THIS(air_gravity_scale);
            COPY_THIS(density);
            COPY_THIS(air_friction);
            COPY_THIS(water_friction);
            COPY_THIS(surface_friction);
            COPY_THIS(elasticity);
            return copy;
        }
    };
    static_assert(sizeof(PointPhysics<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct PreferencesNetworkGame {
        TagString name;
        ColorRGB<EndianType> primary_color;
        ColorRGB<EndianType> secondary_color;
        TagDependency<EndianType> pattern;
        EndianType<Index> pattern_bitmap_index;
        PAD(0x2);
        TagDependency<EndianType> decal;
        EndianType<Index> decal_bitmap_index;
        PAD(0x2);
        PAD(0x320);
        ENDIAN_TEMPLATE(NewEndian) operator PreferencesNetworkGame<NewEndian>() const {
            PreferencesNetworkGame<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(primary_color);
            COPY_THIS(secondary_color);
            COPY_THIS(pattern);
            COPY_THIS(pattern_bitmap_index);
            COPY_THIS(decal);
            COPY_THIS(decal_bitmap_index);
            return copy;
        }
    };
    static_assert(sizeof(PreferencesNetworkGame<NativeEndian>) == 0x380);

    ENDIAN_TEMPLATE(EndianType) struct ProjectileMaterialResponse {
        EndianType<ProjectileMaterialResponseFlags> flags;
        EndianType<ProjectileResponse> default_response;
        TagDependency<EndianType> default_effect;
        PAD(0x10);
        EndianType<ProjectileResponse> potential_response;
        EndianType<ProjectileMaterialResponsePotentialFlags> potential_flags;
        EndianType<Fraction> potential_skip_fraction;
        Bounds<EndianType<Angle>> potential_between;
        Bounds<EndianType<float>> potential_and;
        TagDependency<EndianType> potential_effect;
        PAD(0x10);
        EndianType<ProjectileScaleEffectsBy> scale_effects_by;
        PAD(0x2);
        EndianType<Angle> angular_noise;
        EndianType<float> velocity_noise;
        TagDependency<EndianType> detonation_effect;
        PAD(0x18);
        EndianType<float> initial_friction;
        EndianType<float> maximum_distance;
        EndianType<float> parallel_friction;
        EndianType<float> perpendicular_friction;
        ENDIAN_TEMPLATE(NewEndian) operator ProjectileMaterialResponse<NewEndian>() const {
            ProjectileMaterialResponse<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(default_response);
            COPY_THIS(default_effect);
            COPY_THIS(potential_response);
            COPY_THIS(potential_flags);
            COPY_THIS(potential_skip_fraction);
            COPY_THIS(potential_between);
            COPY_THIS(potential_and);
            COPY_THIS(potential_effect);
            COPY_THIS(scale_effects_by);
            COPY_THIS(angular_noise);
            COPY_THIS(velocity_noise);
            COPY_THIS(detonation_effect);
            COPY_THIS(initial_friction);
            COPY_THIS(maximum_distance);
            COPY_THIS(parallel_friction);
            COPY_THIS(perpendicular_friction);
            return copy;
        }
    };
    static_assert(sizeof(ProjectileMaterialResponse<NativeEndian>) == 0xA0);

    ENDIAN_TEMPLATE(EndianType) struct Projectile : Object<EndianType> {
        EndianType<ProjectileFlags> projectile_flags;
        EndianType<ProjectileDetonationTimerStarts> detonation_timer_starts;
        EndianType<ObjectNoise> impact_noise;
        EndianType<ProjectileFunctionIn> projectile_a_in;
        EndianType<ProjectileFunctionIn> projectile_b_in;
        EndianType<ProjectileFunctionIn> projectile_c_in;
        EndianType<ProjectileFunctionIn> projectile_d_in;
        TagDependency<EndianType> super_detonation;
        EndianType<float> ai_perception_radius;
        EndianType<float> collision_radius;
        EndianType<float> arming_time;
        EndianType<float> danger_radius;
        TagDependency<EndianType> effect;
        Bounds<EndianType<float>> timer;
        EndianType<float> minimum_velocity;
        EndianType<float> maximum_range;
        EndianType<float> air_gravity_scale;
        Bounds<EndianType<float>> air_damage_range;
        EndianType<float> water_gravity_scale;
        Bounds<EndianType<float>> water_damage_range;
        EndianType<float> initial_velocity;
        EndianType<float> final_velocity;
        EndianType<Angle> guided_angular_velocity;
        EndianType<ObjectNoise> detonation_noise;
        PAD(0x2);
        TagDependency<EndianType> detonation_started;
        TagDependency<EndianType> flyby_sound;
        TagDependency<EndianType> attached_detonation_damage;
        TagDependency<EndianType> impact_damage;
        PAD(0xC);
        TagReflexive<EndianType, ProjectileMaterialResponse> projectile_material_response;
        ENDIAN_TEMPLATE(NewEndian) operator Projectile<NewEndian>() const {
            Projectile<NewEndian> copy = {};
            COPY_THIS(projectile_flags);
            COPY_THIS(detonation_timer_starts);
            COPY_THIS(impact_noise);
            COPY_THIS(projectile_a_in);
            COPY_THIS(projectile_b_in);
            COPY_THIS(projectile_c_in);
            COPY_THIS(projectile_d_in);
            COPY_THIS(super_detonation);
            COPY_THIS(ai_perception_radius);
            COPY_THIS(collision_radius);
            COPY_THIS(arming_time);
            COPY_THIS(danger_radius);
            COPY_THIS(effect);
            COPY_THIS(timer);
            COPY_THIS(minimum_velocity);
            COPY_THIS(maximum_range);
            COPY_THIS(air_gravity_scale);
            COPY_THIS(air_damage_range);
            COPY_THIS(water_gravity_scale);
            COPY_THIS(water_damage_range);
            COPY_THIS(initial_velocity);
            COPY_THIS(final_velocity);
            COPY_THIS(guided_angular_velocity);
            COPY_THIS(detonation_noise);
            COPY_THIS(detonation_started);
            COPY_THIS(flyby_sound);
            COPY_THIS(attached_detonation_damage);
            COPY_THIS(impact_damage);
            COPY_THIS(projectile_material_response);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Projectile<NativeEndian>) == 0x24C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioSky {
        TagDependency<EndianType> sky;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioSky<NewEndian>() const {
            ScenarioSky<NewEndian> copy;
            COPY_THIS(sky);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioSky<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioChildScenario {
        TagDependency<EndianType> child_scenario;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioChildScenario<NewEndian>() const {
            ScenarioChildScenario<NewEndian> copy = {};
            COPY_THIS(child_scenario);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioChildScenario<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioFunction {
        EndianType<ScenarioFunctionFlags> flags;
        TagString name;
        EndianType<float> period;
        EndianType<Index> scale_period_by;
        EndianType<WaveFunction> function;
        EndianType<Index> scale_function_by;
        EndianType<WaveFunction> wobble_function;
        EndianType<float> wobble_period;
        EndianType<float> wobble_magnitude;
        EndianType<Fraction> square_wave_threshold;
        EndianType<std::int16_t> step_count;
        EndianType<FunctionType> map_to;
        EndianType<std::int16_t> sawtooth_count;
        PAD(0x2);
        EndianType<Index> scale_result_by;
        EndianType<FunctionBoundsMode> bounds_mode;
        Bounds<EndianType<float>> bounds;
        PAD(0x4);
        PAD(0x2);
        EndianType<Index> turn_off_with;
        PAD(0x10);
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioFunction<NewEndian>() const {
            ScenarioFunction<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(name);
            COPY_THIS(period);
            COPY_THIS(scale_period_by);
            COPY_THIS(function);
            COPY_THIS(scale_function_by);
            COPY_THIS(wobble_function);
            COPY_THIS(wobble_period);
            COPY_THIS(wobble_magnitude);
            COPY_THIS(square_wave_threshold);
            COPY_THIS(step_count);
            COPY_THIS(map_to);
            COPY_THIS(sawtooth_count);
            COPY_THIS(scale_result_by);
            COPY_THIS(bounds_mode);
            COPY_THIS(bounds);
            COPY_THIS(turn_off_with);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioFunction<NativeEndian>) == 0x78);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioEditorComment {
        Point3D<EndianType> position;
        PAD(0x10);
        TagDataOffset<EndianType> comment;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioEditorComment<NewEndian>() const {
            ScenarioEditorComment<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(comment);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioEditorComment<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioScavengerHuntObjects {
        TagString name;
        EndianType<Index> object_name_index;
        PAD(0x2);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioScavengerHuntObjects<NewEndian>() const {
            ScenarioScavengerHuntObjects<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(object_name_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioScavengerHuntObjects<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioObjectName {
        TagString name;
        LittleEndian<ObjectType> object_type;
        LittleEndian<Index> object_index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioObjectName<NewEndian>() const {
            ScenarioObjectName<NewEndian> copy;
            COPY_THIS(name);
            COPY_THIS(object_type);
            COPY_THIS(object_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioObjectName<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioScenery {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        EndianType<std::uint16_t> bsp_indices;
        PAD(0x2);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        PAD(0x10);
        PAD(0x8);
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioScenery<NewEndian>() const {
            ScenarioScenery<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(bsp_indices);
            COPY_THIS(appearance_player_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioScenery<NativeEndian>) == 0x48);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioSceneryPalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioSceneryPalette<NewEndian>() const {
            ScenarioSceneryPalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioSceneryPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioBiped {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x4);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        PAD(0x10);
        PAD(0x8);
        PAD(0x8);
        EndianType<float> body_vitality_modifier;
        EndianType<ScenarioUnitFlags> flags;
        PAD(0x8);
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioBiped<NewEndian>() const {
            ScenarioBiped<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(appearance_player_index);
            COPY_THIS(body_vitality_modifier);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioBiped<NativeEndian>) == 0x78);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioBipedPalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioBipedPalette<NewEndian>() const {
            ScenarioBipedPalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioBipedPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioVehicle {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x4);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        PAD(0x10);
        PAD(0x8);
        PAD(0x8);
        EndianType<float> body_vitality;
        EndianType<ScenarioUnitFlags> flags;
        PAD(0x8);
        std::int8_t multiplayer_team_index;
        PAD(0x1);
        EndianType<ScenarioVehicleMultiplayerSpawnFlags> multiplayer_spawn_flags;
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioVehicle<NewEndian>() const {
            ScenarioVehicle<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(appearance_player_index);
            COPY_THIS(body_vitality);
            COPY_THIS(flags);
            COPY_THIS(multiplayer_team_index);
            COPY_THIS(multiplayer_spawn_flags);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioVehicle<NativeEndian>) == 0x78);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioVehiclePalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioVehiclePalette<NewEndian>() const {
            ScenarioVehiclePalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioVehiclePalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioEquipment {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x2);
        EndianType<ScenarioItemFlags> misc_flags;
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioEquipment<NewEndian>() const {
            ScenarioEquipment<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(misc_flags);
            COPY_THIS(appearance_player_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioEquipment<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioEquipmentPalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioEquipmentPalette<NewEndian>() const {
            ScenarioEquipmentPalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioEquipmentPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioWeapon {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x4);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        PAD(0x10);
        PAD(0x8);
        PAD(0x8);
        EndianType<std::int16_t> rounds_reserved;
        EndianType<std::int16_t> rounds_loaded;
        EndianType<ScenarioItemFlags> flags;
        PAD(0x2);
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioWeapon<NewEndian>() const {
            ScenarioWeapon<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(appearance_player_index);
            COPY_THIS(rounds_reserved);
            COPY_THIS(rounds_loaded);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioWeapon<NativeEndian>) == 0x5C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioWeaponPalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioWeaponPalette<NewEndian>() const {
            ScenarioWeaponPalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioWeaponPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioDeviceGroup {
        TagString name;
        EndianType<float> initial_value;
        EndianType<ScenarioDeviceGroupFlags> flags;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioDeviceGroup<NewEndian>() const {
            ScenarioDeviceGroup<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(initial_value);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioDeviceGroup<NativeEndian>) == 0x34);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioMachine {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x4);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        EndianType<Index> power_group;
        EndianType<Index> position_group;
        EndianType<ScenarioDeviceFlags> device_flags;
        EndianType<ScenarioMachineFlags> machine_flags;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioMachine<NewEndian>() const {
            ScenarioMachine<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(appearance_player_index);
            COPY_THIS(power_group);
            COPY_THIS(position_group);
            COPY_THIS(device_flags);
            COPY_THIS(machine_flags);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioMachine<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioMachinePalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioMachinePalette<NewEndian>() const {
            ScenarioMachinePalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioMachinePalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioControl {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x4);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        EndianType<Index> power_group;
        EndianType<Index> position_group;
        EndianType<ScenarioDeviceFlags> device_flags;
        EndianType<ScenarioControlFlags> control_flags;
        EndianType<std::int16_t> custom_control_name;
        PAD(0x2);
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioControl<NewEndian>() const {
            ScenarioControl<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(appearance_player_index);
            COPY_THIS(power_group);
            COPY_THIS(position_group);
            COPY_THIS(device_flags);
            COPY_THIS(control_flags);
            COPY_THIS(custom_control_name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioControl<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioControlPalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioControlPalette<NewEndian>() const {
            ScenarioControlPalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioControlPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioLightFixture {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        EndianType<std::uint16_t> bsp_indices;
        PAD(0x2);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        EndianType<Index> power_group;
        EndianType<Index> position_group;
        EndianType<ScenarioDeviceFlags> device_flags;
        ColorRGB<EndianType> color;
        EndianType<float> intensity;
        EndianType<Angle> falloff_angle;
        EndianType<Angle> cutoff_angle;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioLightFixture<NewEndian>() const {
            ScenarioLightFixture<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(bsp_indices);
            COPY_THIS(appearance_player_index);
            COPY_THIS(power_group);
            COPY_THIS(position_group);
            COPY_THIS(device_flags);
            COPY_THIS(color);
            COPY_THIS(intensity);
            COPY_THIS(falloff_angle);
            COPY_THIS(cutoff_angle);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioLightFixture<NativeEndian>) == 0x58);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioLightFixturePalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioLightFixturePalette<NewEndian>() const {
            ScenarioLightFixturePalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioLightFixturePalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioSoundScenery {
        EndianType<Index> type;
        EndianType<Index> name;
        EndianType<ScenarioSpawnNotPlaced> not_placed;
        EndianType<std::int16_t> desired_permutation;
        Point3D<EndianType> position;
        Euler3D<EndianType> rotation;
        PAD(0x4);
        EndianType<std::int8_t> appearance_player_index;
        PAD(0x3);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioSoundScenery<NewEndian>() const {
            ScenarioSoundScenery<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(name);
            COPY_THIS(not_placed);
            COPY_THIS(desired_permutation);
            COPY_THIS(position);
            COPY_THIS(rotation);
            COPY_THIS(appearance_player_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioSoundScenery<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioSoundSceneryPalette {
        TagDependency<EndianType> name;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioSoundSceneryPalette<NewEndian>() const {
            ScenarioSoundSceneryPalette<NewEndian> copy = {};
            COPY_THIS(name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioSoundSceneryPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioPlayerStartingProfile {
        TagString name;
        EndianType<Fraction> starting_health_modifier;
        EndianType<Fraction> starting_shield_modifier;
        TagDependency<EndianType> primary_weapon;
        EndianType<std::int16_t> primary_rounds_loaded;
        EndianType<std::int16_t> primary_rounds_reserved;
        TagDependency<EndianType> secondary_weapon;
        EndianType<std::int16_t> secondary_rounds_loaded;
        EndianType<std::int16_t> secondary_rounds_reserved;
        std::int8_t starting_fragmentation_grenade_count;
        std::int8_t starting_plasma_grenade_count;
        std::int8_t starting_grenade_type2_count;
        std::int8_t starting_grenade_type3_count;
        PAD(0x14);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioPlayerStartingProfile<NewEndian>() const {
            ScenarioPlayerStartingProfile<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(starting_health_modifier);
            COPY_THIS(starting_shield_modifier);
            COPY_THIS(primary_weapon);
            COPY_THIS(primary_rounds_loaded);
            COPY_THIS(primary_rounds_reserved);
            COPY_THIS(secondary_weapon);
            COPY_THIS(secondary_rounds_loaded);
            COPY_THIS(secondary_rounds_reserved);
            COPY_THIS(starting_fragmentation_grenade_count);
            COPY_THIS(starting_plasma_grenade_count);
            COPY_THIS(starting_grenade_type2_count);
            COPY_THIS(starting_grenade_type3_count);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioPlayerStartingProfile<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioPlayerStartingLocation {
        Point3D<EndianType> position;
        EndianType<Angle> facing;
        EndianType<Index> team_index;
        EndianType<Index> bsp_index;
        EndianType<ScenarioSpawnType> type_0;
        EndianType<ScenarioSpawnType> type_1;
        EndianType<ScenarioSpawnType> type_2;
        EndianType<ScenarioSpawnType> type_3;
        PAD(0x18);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioPlayerStartingLocation<NewEndian>() const {
            ScenarioPlayerStartingLocation<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(facing);
            COPY_THIS(team_index);
            COPY_THIS(bsp_index);
            COPY_THIS(type_0);
            COPY_THIS(type_1);
            COPY_THIS(type_2);
            COPY_THIS(type_3);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioPlayerStartingLocation<NativeEndian>) == 0x34);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioTriggerVolume {
        LittleEndian<std::uint16_t> unknown;
        PAD(0x2);
        TagString name;
        EndianType<float> parameters[3];
        Vector3D<EndianType> rotation_vector_a;
        Vector3D<EndianType> rotation_vector_b;
        Point3D<EndianType> starting_corner;
        Point3D<EndianType> ending_corner_offset;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioTriggerVolume<NewEndian>() const {
            ScenarioTriggerVolume<NewEndian> copy = {};
            COPY_THIS(unknown);
            COPY_THIS(name);
            COPY_THIS_ARRAY(parameters);
            COPY_THIS(rotation_vector_a);
            COPY_THIS(rotation_vector_b);
            COPY_THIS(starting_corner);
            COPY_THIS(ending_corner_offset);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioTriggerVolume<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioRecordedAnimation {
        TagString name;
        std::int8_t version;
        std::int8_t raw_animation_data;
        std::int8_t unit_control_data_version;
        PAD(0x1);
        EndianType<std::int16_t> length_of_animation;
        PAD(0x2);
        PAD(0x4);
        TagDataOffset<EndianType> recorded_animation_event_stream;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioRecordedAnimation<NewEndian>() const {
            ScenarioRecordedAnimation<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(version);
            COPY_THIS(raw_animation_data);
            COPY_THIS(unit_control_data_version);
            COPY_THIS(length_of_animation);
            COPY_THIS(recorded_animation_event_stream);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioRecordedAnimation<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioNetgameFlags {
        Point3D<EndianType> position;
        EndianType<Angle> facing;
        EndianType<ScenarioNetgameFlagType> type;
        EndianType<Index> usage_id;
        TagDependency<EndianType> weapon_group;
        PAD(0x70);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioNetgameFlags<NewEndian>() const {
            ScenarioNetgameFlags<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(facing);
            COPY_THIS(type);
            COPY_THIS(usage_id);
            COPY_THIS(weapon_group);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioNetgameFlags<NativeEndian>) == 0x94);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioNetgameEquipment {
        EndianType<ScenarioNetgameEquipmentFlags> flags;
        EndianType<ScenarioSpawnType> type_0;
        EndianType<ScenarioSpawnType> type_1;
        EndianType<ScenarioSpawnType> type_2;
        EndianType<ScenarioSpawnType> type_3;
        EndianType<Index> team_index;
        EndianType<std::int16_t> spawn_time;
        EndianType<std::uint32_t> unknown_ffffffff;
        PAD(0x2C);
        Point3D<EndianType> position;
        EndianType<Angle> facing;
        TagDependency<EndianType> item_collection;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioNetgameEquipment<NewEndian>() const {
            ScenarioNetgameEquipment<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(type_0);
            COPY_THIS(type_1);
            COPY_THIS(type_2);
            COPY_THIS(type_3);
            COPY_THIS(team_index);
            COPY_THIS(spawn_time);
            COPY_THIS(unknown_ffffffff);
            COPY_THIS(position);
            COPY_THIS(facing);
            COPY_THIS(item_collection);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioNetgameEquipment<NativeEndian>) == 0x90);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStartingEquipment {
        EndianType<ScenarioStartingEquipmentFlags> flags;
        EndianType<ScenarioSpawnType> type_0;
        EndianType<ScenarioSpawnType> type_1;
        EndianType<ScenarioSpawnType> type_2;
        EndianType<ScenarioSpawnType> type_3;
        PAD(0x30);
        TagDependency<EndianType> item_collection_1;
        TagDependency<EndianType> item_collection_2;
        TagDependency<EndianType> item_collection_3;
        TagDependency<EndianType> item_collection_4;
        TagDependency<EndianType> item_collection_5;
        TagDependency<EndianType> item_collection_6;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStartingEquipment<NewEndian>() const {
            ScenarioStartingEquipment<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(type_0);
            COPY_THIS(type_1);
            COPY_THIS(type_2);
            COPY_THIS(type_3);
            COPY_THIS(item_collection_1);
            COPY_THIS(item_collection_2);
            COPY_THIS(item_collection_3);
            COPY_THIS(item_collection_4);
            COPY_THIS(item_collection_5);
            COPY_THIS(item_collection_6);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStartingEquipment<NativeEndian>) == 0xCC);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioBSPSwitchTriggerVolume {
        EndianType<Index> trigger_volume;
        EndianType<Index> source;
        EndianType<Index> destination;
        LittleEndian<std::uint16_t> unknown;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioBSPSwitchTriggerVolume<NewEndian>() const {
            ScenarioBSPSwitchTriggerVolume<NewEndian> copy;
            COPY_THIS(trigger_volume);
            COPY_THIS(source);
            COPY_THIS(destination);
            COPY_THIS(unknown);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioBSPSwitchTriggerVolume<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioDecal {
        EndianType<Index> decal_type;
        std::int8_t yaw;
        std::int8_t pitch;
        Point3D<EndianType> position;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioDecal<NewEndian>() const {
            ScenarioDecal<NewEndian> copy;
            COPY_THIS(decal_type);
            COPY_THIS(yaw);
            COPY_THIS(pitch);
            COPY_THIS(position);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioDecal<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioDecalPalette {
        TagDependency<EndianType> reference;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioDecalPalette<NewEndian>() const {
            ScenarioDecalPalette<NewEndian> copy;
            COPY_THIS(reference);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioDecalPalette<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioDetailObjectCollectionPalette {
        TagDependency<EndianType> reference;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioDetailObjectCollectionPalette<NewEndian>() const {
            ScenarioDetailObjectCollectionPalette<NewEndian> copy = {};
            COPY_THIS(reference);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioDetailObjectCollectionPalette<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioActorPalette {
        TagDependency<EndianType> reference;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioActorPalette<NewEndian>() const {
            ScenarioActorPalette<NewEndian> copy;
            COPY_THIS(reference);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioActorPalette<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioMovePosition {
        Point3D<EndianType> position;
        EndianType<Angle> facing;
        EndianType<float> weight;
        Bounds<EndianType<float>> time;
        EndianType<Index> animation;
        std::int8_t sequence_id;
        PAD(0x1);
        PAD(0x8);
        LittleEndian<Index> cluster_index;
        PAD(0x22);
        LittleEndian<std::uint32_t> surface_index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioMovePosition<NewEndian>() const {
            ScenarioMovePosition<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(facing);
            COPY_THIS(weight);
            COPY_THIS(time);
            COPY_THIS(animation);
            COPY_THIS(sequence_id);
            COPY_THIS(cluster_index);
            COPY_THIS(surface_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioMovePosition<NativeEndian>) == 0x50);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioActorStartingLocation {
        Point3D<EndianType> position;
        EndianType<Angle> facing;
        LittleEndian<Index> cluster_index;
        std::int8_t sequence_id;
        EndianType<ScenarioActorStartingLocationFlags> flags;
        EndianType<ScenarioReturnState> return_state;
        EndianType<ScenarioReturnState> initial_state;
        EndianType<Index> actor_type;
        EndianType<Index> command_list;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioActorStartingLocation<NewEndian>() const {
            ScenarioActorStartingLocation<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(facing);
            COPY_THIS(cluster_index);
            COPY_THIS(sequence_id);
            COPY_THIS(flags);
            COPY_THIS(return_state);
            COPY_THIS(initial_state);
            COPY_THIS(actor_type);
            COPY_THIS(command_list);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioActorStartingLocation<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioSquad {
        TagString name;
        EndianType<Index> actor_type;
        EndianType<Index> platoon;
        EndianType<ScenarioReturnState> initial_state;
        EndianType<ScenarioReturnState> return_state;
        EndianType<ScenarioSquadFlags> flags;
        EndianType<ScenarioUniqueLeaderType> unique_leader_type;
        PAD(0x2);
        PAD(0x1C);
        PAD(0x2);
        EndianType<Index> maneuver_to_squad;
        EndianType<float> squad_delay_time;
        EndianType<ScenarioSquadAttacking> attacking;
        EndianType<ScenarioSquadAttacking> attacking_search;
        EndianType<ScenarioSquadAttacking> attacking_guard;
        EndianType<ScenarioSquadAttacking> defending;
        EndianType<ScenarioSquadAttacking> defending_search;
        EndianType<ScenarioSquadAttacking> defending_guard;
        EndianType<ScenarioSquadAttacking> pursuing;
        PAD(0x4);
        PAD(0x8);
        EndianType<std::int16_t> normal_diff_count;
        EndianType<std::int16_t> insane_diff_count;
        EndianType<ScenarioMajorUpgrade> major_upgrade;
        PAD(0x2);
        EndianType<std::int16_t> respawn_min_actors;
        EndianType<std::int16_t> respawn_max_actors;
        EndianType<std::int16_t> respawn_total;
        PAD(0x2);
        Bounds<EndianType<float>> respawn_delay;
        PAD(0x30);
        TagReflexive<EndianType, ScenarioMovePosition> move_positions;
        TagReflexive<EndianType, ScenarioActorStartingLocation> starting_locations;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioSquad<NewEndian>() const {
            ScenarioSquad<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(actor_type);
            COPY_THIS(platoon);
            COPY_THIS(initial_state);
            COPY_THIS(return_state);
            COPY_THIS(flags);
            COPY_THIS(unique_leader_type);
            COPY_THIS(maneuver_to_squad);
            COPY_THIS(squad_delay_time);
            COPY_THIS(attacking);
            COPY_THIS(attacking_search);
            COPY_THIS(attacking_guard);
            COPY_THIS(defending);
            COPY_THIS(defending_search);
            COPY_THIS(defending_guard);
            COPY_THIS(pursuing);
            COPY_THIS(normal_diff_count);
            COPY_THIS(insane_diff_count);
            COPY_THIS(major_upgrade);
            COPY_THIS(respawn_min_actors);
            COPY_THIS(respawn_max_actors);
            COPY_THIS(respawn_total);
            COPY_THIS(respawn_delay);
            COPY_THIS(move_positions);
            COPY_THIS(starting_locations);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioSquad<NativeEndian>) == 0xE8);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioPlatoon {
        TagString name;
        EndianType<ScenarioPlatoonFlags> flags;
        PAD(0xC);
        EndianType<ScenarioChangeAttackingDefendingStateWhen> change_attacking_defending_state_when;
        EndianType<Index> happens_to;
        PAD(0x4);
        PAD(0x4);
        EndianType<ScenarioChangeAttackingDefendingStateWhen> maneuver_when;
        EndianType<Index> happens_to_1;
        PAD(0x4);
        PAD(0x4);
        PAD(0x40);
        PAD(0x24);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioPlatoon<NewEndian>() const {
            ScenarioPlatoon<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(change_attacking_defending_state_when);
            COPY_THIS(happens_to);
            COPY_THIS(maneuver_when);
            COPY_THIS(happens_to_1);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioPlatoon<NativeEndian>) == 0xAC);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioFiringPosition {
        Point3D<EndianType> position;
        EndianType<ScenarioGroupIndex> group_index;
        LittleEndian<Index> cluster_index;
        PAD(0x4);
        LittleEndian<std::uint32_t> surface_index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioFiringPosition<NewEndian>() const {
            ScenarioFiringPosition<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(group_index);
            COPY_THIS(cluster_index);
            COPY_THIS(surface_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioFiringPosition<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioEncounter {
        TagString name;
        EndianType<ScenarioEncounterFlags> flags;
        EndianType<ScenarioTeamIndex> team_index;
        LittleEndian<std::int16_t> one;
        EndianType<ScenarioSearchBehavior> search_behavior;
        EndianType<Index> manual_bsp_index;
        Bounds<EndianType<float>> respawn_delay;
        PAD(0x4A);
        LittleEndian<Index> precomputed_bsp_index;
        TagReflexive<EndianType, ScenarioSquad> squads;
        TagReflexive<EndianType, ScenarioPlatoon> platoons;
        TagReflexive<EndianType, ScenarioFiringPosition> firing_positions;
        TagReflexive<EndianType, ScenarioPlayerStartingLocation> player_starting_locations;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioEncounter<NewEndian>() const {
            ScenarioEncounter<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(team_index);
            COPY_THIS(one);
            COPY_THIS(search_behavior);
            COPY_THIS(manual_bsp_index);
            COPY_THIS(respawn_delay);
            COPY_THIS(precomputed_bsp_index);
            COPY_THIS(squads);
            COPY_THIS(platoons);
            COPY_THIS(firing_positions);
            COPY_THIS(player_starting_locations);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioEncounter<NativeEndian>) == 0xB0);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioCommand {
        EndianType<ScenarioAtomType> atom_type;
        EndianType<std::int16_t> atom_modifier;
        EndianType<float> parameter1;
        EndianType<float> parameter2;
        EndianType<Index> point_1;
        EndianType<Index> point_2;
        EndianType<Index> animation;
        EndianType<Index> script;
        EndianType<Index> recording;
        EndianType<Index> command;
        EndianType<Index> object_name;
        PAD(0x6);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioCommand<NewEndian>() const {
            ScenarioCommand<NewEndian> copy = {};
            COPY_THIS(atom_type);
            COPY_THIS(atom_modifier);
            COPY_THIS(parameter1);
            COPY_THIS(parameter2);
            COPY_THIS(point_1);
            COPY_THIS(point_2);
            COPY_THIS(animation);
            COPY_THIS(script);
            COPY_THIS(recording);
            COPY_THIS(command);
            COPY_THIS(object_name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioCommand<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioCommandPoint {
        Point3D<EndianType> position;
        LittleEndian<std::uint32_t> surface_index;
        PAD(0x4);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioCommandPoint<NewEndian>() const {
            ScenarioCommandPoint<NewEndian> copy = {};
            COPY_THIS(position);
            COPY_THIS(surface_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioCommandPoint<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioCommandList {
        TagString name;
        EndianType<ScenarioCommandListFlags> flags;
        PAD(0x8);
        EndianType<Index> manual_bsp_index;
        LittleEndian<Index> precomputed_bsp_index;
        TagReflexive<EndianType, ScenarioCommand> commands;
        TagReflexive<EndianType, ScenarioCommandPoint> points;
        PAD(0x18);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioCommandList<NewEndian>() const {
            ScenarioCommandList<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(manual_bsp_index);
            COPY_THIS(precomputed_bsp_index);
            COPY_THIS(commands);
            COPY_THIS(points);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioCommandList<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioAIAnimationReference {
        TagString animation_name;
        TagDependency<EndianType> animation_graph;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioAIAnimationReference<NewEndian>() const {
            ScenarioAIAnimationReference<NewEndian> copy = {};
            COPY_THIS(animation_name);
            COPY_THIS(animation_graph);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioAIAnimationReference<NativeEndian>) == 0x3C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioAIScriptReference {
        TagString script_name;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioAIScriptReference<NewEndian>() const {
            ScenarioAIScriptReference<NewEndian> copy = {};
            COPY_THIS(script_name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioAIScriptReference<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioAIRecordingReference {
        TagString recording_name;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioAIRecordingReference<NewEndian>() const {
            ScenarioAIRecordingReference<NewEndian> copy = {};
            COPY_THIS(recording_name);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioAIRecordingReference<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioAIConversationParticipant {
        PAD(0x2);
        EndianType<ScenarioAIConversationParticipantFlags> flags;
        EndianType<ScenarioSelectionType> selection_type;
        EndianType<ActorType> actor_type;
        EndianType<Index> use_this_object;
        EndianType<Index> set_new_name;
        PAD(0xC);
        LittleEndian<std::uint16_t> variant_numbers[6];
        TagString encounter_name;
        LittleEndian<std::uint32_t> encounter_index;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioAIConversationParticipant<NewEndian>() const {
            ScenarioAIConversationParticipant<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(selection_type);
            COPY_THIS(actor_type);
            COPY_THIS(use_this_object);
            COPY_THIS(set_new_name);
            COPY_THIS_ARRAY(variant_numbers);
            COPY_THIS(encounter_name);
            COPY_THIS(encounter_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioAIConversationParticipant<NativeEndian>) == 0x54);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioAIConversationLine {
        EndianType<ScenarioAIConversationLineFlags> flags;
        EndianType<Index> participant;
        EndianType<ScenarioAddressee> addressee;
        EndianType<Index> addressee_participant;
        PAD(0x4);
        EndianType<float> line_delay_time;
        PAD(0xC);
        TagDependency<EndianType> variant_1;
        TagDependency<EndianType> variant_2;
        TagDependency<EndianType> variant_3;
        TagDependency<EndianType> variant_4;
        TagDependency<EndianType> variant_5;
        TagDependency<EndianType> variant_6;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioAIConversationLine<NewEndian>() const {
            ScenarioAIConversationLine<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(participant);
            COPY_THIS(addressee);
            COPY_THIS(addressee_participant);
            COPY_THIS(line_delay_time);
            COPY_THIS(variant_1);
            COPY_THIS(variant_2);
            COPY_THIS(variant_3);
            COPY_THIS(variant_4);
            COPY_THIS(variant_5);
            COPY_THIS(variant_6);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioAIConversationLine<NativeEndian>) == 0x7C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioAIConversation {
        TagString name;
        EndianType<ScenarioAIConversationFlags> flags;
        PAD(0x2);
        EndianType<float> trigger_distance;
        EndianType<float> run_to_player_dist;
        PAD(0x24);
        TagReflexive<EndianType, ScenarioAIConversationParticipant> participants;
        TagReflexive<EndianType, ScenarioAIConversationLine> lines;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioAIConversation<NewEndian>() const {
            ScenarioAIConversation<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(trigger_distance);
            COPY_THIS(run_to_player_dist);
            COPY_THIS(participants);
            COPY_THIS(lines);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioAIConversation<NativeEndian>) == 0x74);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioScriptParameter {
        TagString name;
        EndianType<ScenarioScriptValueType> return_type;
        PAD(0x2);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioScriptParameter<NewEndian>() const {
            ScenarioScriptParameter<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(return_type);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioScriptParameter<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioScript {
        TagString name;
        EndianType<ScenarioScriptType> script_type;
        EndianType<ScenarioScriptValueType> return_type;
        EndianType<std::uint32_t> root_expression_index;
        PAD(0x28);
        TagReflexive<EndianType, ScenarioScriptParameter> parameters;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioScript<NewEndian>() const {
            ScenarioScript<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(script_type);
            COPY_THIS(return_type);
            COPY_THIS(root_expression_index);
            COPY_THIS(parameters);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioScript<NativeEndian>) == 0x5C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioGlobal {
        TagString name;
        EndianType<ScenarioScriptValueType> type;
        PAD(0x2);
        PAD(0x4);
        EndianType<std::int32_t> initialization_expression_index;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioGlobal<NewEndian>() const {
            ScenarioGlobal<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(type);
            COPY_THIS(initialization_expression_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioGlobal<NativeEndian>) == 0x5C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioReference {
        PAD(0x18);
        TagDependency<EndianType> reference;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioReference<NewEndian>() const {
            ScenarioReference<NewEndian> copy = {};
            COPY_THIS(reference);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioReference<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioSourceFile {
        TagString name;
        TagDataOffset<EndianType> source;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioSourceFile<NewEndian>() const {
            ScenarioSourceFile<NewEndian> copy;
            COPY_THIS(name);
            COPY_THIS(source);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioSourceFile<NativeEndian>) == 0x34);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioCutsceneFlag {
        LittleEndian<std::uint32_t> unknown;
        TagString name;
        Point3D<EndianType> position;
        Euler2D<EndianType> facing;
        PAD(0x24);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioCutsceneFlag<NewEndian>() const {
            ScenarioCutsceneFlag<NewEndian> copy = {};
            COPY_THIS(unknown);
            COPY_THIS(name);
            COPY_THIS(position);
            COPY_THIS(facing);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioCutsceneFlag<NativeEndian>) == 0x5C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioCutsceneCameraPoint {
        LittleEndian<std::uint32_t> unknown;
        TagString name;
        PAD(0x4);
        Point3D<EndianType> position;
        Euler3D<EndianType> orientation;
        EndianType<Angle> field_of_view;
        PAD(0x24);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioCutsceneCameraPoint<NewEndian>() const {
            ScenarioCutsceneCameraPoint<NewEndian> copy = {};
            COPY_THIS(unknown);
            COPY_THIS(name);
            COPY_THIS(position);
            COPY_THIS(orientation);
            COPY_THIS(field_of_view);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioCutsceneCameraPoint<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioCutsceneTitle {
        LittleEndian<std::uint32_t> unknown;
        TagString name;
        PAD(0x4);
        Rectangle2D<EndianType> text_bounds;
        EndianType<Index> string_index;
        EndianType<ScenarioTextStyle> text_style;
        EndianType<ScenarioJustification> justification;
        PAD(0x2);
        EndianType<ScenarioTextFlags> text_flags;
        EndianType<ColorARGBInt> text_color;
        EndianType<ColorARGBInt> shadow_color;
        EndianType<float> fade_in_time;
        EndianType<float> up_time;
        EndianType<float> fade_out_time;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioCutsceneTitle<NewEndian>() const {
            ScenarioCutsceneTitle<NewEndian> copy = {};
            COPY_THIS(unknown);
            COPY_THIS(name);
            COPY_THIS(text_bounds);
            COPY_THIS(string_index);
            COPY_THIS(text_style);
            COPY_THIS(justification);
            COPY_THIS(text_flags);
            COPY_THIS(text_color);
            COPY_THIS(shadow_color);
            COPY_THIS(fade_in_time);
            COPY_THIS(up_time);
            COPY_THIS(fade_out_time);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioCutsceneTitle<NativeEndian>) == 0x60);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioBSP {
        LittleEndian<std::uint32_t> bsp_start;
        LittleEndian<std::uint32_t> bsp_size;
        LittleEndian<std::uint32_t> bsp_address;
        PAD(0x4);
        TagDependency<EndianType> structure_bsp;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioBSP<NewEndian>() const {
            ScenarioBSP<NewEndian> copy = {};
            COPY_THIS(bsp_start);
            COPY_THIS(bsp_size);
            COPY_THIS(bsp_address);
            COPY_THIS(structure_bsp);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioBSP<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioScriptNode {
        EndianType<std::uint16_t> salt;
        EndianType<std::uint16_t> index_union;
        EndianType<ScenarioScriptValueType> type;
        EndianType<ScenarioScriptNodeFlags> flags;
        EndianType<std::uint32_t> next_node;
        EndianType<std::uint32_t> string_offset;
        EndianType<ScenarioScriptNodeValue> data;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioScriptNode<NewEndian>() const {
            ScenarioScriptNode<NewEndian> copy;
            COPY_THIS(salt);
            COPY_THIS(index_union);
            COPY_THIS(type);
            COPY_THIS(flags);
            COPY_THIS(next_node);
            COPY_THIS(string_offset);
            COPY_THIS(data);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioScriptNode<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioScriptNodeTable {
        TagString name;
        EndianType<std::uint16_t> maximum_count;
        EndianType<std::uint16_t> element_size;
        std::uint8_t one;
        PAD(0x3);
        EndianType<std::uint32_t> data;
        PAD(0x2);
        EndianType<std::uint16_t> size;
        EndianType<std::uint16_t> count;
        EndianType<std::uint16_t> next_id;
        EndianType<std::uint32_t> first_element_ptr;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioScriptNodeTable<NewEndian>() const {
            ScenarioScriptNodeTable<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(maximum_count);
            COPY_THIS(element_size);
            COPY_THIS(one);
            COPY_THIS(data);
            COPY_THIS(size);
            COPY_THIS(count);
            COPY_THIS(next_id);
            COPY_THIS(first_element_ptr);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioScriptNodeTable<NativeEndian>) == 0x38);

    ENDIAN_TEMPLATE(EndianType) struct Scenario {
        TagDependency<EndianType> dont_use;
        TagDependency<EndianType> wont_use;
        TagDependency<EndianType> cant_use;
        TagReflexive<EndianType, ScenarioSky> skies;
        EndianType<ScenarioType> type;
        EndianType<ScenarioFlags> flags;
        TagReflexive<EndianType, ScenarioChildScenario> child_scenarios;
        EndianType<float> local_north;
        PAD(0x14);
        PAD(0x88);
        TagReflexive<EndianType, PredictedResource> predicted_resources;
        TagReflexive<EndianType, ScenarioFunction> functions;
        TagDataOffset<EndianType> editor_scenario_data;
        TagReflexive<EndianType, ScenarioEditorComment> comments;
        TagReflexive<EndianType, ScenarioScavengerHuntObjects> scavenger_hunt_objects;
        PAD(0xD4);
        TagReflexive<EndianType, ScenarioObjectName> object_names;
        TagReflexive<EndianType, ScenarioScenery> scenery;
        TagReflexive<EndianType, ScenarioSceneryPalette> scenery_palette;
        TagReflexive<EndianType, ScenarioBiped> bipeds;
        TagReflexive<EndianType, ScenarioBipedPalette> biped_palette;
        TagReflexive<EndianType, ScenarioVehicle> vehicles;
        TagReflexive<EndianType, ScenarioVehiclePalette> vehicle_palette;
        TagReflexive<EndianType, ScenarioEquipment> equipment;
        TagReflexive<EndianType, ScenarioEquipmentPalette> equipment_palette;
        TagReflexive<EndianType, ScenarioWeapon> weapons;
        TagReflexive<EndianType, ScenarioWeaponPalette> weapon_palette;
        TagReflexive<EndianType, ScenarioDeviceGroup> device_groups;
        TagReflexive<EndianType, ScenarioMachine> machines;
        TagReflexive<EndianType, ScenarioMachinePalette> machine_palette;
        TagReflexive<EndianType, ScenarioControl> controls;
        TagReflexive<EndianType, ScenarioControlPalette> control_palette;
        TagReflexive<EndianType, ScenarioLightFixture> light_fixtures;
        TagReflexive<EndianType, ScenarioLightFixturePalette> light_fixture_palette;
        TagReflexive<EndianType, ScenarioSoundScenery> sound_scenery;
        TagReflexive<EndianType, ScenarioSoundSceneryPalette> sound_scenery_palette;
        PAD(0x54);
        TagReflexive<EndianType, ScenarioPlayerStartingProfile> player_starting_profile;
        TagReflexive<EndianType, ScenarioPlayerStartingLocation> player_starting_locations;
        TagReflexive<EndianType, ScenarioTriggerVolume> trigger_volumes;
        TagReflexive<EndianType, ScenarioRecordedAnimation> recorded_animations;
        TagReflexive<EndianType, ScenarioNetgameFlags> netgame_flags;
        TagReflexive<EndianType, ScenarioNetgameEquipment> netgame_equipment;
        TagReflexive<EndianType, ScenarioStartingEquipment> starting_equipment;
        TagReflexive<EndianType, ScenarioBSPSwitchTriggerVolume> bsp_switch_trigger_volumes;
        TagReflexive<EndianType, ScenarioDecal> decals;
        TagReflexive<EndianType, ScenarioDecalPalette> decal_palette;
        TagReflexive<EndianType, ScenarioDetailObjectCollectionPalette> detail_object_collection_palette;
        PAD(0x54);
        TagReflexive<EndianType, ScenarioActorPalette> actor_palette;
        TagReflexive<EndianType, ScenarioEncounter> encounters;
        TagReflexive<EndianType, ScenarioCommandList> command_lists;
        TagReflexive<EndianType, ScenarioAIAnimationReference> ai_animation_references;
        TagReflexive<EndianType, ScenarioAIScriptReference> ai_script_references;
        TagReflexive<EndianType, ScenarioAIRecordingReference> ai_recording_references;
        TagReflexive<EndianType, ScenarioAIConversation> ai_conversations;
        TagDataOffset<EndianType> script_syntax_data;
        TagDataOffset<EndianType> script_string_data;
        TagReflexive<EndianType, ScenarioScript> scripts;
        TagReflexive<EndianType, ScenarioGlobal> globals;
        TagReflexive<EndianType, ScenarioReference> references;
        TagReflexive<EndianType, ScenarioSourceFile> source_files;
        PAD(0x18);
        TagReflexive<EndianType, ScenarioCutsceneFlag> cutscene_flags;
        TagReflexive<EndianType, ScenarioCutsceneCameraPoint> cutscene_camera_points;
        TagReflexive<EndianType, ScenarioCutsceneTitle> cutscene_titles;
        PAD(0x6C);
        TagDependency<EndianType> custom_object_names;
        TagDependency<EndianType> ingame_help_text;
        TagDependency<EndianType> hud_messages;
        TagReflexive<EndianType, ScenarioBSP> structure_bsps;
        ENDIAN_TEMPLATE(NewEndian) operator Scenario<NewEndian>() const {
            Scenario<NewEndian> copy = {};
            COPY_THIS(dont_use);
            COPY_THIS(wont_use);
            COPY_THIS(cant_use);
            COPY_THIS(skies);
            COPY_THIS(type);
            COPY_THIS(flags);
            COPY_THIS(child_scenarios);
            COPY_THIS(local_north);
            COPY_THIS(predicted_resources);
            COPY_THIS(functions);
            COPY_THIS(editor_scenario_data);
            COPY_THIS(comments);
            COPY_THIS(scavenger_hunt_objects);
            COPY_THIS(object_names);
            COPY_THIS(scenery);
            COPY_THIS(scenery_palette);
            COPY_THIS(bipeds);
            COPY_THIS(biped_palette);
            COPY_THIS(vehicles);
            COPY_THIS(vehicle_palette);
            COPY_THIS(equipment);
            COPY_THIS(equipment_palette);
            COPY_THIS(weapons);
            COPY_THIS(weapon_palette);
            COPY_THIS(device_groups);
            COPY_THIS(machines);
            COPY_THIS(machine_palette);
            COPY_THIS(controls);
            COPY_THIS(control_palette);
            COPY_THIS(light_fixtures);
            COPY_THIS(light_fixture_palette);
            COPY_THIS(sound_scenery);
            COPY_THIS(sound_scenery_palette);
            COPY_THIS(player_starting_profile);
            COPY_THIS(player_starting_locations);
            COPY_THIS(trigger_volumes);
            COPY_THIS(recorded_animations);
            COPY_THIS(netgame_flags);
            COPY_THIS(netgame_equipment);
            COPY_THIS(starting_equipment);
            COPY_THIS(bsp_switch_trigger_volumes);
            COPY_THIS(decals);
            COPY_THIS(decal_palette);
            COPY_THIS(detail_object_collection_palette);
            COPY_THIS(actor_palette);
            COPY_THIS(encounters);
            COPY_THIS(command_lists);
            COPY_THIS(ai_animation_references);
            COPY_THIS(ai_script_references);
            COPY_THIS(ai_recording_references);
            COPY_THIS(ai_conversations);
            COPY_THIS(script_syntax_data);
            COPY_THIS(script_string_data);
            COPY_THIS(scripts);
            COPY_THIS(globals);
            COPY_THIS(references);
            COPY_THIS(source_files);
            COPY_THIS(cutscene_flags);
            COPY_THIS(cutscene_camera_points);
            COPY_THIS(cutscene_titles);
            COPY_THIS(custom_object_names);
            COPY_THIS(ingame_help_text);
            COPY_THIS(hud_messages);
            COPY_THIS(structure_bsps);
            return copy;
        }
    };
    static_assert(sizeof(Scenario<NativeEndian>) == 0x5B0);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPCollisionMaterial {
        TagDependency<EndianType> shader;
        PAD(0x2);
        LittleEndian<MaterialType> material;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPCollisionMaterial<NewEndian>() const {
            ScenarioStructureBSPCollisionMaterial<NewEndian> copy = {};
            COPY_THIS(shader);
            COPY_THIS(material);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPCollisionMaterial<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPNode {
        LittleEndian<std::uint16_t> node_stuff[3];
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPNode<NewEndian>() const {
            ScenarioStructureBSPNode<NewEndian> copy;
            COPY_THIS_ARRAY(node_stuff);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPNode<NativeEndian>) == 0x6);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPLeaf {
        LittleEndian<std::uint16_t> vertices[3];
        PAD(0x2);
        EndianType<Index> cluster;
        EndianType<std::int16_t> surface_reference_count;
        EndianType<std::int32_t> surface_references;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPLeaf<NewEndian>() const {
            ScenarioStructureBSPLeaf<NewEndian> copy = {};
            COPY_THIS_ARRAY(vertices);
            COPY_THIS(cluster);
            COPY_THIS(surface_reference_count);
            COPY_THIS(surface_references);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPLeaf<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPSurfaceReference {
        EndianType<std::int32_t> surface;
        EndianType<std::int32_t> node;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPSurfaceReference<NewEndian>() const {
            ScenarioStructureBSPSurfaceReference<NewEndian> copy;
            COPY_THIS(surface);
            COPY_THIS(node);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPSurfaceReference<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPSurface {
        EndianType<Index> vertex0_index;
        EndianType<Index> vertex1_index;
        EndianType<Index> vertex2_index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPSurface<NewEndian>() const {
            ScenarioStructureBSPSurface<NewEndian> copy;
            COPY_THIS(vertex0_index);
            COPY_THIS(vertex1_index);
            COPY_THIS(vertex2_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPSurface<NativeEndian>) == 0x6);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMaterialUncompressedRenderedVertex {
        Point3D<EndianType> position;
        Vector3D<EndianType> normal;
        Vector3D<EndianType> binormal;
        Vector3D<EndianType> tangent;
        Point2D<EndianType> texture_coords;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMaterialUncompressedRenderedVertex<NewEndian>() const {
            ScenarioStructureBSPMaterialUncompressedRenderedVertex<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(normal);
            COPY_THIS(binormal);
            COPY_THIS(tangent);
            COPY_THIS(texture_coords);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMaterialUncompressedRenderedVertex<NativeEndian>) == 0x38);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMaterialCompressedRenderedVertex {
        Point3D<EndianType> position;
        EndianType<std::uint32_t> normal;
        EndianType<std::uint32_t> binormal;
        EndianType<std::uint32_t> tangent;
        Point2D<EndianType> texture_coords;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMaterialCompressedRenderedVertex<NewEndian>() const {
            ScenarioStructureBSPMaterialCompressedRenderedVertex<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(normal);
            COPY_THIS(binormal);
            COPY_THIS(tangent);
            COPY_THIS(texture_coords);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMaterialCompressedRenderedVertex<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMaterialUncompressedLightmapVertex {
        Vector3D<EndianType> normal;
        Point2D<EndianType> texture_coords;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMaterialUncompressedLightmapVertex<NewEndian>() const {
            ScenarioStructureBSPMaterialUncompressedLightmapVertex<NewEndian> copy;
            COPY_THIS(normal);
            COPY_THIS(texture_coords);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMaterialUncompressedLightmapVertex<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMaterialCompressedLightmapVertex {
        EndianType<std::uint32_t> normal;
        EndianType<std::int16_t> texture_coordinate_x;
        EndianType<std::int16_t> texture_coordinate_y;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMaterialCompressedLightmapVertex<NewEndian>() const {
            ScenarioStructureBSPMaterialCompressedLightmapVertex<NewEndian> copy;
            COPY_THIS(normal);
            COPY_THIS(texture_coordinate_x);
            COPY_THIS(texture_coordinate_y);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMaterialCompressedLightmapVertex<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMaterial {
        TagDependency<EndianType> shader;
        EndianType<Index> shader_permutation;
        EndianType<ScenarioStructureBSPMaterialFlags> flags;
        EndianType<std::int32_t> surfaces;
        EndianType<std::int32_t> surface_count;
        Point3D<EndianType> centroid;
        ColorRGB<EndianType> ambient_color;
        EndianType<std::int16_t> distant_light_count;
        PAD(0x2);
        ColorRGB<EndianType> distant_light_0_color;
        Vector3D<EndianType> distant_light_0_direction;
        ColorRGB<EndianType> distant_light_1_color;
        Vector3D<EndianType> distant_light_1_direction;
        PAD(0xC);
        ColorARGB<EndianType> reflection_tint;
        Vector3D<EndianType> shadow_vector;
        ColorRGB<EndianType> shadow_color;
        Plane3D<EndianType> plane;
        EndianType<Index> breakable_surface;
        PAD(0x2);
        LittleEndian<VertexType> rendered_vertices_type;
        PAD(0x2);
        EndianType<std::uint32_t> rendered_vertices_count;
        EndianType<std::uint32_t> rendered_vertices_offset;
        PAD(0x4);
        LittleEndian<Pointer> rendered_vertices_index_pointer;
        LittleEndian<VertexType> lightmap_vertices_type;
        PAD(0x2);
        EndianType<std::uint32_t> lightmap_vertices_count;
        EndianType<std::uint32_t> lightmap_vertices_offset;
        PAD(0x4);
        LittleEndian<Pointer> lightmap_vertices_index_pointer;
        TagDataOffset<EndianType> uncompressed_vertices;
        TagDataOffset<EndianType> compressed_vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMaterial<NewEndian>() const {
            ScenarioStructureBSPMaterial<NewEndian> copy = {};
            COPY_THIS(shader);
            COPY_THIS(shader_permutation);
            COPY_THIS(flags);
            COPY_THIS(surfaces);
            COPY_THIS(surface_count);
            COPY_THIS(centroid);
            COPY_THIS(ambient_color);
            COPY_THIS(distant_light_count);
            COPY_THIS(distant_light_0_color);
            COPY_THIS(distant_light_0_direction);
            COPY_THIS(distant_light_1_color);
            COPY_THIS(distant_light_1_direction);
            COPY_THIS(reflection_tint);
            COPY_THIS(shadow_vector);
            COPY_THIS(shadow_color);
            COPY_THIS(plane);
            COPY_THIS(breakable_surface);
            COPY_THIS(rendered_vertices_type);
            COPY_THIS(rendered_vertices_count);
            COPY_THIS(rendered_vertices_offset);
            COPY_THIS(rendered_vertices_index_pointer);
            COPY_THIS(lightmap_vertices_type);
            COPY_THIS(lightmap_vertices_count);
            COPY_THIS(lightmap_vertices_offset);
            COPY_THIS(lightmap_vertices_index_pointer);
            COPY_THIS(uncompressed_vertices);
            COPY_THIS(compressed_vertices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMaterial<NativeEndian>) == 0x100);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPLightmap {
        EndianType<Index> bitmap;
        PAD(0x2);
        PAD(0x10);
        TagReflexive<EndianType, ScenarioStructureBSPMaterial> materials;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPLightmap<NewEndian>() const {
            ScenarioStructureBSPLightmap<NewEndian> copy = {};
            COPY_THIS(bitmap);
            COPY_THIS(materials);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPLightmap<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPLensFlare {
        TagDependency<EndianType> lens;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPLensFlare<NewEndian>() const {
            ScenarioStructureBSPLensFlare<NewEndian> copy;
            COPY_THIS(lens);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPLensFlare<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPLensFlareMarker {
        Point3D<EndianType> position;
        std::int8_t direction_i_component;
        std::int8_t direction_j_component;
        std::int8_t direction_k_component;
        std::int8_t lens_flare_index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPLensFlareMarker<NewEndian>() const {
            ScenarioStructureBSPLensFlareMarker<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(direction_i_component);
            COPY_THIS(direction_j_component);
            COPY_THIS(direction_k_component);
            COPY_THIS(lens_flare_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPLensFlareMarker<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPSubclusterSurfaceIndex {
        EndianType<std::int32_t> index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPSubclusterSurfaceIndex<NewEndian>() const {
            ScenarioStructureBSPSubclusterSurfaceIndex<NewEndian> copy;
            COPY_THIS(index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPSubclusterSurfaceIndex<NativeEndian>) == 0x4);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPSubcluster {
        Bounds<EndianType<float>> world_bounds_x;
        Bounds<EndianType<float>> world_bounds_y;
        Bounds<EndianType<float>> world_bounds_z;
        TagReflexive<EndianType, ScenarioStructureBSPSubclusterSurfaceIndex> surface_indices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPSubcluster<NewEndian>() const {
            ScenarioStructureBSPSubcluster<NewEndian> copy;
            COPY_THIS(world_bounds_x);
            COPY_THIS(world_bounds_y);
            COPY_THIS(world_bounds_z);
            COPY_THIS(surface_indices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPSubcluster<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPClusterSurfaceIndex {
        EndianType<std::int32_t> index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPClusterSurfaceIndex<NewEndian>() const {
            ScenarioStructureBSPClusterSurfaceIndex<NewEndian> copy;
            COPY_THIS(index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPClusterSurfaceIndex<NativeEndian>) == 0x4);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMirrorVertex {
        Point3D<EndianType> point;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMirrorVertex<NewEndian>() const {
            ScenarioStructureBSPMirrorVertex<NewEndian> copy;
            COPY_THIS(point);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMirrorVertex<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMirror {
        Plane3D<EndianType> plane;
        PAD(0x14);
        TagDependency<EndianType> shader;
        TagReflexive<EndianType, ScenarioStructureBSPMirrorVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMirror<NewEndian>() const {
            ScenarioStructureBSPMirror<NewEndian> copy = {};
            COPY_THIS(plane);
            COPY_THIS(shader);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMirror<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPClusterPortalIndex {
        EndianType<Index> portal;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPClusterPortalIndex<NewEndian>() const {
            ScenarioStructureBSPClusterPortalIndex<NewEndian> copy;
            COPY_THIS(portal);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPClusterPortalIndex<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPCluster {
        EndianType<Index> sky;
        EndianType<Index> fog;
        EndianType<Index> background_sound;
        EndianType<Index> sound_environment;
        EndianType<Index> weather;
        EndianType<Index> transition_structure_bsp;
        LittleEndian<Index> first_decal_index;
        LittleEndian<std::uint16_t> decal_count;
        PAD(0x18);
        TagReflexive<EndianType, PredictedResource> predicted_resources;
        TagReflexive<EndianType, ScenarioStructureBSPSubcluster> subclusters;
        EndianType<Index> first_lens_flare_marker_index;
        EndianType<std::int16_t> lens_flare_marker_count;
        TagReflexive<EndianType, ScenarioStructureBSPClusterSurfaceIndex> surface_indices;
        TagReflexive<EndianType, ScenarioStructureBSPMirror> mirrors;
        TagReflexive<EndianType, ScenarioStructureBSPClusterPortalIndex> portals;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPCluster<NewEndian>() const {
            ScenarioStructureBSPCluster<NewEndian> copy = {};
            COPY_THIS(sky);
            COPY_THIS(fog);
            COPY_THIS(background_sound);
            COPY_THIS(sound_environment);
            COPY_THIS(weather);
            COPY_THIS(transition_structure_bsp);
            COPY_THIS(first_decal_index);
            COPY_THIS(decal_count);
            COPY_THIS(predicted_resources);
            COPY_THIS(subclusters);
            COPY_THIS(first_lens_flare_marker_index);
            COPY_THIS(lens_flare_marker_count);
            COPY_THIS(surface_indices);
            COPY_THIS(mirrors);
            COPY_THIS(portals);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPCluster<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPClusterPortalVertex {
        Point3D<EndianType> point;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPClusterPortalVertex<NewEndian>() const {
            ScenarioStructureBSPClusterPortalVertex<NewEndian> copy;
            COPY_THIS(point);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPClusterPortalVertex<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPClusterPortal {
        EndianType<Index> front_cluster;
        EndianType<Index> back_cluster;
        EndianType<std::int32_t> plane_index;
        Point3D<EndianType> centroid;
        EndianType<float> bounding_radius;
        EndianType<ScenarioStructureBSPClusterPortalFlags> flags;
        PAD(0x18);
        TagReflexive<EndianType, ScenarioStructureBSPClusterPortalVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPClusterPortal<NewEndian>() const {
            ScenarioStructureBSPClusterPortal<NewEndian> copy = {};
            COPY_THIS(front_cluster);
            COPY_THIS(back_cluster);
            COPY_THIS(plane_index);
            COPY_THIS(centroid);
            COPY_THIS(bounding_radius);
            COPY_THIS(flags);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPClusterPortal<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPBreakableSurface {
        Point3D<EndianType> centroid;
        EndianType<float> radius;
        EndianType<std::int32_t> collision_surface_index;
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPBreakableSurface<NewEndian>() const {
            ScenarioStructureBSPBreakableSurface<NewEndian> copy = {};
            COPY_THIS(centroid);
            COPY_THIS(radius);
            COPY_THIS(collision_surface_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPBreakableSurface<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPFogPlaneVertex {
        Point3D<EndianType> point;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPFogPlaneVertex<NewEndian>() const {
            ScenarioStructureBSPFogPlaneVertex<NewEndian> copy;
            COPY_THIS(point);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPFogPlaneVertex<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPFogPlane {
        EndianType<Index> front_region;
        LittleEndian<MaterialType> material_type;
        Plane3D<EndianType> plane;
        TagReflexive<EndianType, ScenarioStructureBSPFogPlaneVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPFogPlane<NewEndian>() const {
            ScenarioStructureBSPFogPlane<NewEndian> copy;
            COPY_THIS(front_region);
            COPY_THIS(material_type);
            COPY_THIS(plane);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPFogPlane<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPFogRegion {
        PAD(0x24);
        EndianType<Index> fog;
        EndianType<Index> weather_palette;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPFogRegion<NewEndian>() const {
            ScenarioStructureBSPFogRegion<NewEndian> copy = {};
            COPY_THIS(fog);
            COPY_THIS(weather_palette);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPFogRegion<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPFogPalette {
        TagString name;
        TagDependency<EndianType> fog;
        PAD(0x4);
        TagString fog_scale_function;
        PAD(0x34);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPFogPalette<NewEndian>() const {
            ScenarioStructureBSPFogPalette<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(fog);
            COPY_THIS(fog_scale_function);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPFogPalette<NativeEndian>) == 0x88);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPWeatherPalette {
        TagString name;
        TagDependency<EndianType> particle_system;
        PAD(0x4);
        TagString particle_system_scale_function;
        PAD(0x2C);
        TagDependency<EndianType> wind;
        Vector3D<EndianType> wind_direction;
        EndianType<float> wind_magnitude;
        PAD(0x4);
        TagString wind_scale_function;
        PAD(0x2C);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPWeatherPalette<NewEndian>() const {
            ScenarioStructureBSPWeatherPalette<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(particle_system);
            COPY_THIS(particle_system_scale_function);
            COPY_THIS(wind);
            COPY_THIS(wind_direction);
            COPY_THIS(wind_magnitude);
            COPY_THIS(wind_scale_function);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPWeatherPalette<NativeEndian>) == 0xF0);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPWeatherPolyhedronPlane {
        Plane3D<EndianType> plane;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPWeatherPolyhedronPlane<NewEndian>() const {
            ScenarioStructureBSPWeatherPolyhedronPlane<NewEndian> copy;
            COPY_THIS(plane);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPWeatherPolyhedronPlane<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPWeatherPolyhedron {
        Point3D<EndianType> bounding_sphere_center;
        EndianType<float> bounding_sphere_radius;
        PAD(0x4);
        TagReflexive<EndianType, ScenarioStructureBSPWeatherPolyhedronPlane> planes;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPWeatherPolyhedron<NewEndian>() const {
            ScenarioStructureBSPWeatherPolyhedron<NewEndian> copy = {};
            COPY_THIS(bounding_sphere_center);
            COPY_THIS(bounding_sphere_radius);
            COPY_THIS(planes);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPWeatherPolyhedron<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPPathfindingSurface {
        std::int8_t data;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPPathfindingSurface<NewEndian>() const {
            ScenarioStructureBSPPathfindingSurface<NewEndian> copy;
            COPY_THIS(data);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPPathfindingSurface<NativeEndian>) == 0x1);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPPathfindingEdge {
        std::int8_t midpoint;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPPathfindingEdge<NewEndian>() const {
            ScenarioStructureBSPPathfindingEdge<NewEndian> copy;
            COPY_THIS(midpoint);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPPathfindingEdge<NativeEndian>) == 0x1);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPBackgroundSoundPalette {
        TagString name;
        TagDependency<EndianType> background_sound;
        PAD(0x4);
        TagString scale_function;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPBackgroundSoundPalette<NewEndian>() const {
            ScenarioStructureBSPBackgroundSoundPalette<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(background_sound);
            COPY_THIS(scale_function);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPBackgroundSoundPalette<NativeEndian>) == 0x74);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPSoundEnvironmentPalette {
        TagString name;
        TagDependency<EndianType> sound_environment;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPSoundEnvironmentPalette<NewEndian>() const {
            ScenarioStructureBSPSoundEnvironmentPalette<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(sound_environment);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPSoundEnvironmentPalette<NativeEndian>) == 0x50);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMarker {
        TagString name;
        Quaternion<EndianType> rotation;
        Point3D<EndianType> position;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMarker<NewEndian>() const {
            ScenarioStructureBSPMarker<NewEndian> copy;
            COPY_THIS(name);
            COPY_THIS(rotation);
            COPY_THIS(position);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMarker<NativeEndian>) == 0x3C);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPGlobalDetailObjectCell {
        EndianType<std::int16_t> cell_x;
        EndianType<std::int16_t> cell_y;
        EndianType<std::int16_t> cell_z;
        EndianType<std::int16_t> offset_z;
        EndianType<std::int32_t> valid_layers_flags;
        EndianType<std::int32_t> start_index;
        EndianType<std::int32_t> count_index;
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPGlobalDetailObjectCell<NewEndian>() const {
            ScenarioStructureBSPGlobalDetailObjectCell<NewEndian> copy = {};
            COPY_THIS(cell_x);
            COPY_THIS(cell_y);
            COPY_THIS(cell_z);
            COPY_THIS(offset_z);
            COPY_THIS(valid_layers_flags);
            COPY_THIS(start_index);
            COPY_THIS(count_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPGlobalDetailObjectCell<NativeEndian>) == 0x20);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPGlobalDetailObject {
        std::int8_t position_x;
        std::int8_t position_y;
        std::int8_t position_z;
        std::int8_t data;
        EndianType<std::int16_t> color;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPGlobalDetailObject<NewEndian>() const {
            ScenarioStructureBSPGlobalDetailObject<NewEndian> copy;
            COPY_THIS(position_x);
            COPY_THIS(position_y);
            COPY_THIS(position_z);
            COPY_THIS(data);
            COPY_THIS(color);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPGlobalDetailObject<NativeEndian>) == 0x6);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPGlobalDetailObjectCount {
        EndianType<std::int16_t> count;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPGlobalDetailObjectCount<NewEndian>() const {
            ScenarioStructureBSPGlobalDetailObjectCount<NewEndian> copy;
            COPY_THIS(count);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPGlobalDetailObjectCount<NativeEndian>) == 0x2);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPGlobalZReferenceVector {
        EndianType<float> z_reference_i;
        EndianType<float> z_reference_j;
        EndianType<float> z_reference_k;
        EndianType<float> z_reference_l;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPGlobalZReferenceVector<NewEndian>() const {
            ScenarioStructureBSPGlobalZReferenceVector<NewEndian> copy;
            COPY_THIS(z_reference_i);
            COPY_THIS(z_reference_j);
            COPY_THIS(z_reference_k);
            COPY_THIS(z_reference_l);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPGlobalZReferenceVector<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPDetailObjectData {
        TagReflexive<EndianType, ScenarioStructureBSPGlobalDetailObjectCell> cells;
        TagReflexive<EndianType, ScenarioStructureBSPGlobalDetailObject> instances;
        TagReflexive<EndianType, ScenarioStructureBSPGlobalDetailObjectCount> counts;
        TagReflexive<EndianType, ScenarioStructureBSPGlobalZReferenceVector> z_reference_vectors;
        std::uint8_t bullshit;
        PAD(0x3);
        PAD(0xC);
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPDetailObjectData<NewEndian>() const {
            ScenarioStructureBSPDetailObjectData<NewEndian> copy = {};
            COPY_THIS(cells);
            COPY_THIS(instances);
            COPY_THIS(counts);
            COPY_THIS(z_reference_vectors);
            COPY_THIS(bullshit);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPDetailObjectData<NativeEndian>) == 0x40);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPRuntimeDecal {
        Point3D<EndianType> position;
        EndianType<Index> decal_type;
        std::int8_t yaw;
        std::int8_t pitch;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPRuntimeDecal<NewEndian>() const {
            ScenarioStructureBSPRuntimeDecal<NewEndian> copy;
            COPY_THIS(position);
            COPY_THIS(decal_type);
            COPY_THIS(yaw);
            COPY_THIS(pitch);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPRuntimeDecal<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMapLeafFaceVertex {
        Point2D<EndianType> vertex;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMapLeafFaceVertex<NewEndian>() const {
            ScenarioStructureBSPMapLeafFaceVertex<NewEndian> copy;
            COPY_THIS(vertex);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMapLeafFaceVertex<NativeEndian>) == 0x8);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMapLeafFace {
        EndianType<std::int32_t> node_index;
        TagReflexive<EndianType, ScenarioStructureBSPMapLeafFaceVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMapLeafFace<NewEndian>() const {
            ScenarioStructureBSPMapLeafFace<NewEndian> copy;
            COPY_THIS(node_index);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMapLeafFace<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPMapLeafPortalIndex {
        EndianType<std::int32_t> portal_index;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPMapLeafPortalIndex<NewEndian>() const {
            ScenarioStructureBSPMapLeafPortalIndex<NewEndian> copy;
            COPY_THIS(portal_index);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPMapLeafPortalIndex<NativeEndian>) == 0x4);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPGlobalMapLeaf {
        TagReflexive<EndianType, ScenarioStructureBSPMapLeafFace> faces;
        TagReflexive<EndianType, ScenarioStructureBSPMapLeafPortalIndex> portal_indices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPGlobalMapLeaf<NewEndian>() const {
            ScenarioStructureBSPGlobalMapLeaf<NewEndian> copy;
            COPY_THIS(faces);
            COPY_THIS(portal_indices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPGlobalMapLeaf<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPLeafPortalVertex {
        Point3D<EndianType> point;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPLeafPortalVertex<NewEndian>() const {
            ScenarioStructureBSPLeafPortalVertex<NewEndian> copy;
            COPY_THIS(point);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPLeafPortalVertex<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPGlobalLeafPortal {
        EndianType<std::int32_t> plane_index;
        EndianType<std::int32_t> back_leaf_index;
        EndianType<std::int32_t> front_leaf_index;
        TagReflexive<EndianType, ScenarioStructureBSPLeafPortalVertex> vertices;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPGlobalLeafPortal<NewEndian>() const {
            ScenarioStructureBSPGlobalLeafPortal<NewEndian> copy;
            COPY_THIS(plane_index);
            COPY_THIS(back_leaf_index);
            COPY_THIS(front_leaf_index);
            COPY_THIS(vertices);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPGlobalLeafPortal<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSP {
        TagDependency<EndianType> lightmaps_bitmap;
        EndianType<float> vehicle_floor;
        EndianType<float> vehicle_ceiling;
        PAD(0x14);
        ColorRGB<EndianType> default_ambient_color;
        PAD(0x4);
        ColorRGB<EndianType> default_distant_light_0_color;
        Vector3D<EndianType> default_distant_light_0_direction;
        ColorRGB<EndianType> default_distant_light_1_color;
        Vector3D<EndianType> default_distant_light_1_direction;
        PAD(0xC);
        ColorARGB<EndianType> default_reflection_tint;
        Vector3D<EndianType> default_shadow_vector;
        ColorRGB<EndianType> default_shadow_color;
        PAD(0x4);
        TagReflexive<EndianType, ScenarioStructureBSPCollisionMaterial> collision_materials;
        TagReflexive<EndianType, ModelCollisionGeometryBSP> collision_bsp;
        TagReflexive<EndianType, ScenarioStructureBSPNode> nodes;
        Bounds<EndianType<float>> world_bounds_x;
        Bounds<EndianType<float>> world_bounds_y;
        Bounds<EndianType<float>> world_bounds_z;
        TagReflexive<EndianType, ScenarioStructureBSPLeaf> leaves;
        TagReflexive<EndianType, ScenarioStructureBSPSurfaceReference> leaf_surfaces;
        TagReflexive<EndianType, ScenarioStructureBSPSurface> surfaces;
        TagReflexive<EndianType, ScenarioStructureBSPLightmap> lightmaps;
        PAD(0xC);
        TagReflexive<EndianType, ScenarioStructureBSPLensFlare> lens_flares;
        TagReflexive<EndianType, ScenarioStructureBSPLensFlareMarker> lens_flare_markers;
        TagReflexive<EndianType, ScenarioStructureBSPCluster> clusters;
        TagDataOffset<EndianType> cluster_data;
        TagReflexive<EndianType, ScenarioStructureBSPClusterPortal> cluster_portals;
        PAD(0xC);
        TagReflexive<EndianType, ScenarioStructureBSPBreakableSurface> breakable_surfaces;
        TagReflexive<EndianType, ScenarioStructureBSPFogPlane> fog_planes;
        TagReflexive<EndianType, ScenarioStructureBSPFogRegion> fog_regions;
        TagReflexive<EndianType, ScenarioStructureBSPFogPalette> fog_palette;
        PAD(0x18);
        TagReflexive<EndianType, ScenarioStructureBSPWeatherPalette> weather_palette;
        TagReflexive<EndianType, ScenarioStructureBSPWeatherPolyhedron> weather_polyhedra;
        PAD(0x18);
        TagReflexive<EndianType, ScenarioStructureBSPPathfindingSurface> pathfinding_surfaces;
        TagReflexive<EndianType, ScenarioStructureBSPPathfindingEdge> pathfinding_edges;
        TagReflexive<EndianType, ScenarioStructureBSPBackgroundSoundPalette> background_sound_palette;
        TagReflexive<EndianType, ScenarioStructureBSPSoundEnvironmentPalette> sound_environment_palette;
        TagDataOffset<EndianType> sound_pas_data;
        PAD(0x18);
        TagReflexive<EndianType, ScenarioStructureBSPMarker> markers;
        TagReflexive<EndianType, ScenarioStructureBSPDetailObjectData> detail_objects;
        TagReflexive<EndianType, ScenarioStructureBSPRuntimeDecal> runtime_decals;
        PAD(0x8);
        PAD(0x4);
        TagReflexive<EndianType, ScenarioStructureBSPGlobalMapLeaf> leaf_map_leaves;
        TagReflexive<EndianType, ScenarioStructureBSPGlobalLeafPortal> leaf_map_portals;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSP<NewEndian>() const {
            ScenarioStructureBSP<NewEndian> copy = {};
            COPY_THIS(lightmaps_bitmap);
            COPY_THIS(vehicle_floor);
            COPY_THIS(vehicle_ceiling);
            COPY_THIS(default_ambient_color);
            COPY_THIS(default_distant_light_0_color);
            COPY_THIS(default_distant_light_0_direction);
            COPY_THIS(default_distant_light_1_color);
            COPY_THIS(default_distant_light_1_direction);
            COPY_THIS(default_reflection_tint);
            COPY_THIS(default_shadow_vector);
            COPY_THIS(default_shadow_color);
            COPY_THIS(collision_materials);
            COPY_THIS(collision_bsp);
            COPY_THIS(nodes);
            COPY_THIS(world_bounds_x);
            COPY_THIS(world_bounds_y);
            COPY_THIS(world_bounds_z);
            COPY_THIS(leaves);
            COPY_THIS(leaf_surfaces);
            COPY_THIS(surfaces);
            COPY_THIS(lightmaps);
            COPY_THIS(lens_flares);
            COPY_THIS(lens_flare_markers);
            COPY_THIS(clusters);
            COPY_THIS(cluster_data);
            COPY_THIS(cluster_portals);
            COPY_THIS(breakable_surfaces);
            COPY_THIS(fog_planes);
            COPY_THIS(fog_regions);
            COPY_THIS(fog_palette);
            COPY_THIS(weather_palette);
            COPY_THIS(weather_polyhedra);
            COPY_THIS(pathfinding_surfaces);
            COPY_THIS(pathfinding_edges);
            COPY_THIS(background_sound_palette);
            COPY_THIS(sound_environment_palette);
            COPY_THIS(sound_pas_data);
            COPY_THIS(markers);
            COPY_THIS(detail_objects);
            COPY_THIS(runtime_decals);
            COPY_THIS(leaf_map_leaves);
            COPY_THIS(leaf_map_portals);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSP<NativeEndian>) == 0x288);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPCompiledHeader {
        LittleEndian<Pointer> pointer;
        EndianType<std::uint32_t> lightmap_material_count;
        EndianType<Pointer> rendered_vertices;
        EndianType<std::uint32_t> lightmap_material_count_again;
        EndianType<Pointer> lightmap_vertices;
        LittleEndian<TagFourCC> signature;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPCompiledHeader<NewEndian>() const {
            ScenarioStructureBSPCompiledHeader<NewEndian> copy;
            COPY_THIS(pointer);
            COPY_THIS(lightmap_material_count);
            COPY_THIS(rendered_vertices);
            COPY_THIS(lightmap_material_count_again);
            COPY_THIS(lightmap_vertices);
            COPY_THIS(signature);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPCompiledHeader<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct ScenarioStructureBSPCompiledHeaderCEA {
        LittleEndian<Pointer> pointer;
        EndianType<std::uint32_t> lightmap_vertex_size;
        EndianType<std::uint32_t> lightmap_vertices;
        PAD(0x8);
        LittleEndian<TagFourCC> signature;
        ENDIAN_TEMPLATE(NewEndian) operator ScenarioStructureBSPCompiledHeaderCEA<NewEndian>() const {
            ScenarioStructureBSPCompiledHeaderCEA<NewEndian> copy = {};
            COPY_THIS(pointer);
            COPY_THIS(lightmap_vertex_size);
            COPY_THIS(lightmap_vertices);
            COPY_THIS(signature);
            return copy;
        }
    };
    static_assert(sizeof(ScenarioStructureBSPCompiledHeaderCEA<NativeEndian>) == 0x18);

    ENDIAN_TEMPLATE(EndianType) struct Scenery : BasicObject<EndianType> {
        ENDIAN_TEMPLATE(NewEndian) operator Scenery<NewEndian>() const {
            Scenery<NewEndian> copy = {};
            COPY_THIS(more_flags);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Scenery<NativeEndian>) == 0x1FC);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentExtraLayer {
        TagDependency<EndianType> shader;
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentExtraLayer<NewEndian>() const {
            ShaderTransparentExtraLayer<NewEndian> copy;
            COPY_THIS(shader);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentExtraLayer<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct Shader {
        EndianType<ShaderFlags> shader_flags;
        EndianType<ShaderDetailLevel> detail_level;
        EndianType<float> power;
        ColorRGB<EndianType> color_of_emitted_light;
        ColorRGB<EndianType> tint_color;
        ShaderPhysicsFlags physics_flags;
        EndianType<MaterialType> material_type;
        LittleEndian<std::uint16_t> shader_type;
        PAD(0x2);
        ENDIAN_TEMPLATE(NewEndian) operator Shader<NewEndian>() const {
            Shader<NewEndian> copy = {};
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(Shader<NativeEndian>) == 0x28);

    ENDIAN_TEMPLATE(EndianType) struct ShaderEnvironment : Shader<EndianType> {
        EndianType<ShaderEnvironmentFlags> shader_environment_flags;
        EndianType<ShaderEnvironmentType> shader_environment_type;
        EndianType<float> lens_flare_spacing;
        TagDependency<EndianType> lens_flare;
        PAD(0x2C);
        EndianType<ShaderEnvironmentDiffuseFlags> diffuse_flags;
        PAD(0x2);
        PAD(0x18);
        TagDependency<EndianType> base_map;
        PAD(0x18);
        EndianType<ShaderDetailFunction> detail_map_function;
        PAD(0x2);
        EndianType<float> primary_detail_map_scale;
        TagDependency<EndianType> primary_detail_map;
        EndianType<float> secondary_detail_map_scale;
        TagDependency<EndianType> secondary_detail_map;
        PAD(0x18);
        EndianType<ShaderDetailFunction> micro_detail_map_function;
        PAD(0x2);
        EndianType<float> micro_detail_map_scale;
        TagDependency<EndianType> micro_detail_map;
        ColorRGB<EndianType> material_color;
        PAD(0xC);
        EndianType<float> bump_map_scale;
        TagDependency<EndianType> bump_map;
        Point2D<LittleEndian> bump_map_scale_xy;
        PAD(0x10);
        EndianType<WaveFunction> u_animation_function;
        PAD(0x2);
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_scale;
        EndianType<WaveFunction> v_animation_function;
        PAD(0x2);
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_scale;
        PAD(0x18);
        EndianType<IsUnfilteredFlag> self_illumination_flags;
        PAD(0x2);
        PAD(0x18);
        ColorRGB<EndianType> primary_on_color;
        ColorRGB<EndianType> primary_off_color;
        EndianType<WaveFunction> primary_animation_function;
        PAD(0x2);
        EndianType<float> primary_animation_period;
        EndianType<float> primary_animation_phase;
        PAD(0x18);
        ColorRGB<EndianType> secondary_on_color;
        ColorRGB<EndianType> secondary_off_color;
        EndianType<WaveFunction> secondary_animation_function;
        PAD(0x2);
        EndianType<float> secondary_animation_period;
        EndianType<float> secondary_animation_phase;
        PAD(0x18);
        ColorRGB<EndianType> plasma_on_color;
        ColorRGB<EndianType> plasma_off_color;
        EndianType<WaveFunction> plasma_animation_function;
        PAD(0x2);
        EndianType<float> plasma_animation_period;
        EndianType<float> plasma_animation_phase;
        PAD(0x18);
        EndianType<float> map_scale;
        TagDependency<EndianType> map;
        PAD(0x18);
        EndianType<ShaderEnvironmentSpecularFlags> specular_flags;
        PAD(0x2);
        PAD(0x10);
        EndianType<Fraction> brightness;
        PAD(0x14);
        ColorRGB<EndianType> perpendicular_color;
        ColorRGB<EndianType> parallel_color;
        PAD(0x10);
        EndianType<ShaderEnvironmentReflectionFlags> reflection_flags;
        EndianType<ShaderEnvironmentReflectionType> reflection_type;
        EndianType<Fraction> lightmap_brightness_scale;
        PAD(0x1C);
        EndianType<Fraction> perpendicular_brightness;
        EndianType<Fraction> parallel_brightness;
        PAD(0x10);
        PAD(0x8);
        PAD(0x10);
        TagDependency<EndianType> reflection_cube_map;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderEnvironment<NewEndian>() const {
            ShaderEnvironment<NewEndian> copy = {};
            COPY_THIS(shader_environment_flags);
            COPY_THIS(shader_environment_type);
            COPY_THIS(lens_flare_spacing);
            COPY_THIS(lens_flare);
            COPY_THIS(diffuse_flags);
            COPY_THIS(base_map);
            COPY_THIS(detail_map_function);
            COPY_THIS(primary_detail_map_scale);
            COPY_THIS(primary_detail_map);
            COPY_THIS(secondary_detail_map_scale);
            COPY_THIS(secondary_detail_map);
            COPY_THIS(micro_detail_map_function);
            COPY_THIS(micro_detail_map_scale);
            COPY_THIS(micro_detail_map);
            COPY_THIS(material_color);
            COPY_THIS(bump_map_scale);
            COPY_THIS(bump_map);
            COPY_THIS(bump_map_scale_xy);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_scale);
            COPY_THIS(self_illumination_flags);
            COPY_THIS(primary_on_color);
            COPY_THIS(primary_off_color);
            COPY_THIS(primary_animation_function);
            COPY_THIS(primary_animation_period);
            COPY_THIS(primary_animation_phase);
            COPY_THIS(secondary_on_color);
            COPY_THIS(secondary_off_color);
            COPY_THIS(secondary_animation_function);
            COPY_THIS(secondary_animation_period);
            COPY_THIS(secondary_animation_phase);
            COPY_THIS(plasma_on_color);
            COPY_THIS(plasma_off_color);
            COPY_THIS(plasma_animation_function);
            COPY_THIS(plasma_animation_period);
            COPY_THIS(plasma_animation_phase);
            COPY_THIS(map_scale);
            COPY_THIS(map);
            COPY_THIS(specular_flags);
            COPY_THIS(brightness);
            COPY_THIS(perpendicular_color);
            COPY_THIS(parallel_color);
            COPY_THIS(reflection_flags);
            COPY_THIS(reflection_type);
            COPY_THIS(lightmap_brightness_scale);
            COPY_THIS(perpendicular_brightness);
            COPY_THIS(parallel_brightness);
            COPY_THIS(reflection_cube_map);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderEnvironment<NativeEndian>) == 0x344);

    ENDIAN_TEMPLATE(EndianType) struct ShaderModel : Shader<EndianType> {
        EndianType<ShaderModelFlags> shader_model_flags;
        PAD(0x2);
        PAD(0xC);
        EndianType<Fraction> translucency;
        PAD(0x10);
        EndianType<FunctionNameNullable> change_color_source;
        PAD(0x2);
        PAD(0x1C);
        EndianType<ShaderModelMoreFlags> shader_model_more_flags;
        PAD(0x2);
        EndianType<FunctionNameNullable> color_source;
        EndianType<WaveFunction> animation_function;
        EndianType<float> animation_period;
        ColorRGB<EndianType> animation_color_lower_bound;
        ColorRGB<EndianType> animation_color_upper_bound;
        PAD(0xC);
        EndianType<float> map_u_scale;
        EndianType<float> map_v_scale;
        TagDependency<EndianType> base_map;
        PAD(0x8);
        TagDependency<EndianType> multipurpose_map;
        PAD(0x8);
        EndianType<ShaderDetailFunction> detail_function;
        EndianType<ShaderModelDetailMask> detail_mask;
        EndianType<float> detail_map_scale;
        TagDependency<EndianType> detail_map;
        EndianType<float> detail_map_v_scale;
        PAD(0xC);
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<float> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        PAD(0x8);
        EndianType<float> reflection_falloff_distance;
        EndianType<float> reflection_cutoff_distance;
        EndianType<Fraction> perpendicular_brightness;
        ColorRGB<EndianType> perpendicular_tint_color;
        EndianType<Fraction> parallel_brightness;
        ColorRGB<EndianType> parallel_tint_color;
        TagDependency<EndianType> reflection_cube_map;
        PAD(0x10);
        LittleEndian<float> unknown;
        PAD(0x10);
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderModel<NewEndian>() const {
            ShaderModel<NewEndian> copy = {};
            COPY_THIS(shader_model_flags);
            COPY_THIS(translucency);
            COPY_THIS(change_color_source);
            COPY_THIS(shader_model_more_flags);
            COPY_THIS(color_source);
            COPY_THIS(animation_function);
            COPY_THIS(animation_period);
            COPY_THIS(animation_color_lower_bound);
            COPY_THIS(animation_color_upper_bound);
            COPY_THIS(map_u_scale);
            COPY_THIS(map_v_scale);
            COPY_THIS(base_map);
            COPY_THIS(multipurpose_map);
            COPY_THIS(detail_function);
            COPY_THIS(detail_mask);
            COPY_THIS(detail_map_scale);
            COPY_THIS(detail_map);
            COPY_THIS(detail_map_v_scale);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            COPY_THIS(reflection_falloff_distance);
            COPY_THIS(reflection_cutoff_distance);
            COPY_THIS(perpendicular_brightness);
            COPY_THIS(perpendicular_tint_color);
            COPY_THIS(parallel_brightness);
            COPY_THIS(parallel_tint_color);
            COPY_THIS(reflection_cube_map);
            COPY_THIS(unknown);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderModel<NativeEndian>) == 0x1B8);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentChicagoMap {
        EndianType<ShaderTransparentChicagoMapFlags> flags;
        PAD(0x2);
        PAD(0x28);
        EndianType<ShaderColorFunctionType> color_function;
        EndianType<ShaderColorFunctionType> alpha_function;
        PAD(0x24);
        EndianType<float> map_u_scale;
        EndianType<float> map_v_scale;
        EndianType<float> map_u_offset;
        EndianType<float> map_v_offset;
        EndianType<float> map_rotation;
        EndianType<Fraction> mipmap_bias;
        TagDependency<EndianType> map;
        PAD(0x28);
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<float> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentChicagoMap<NewEndian>() const {
            ShaderTransparentChicagoMap<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(color_function);
            COPY_THIS(alpha_function);
            COPY_THIS(map_u_scale);
            COPY_THIS(map_v_scale);
            COPY_THIS(map_u_offset);
            COPY_THIS(map_v_offset);
            COPY_THIS(map_rotation);
            COPY_THIS(mipmap_bias);
            COPY_THIS(map);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentChicagoMap<NativeEndian>) == 0xDC);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentChicago : Shader<EndianType> {
        std::uint8_t numeric_counter_limit;
        ShaderTransparentGenericFlags shader_transparent_chicago_flags;
        EndianType<ShaderFirstMapType> first_map_type;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<FunctionOut> framebuffer_fade_source;
        PAD(0x2);
        EndianType<float> lens_flare_spacing;
        TagDependency<EndianType> lens_flare;
        TagReflexive<EndianType, ShaderTransparentExtraLayer> extra_layers;
        TagReflexive<EndianType, ShaderTransparentChicagoMap> maps;
        EndianType<ShaderTransparentChicagoExtraFlags> extra_flags;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentChicago<NewEndian>() const {
            ShaderTransparentChicago<NewEndian> copy = {};
            COPY_THIS(numeric_counter_limit);
            COPY_THIS(shader_transparent_chicago_flags);
            COPY_THIS(first_map_type);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(framebuffer_fade_source);
            COPY_THIS(lens_flare_spacing);
            COPY_THIS(lens_flare);
            COPY_THIS(extra_layers);
            COPY_THIS(maps);
            COPY_THIS(extra_flags);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentChicago<NativeEndian>) == 0x6C);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentChicagoExtended : Shader<EndianType> {
        std::uint8_t numeric_counter_limit;
        ShaderTransparentGenericFlags shader_transparent_chicago_extended_flags;
        EndianType<ShaderFirstMapType> first_map_type;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<FunctionOut> framebuffer_fade_source;
        PAD(0x2);
        EndianType<float> lens_flare_spacing;
        TagDependency<EndianType> lens_flare;
        TagReflexive<EndianType, ShaderTransparentExtraLayer> extra_layers;
        TagReflexive<EndianType, ShaderTransparentChicagoMap> maps_4_stage;
        TagReflexive<EndianType, ShaderTransparentChicagoMap> maps_2_stage;
        EndianType<ShaderTransparentChicagoExtraFlags> extra_flags;
        PAD(0x8);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentChicagoExtended<NewEndian>() const {
            ShaderTransparentChicagoExtended<NewEndian> copy = {};
            COPY_THIS(numeric_counter_limit);
            COPY_THIS(shader_transparent_chicago_extended_flags);
            COPY_THIS(first_map_type);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(framebuffer_fade_source);
            COPY_THIS(lens_flare_spacing);
            COPY_THIS(lens_flare);
            COPY_THIS(extra_layers);
            COPY_THIS(maps_4_stage);
            COPY_THIS(maps_2_stage);
            COPY_THIS(extra_flags);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentChicagoExtended<NativeEndian>) == 0x78);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentGenericMap {
        EndianType<ShaderTransparentGenericMapFlag> flags;
        PAD(0x2);
        EndianType<float> map_u_scale;
        EndianType<float> map_v_scale;
        EndianType<float> map_u_offset;
        EndianType<float> map_v_offset;
        EndianType<float> map_rotation;
        EndianType<Fraction> mipmap_bias;
        TagDependency<EndianType> map;
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<float> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentGenericMap<NewEndian>() const {
            ShaderTransparentGenericMap<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(map_u_scale);
            COPY_THIS(map_v_scale);
            COPY_THIS(map_u_offset);
            COPY_THIS(map_v_offset);
            COPY_THIS(map_rotation);
            COPY_THIS(mipmap_bias);
            COPY_THIS(map);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentGenericMap<NativeEndian>) == 0x64);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentGenericStage {
        EndianType<ShaderTransparentGenericStageFlags> flags;
        PAD(0x2);
        EndianType<FunctionNameNullable> color0_source;
        EndianType<WaveFunction> color0_animation_function;
        EndianType<float> color0_animation_period;
        ColorARGB<EndianType> color0_animation_lower_bound;
        ColorARGB<EndianType> color0_animation_upper_bound;
        ColorARGB<EndianType> color1;
        EndianType<ShaderTransparentGenericStageInputColor> input_a;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_a_mapping;
        EndianType<ShaderTransparentGenericStageInputColor> input_b;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_b_mapping;
        EndianType<ShaderTransparentGenericStageInputColor> input_c;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_c_mapping;
        EndianType<ShaderTransparentGenericStageInputColor> input_d;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_d_mapping;
        EndianType<ShaderTransparentGenericStageOutput> output_ab;
        EndianType<ShaderTransparentGenericStageOutputFunction> output_ab_function;
        EndianType<ShaderTransparentGenericStageOutput> output_bc;
        EndianType<ShaderTransparentGenericStageOutputFunction> output_cd_function;
        EndianType<ShaderTransparentGenericStageOutput> output_ab_cd_mux_sum;
        EndianType<ShaderTransparentGenericStageOutputMapping> output_mapping_color;
        EndianType<ShaderTransparentGenericStageInputAlpha> input_a_alpha;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_a_mapping_alpha;
        EndianType<ShaderTransparentGenericStageInputAlpha> input_b_alpha;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_b_mapping_alpha;
        EndianType<ShaderTransparentGenericStageInputAlpha> input_c_alpha;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_c_mapping_alpha;
        EndianType<ShaderTransparentGenericStageInputAlpha> input_d_alpha;
        EndianType<ShaderTransparentGenericStageInputMappingColor> input_d_mapping_alpha;
        EndianType<ShaderTransparentGenericStageOutput> output_ab_alpha;
        EndianType<ShaderTransparentGenericStageOutput> output_cd_alpha;
        EndianType<ShaderTransparentGenericStageOutput> output_ab_cd_mux_sum_alpha;
        EndianType<ShaderTransparentGenericStageOutputMapping> output_mapping_alpha;
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentGenericStage<NewEndian>() const {
            ShaderTransparentGenericStage<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(color0_source);
            COPY_THIS(color0_animation_function);
            COPY_THIS(color0_animation_period);
            COPY_THIS(color0_animation_lower_bound);
            COPY_THIS(color0_animation_upper_bound);
            COPY_THIS(color1);
            COPY_THIS(input_a);
            COPY_THIS(input_a_mapping);
            COPY_THIS(input_b);
            COPY_THIS(input_b_mapping);
            COPY_THIS(input_c);
            COPY_THIS(input_c_mapping);
            COPY_THIS(input_d);
            COPY_THIS(input_d_mapping);
            COPY_THIS(output_ab);
            COPY_THIS(output_ab_function);
            COPY_THIS(output_bc);
            COPY_THIS(output_cd_function);
            COPY_THIS(output_ab_cd_mux_sum);
            COPY_THIS(output_mapping_color);
            COPY_THIS(input_a_alpha);
            COPY_THIS(input_a_mapping_alpha);
            COPY_THIS(input_b_alpha);
            COPY_THIS(input_b_mapping_alpha);
            COPY_THIS(input_c_alpha);
            COPY_THIS(input_c_mapping_alpha);
            COPY_THIS(input_d_alpha);
            COPY_THIS(input_d_mapping_alpha);
            COPY_THIS(output_ab_alpha);
            COPY_THIS(output_cd_alpha);
            COPY_THIS(output_ab_cd_mux_sum_alpha);
            COPY_THIS(output_mapping_alpha);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentGenericStage<NativeEndian>) == 0x70);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentGeneric : Shader<EndianType> {
        std::uint8_t numeric_counter_limit;
        ShaderTransparentGenericFlags shader_transparent_generic_flags;
        EndianType<ShaderFirstMapType> first_map_type;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<FunctionOut> framebuffer_fade_source;
        PAD(0x2);
        EndianType<float> lens_flare_spacing;
        TagDependency<EndianType> lens_flare;
        TagReflexive<EndianType, ShaderTransparentExtraLayer> extra_layers;
        TagReflexive<EndianType, ShaderTransparentGenericMap> maps;
        TagReflexive<EndianType, ShaderTransparentGenericStage> stages;
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentGeneric<NewEndian>() const {
            ShaderTransparentGeneric<NewEndian> copy = {};
            COPY_THIS(numeric_counter_limit);
            COPY_THIS(shader_transparent_generic_flags);
            COPY_THIS(first_map_type);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(framebuffer_fade_source);
            COPY_THIS(lens_flare_spacing);
            COPY_THIS(lens_flare);
            COPY_THIS(extra_layers);
            COPY_THIS(maps);
            COPY_THIS(stages);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentGeneric<NativeEndian>) == 0x6C);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentGlass : Shader<EndianType> {
        EndianType<ShaderTransparentGlassFlags> shader_transparent_glass_flags;
        PAD(0x2);
        PAD(0x28);
        ColorRGB<EndianType> background_tint_color;
        EndianType<float> background_tint_map_scale;
        TagDependency<EndianType> background_tint_map;
        PAD(0x14);
        PAD(0x2);
        EndianType<ShaderTransparentGlassReflectionType> reflection_type;
        EndianType<Fraction> perpendicular_brightness;
        ColorRGB<EndianType> perpendicular_tint_color;
        EndianType<Fraction> parallel_brightness;
        ColorRGB<EndianType> parallel_tint_color;
        TagDependency<EndianType> reflection_map;
        EndianType<float> bump_map_scale;
        TagDependency<EndianType> bump_map;
        PAD(0x80);
        PAD(0x4);
        EndianType<float> diffuse_map_scale;
        TagDependency<EndianType> diffuse_map;
        EndianType<float> diffuse_detail_map_scale;
        TagDependency<EndianType> diffuse_detail_map;
        PAD(0x1C);
        PAD(0x4);
        EndianType<float> specular_map_scale;
        TagDependency<EndianType> specular_map;
        EndianType<float> specular_detail_map_scale;
        TagDependency<EndianType> specular_detail_map;
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentGlass<NewEndian>() const {
            ShaderTransparentGlass<NewEndian> copy = {};
            COPY_THIS(shader_transparent_glass_flags);
            COPY_THIS(background_tint_color);
            COPY_THIS(background_tint_map_scale);
            COPY_THIS(background_tint_map);
            COPY_THIS(reflection_type);
            COPY_THIS(perpendicular_brightness);
            COPY_THIS(perpendicular_tint_color);
            COPY_THIS(parallel_brightness);
            COPY_THIS(parallel_tint_color);
            COPY_THIS(reflection_map);
            COPY_THIS(bump_map_scale);
            COPY_THIS(bump_map);
            COPY_THIS(diffuse_map_scale);
            COPY_THIS(diffuse_map);
            COPY_THIS(diffuse_detail_map_scale);
            COPY_THIS(diffuse_detail_map);
            COPY_THIS(specular_map_scale);
            COPY_THIS(specular_map);
            COPY_THIS(specular_detail_map_scale);
            COPY_THIS(specular_detail_map);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentGlass<NativeEndian>) == 0x1E0);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentMeter : Shader<EndianType> {
        EndianType<ShaderTransparentMeterFlags> meter_flags;
        PAD(0x2);
        PAD(0x20);
        TagDependency<EndianType> map;
        PAD(0x20);
        ColorRGB<EndianType> gradient_min_color;
        ColorRGB<EndianType> gradient_max_color;
        ColorRGB<EndianType> background_color;
        ColorRGB<EndianType> flash_color;
        ColorRGB<EndianType> meter_tint_color;
        EndianType<Fraction> meter_transparency;
        EndianType<Fraction> background_transparency;
        PAD(0x18);
        EndianType<FunctionOut> meter_brightness_source;
        EndianType<FunctionOut> flash_brightness_source;
        EndianType<FunctionOut> value_source;
        EndianType<FunctionOut> gradient_source;
        EndianType<FunctionOut> flash_extension_source;
        PAD(0x2);
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentMeter<NewEndian>() const {
            ShaderTransparentMeter<NewEndian> copy = {};
            COPY_THIS(meter_flags);
            COPY_THIS(map);
            COPY_THIS(gradient_min_color);
            COPY_THIS(gradient_max_color);
            COPY_THIS(background_color);
            COPY_THIS(flash_color);
            COPY_THIS(meter_tint_color);
            COPY_THIS(meter_transparency);
            COPY_THIS(background_transparency);
            COPY_THIS(meter_brightness_source);
            COPY_THIS(flash_brightness_source);
            COPY_THIS(value_source);
            COPY_THIS(gradient_source);
            COPY_THIS(flash_extension_source);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentMeter<NativeEndian>) == 0x104);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentPlasma : Shader<EndianType> {
        PAD(0x2);
        PAD(0x2);
        EndianType<FunctionOut> intensity_source;
        PAD(0x2);
        EndianType<float> intensity_exponent;
        EndianType<FunctionOut> offset_source;
        PAD(0x2);
        EndianType<float> offset_amount;
        EndianType<float> offset_exponent;
        PAD(0x20);
        EndianType<Fraction> perpendicular_brightness;
        ColorRGB<EndianType> perpendicular_tint_color;
        EndianType<Fraction> parallel_brightness;
        ColorRGB<EndianType> parallel_tint_color;
        EndianType<FunctionNameNullable> tint_color_source;
        PAD(0x2);
        PAD(0x20);
        PAD(0x2);
        PAD(0x2);
        PAD(0x10);
        PAD(0x4);
        PAD(0x4);
        EndianType<float> primary_animation_period;
        Vector3D<EndianType> primary_animation_direction;
        EndianType<float> primary_noise_map_scale;
        TagDependency<EndianType> primary_noise_map;
        PAD(0x20);
        PAD(0x4);
        EndianType<float> secondary_animation_period;
        Vector3D<EndianType> secondary_animation_direction;
        EndianType<float> secondary_noise_map_scale;
        TagDependency<EndianType> secondary_noise_map;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentPlasma<NewEndian>() const {
            ShaderTransparentPlasma<NewEndian> copy = {};
            COPY_THIS(intensity_source);
            COPY_THIS(intensity_exponent);
            COPY_THIS(offset_source);
            COPY_THIS(offset_amount);
            COPY_THIS(offset_exponent);
            COPY_THIS(perpendicular_brightness);
            COPY_THIS(perpendicular_tint_color);
            COPY_THIS(parallel_brightness);
            COPY_THIS(parallel_tint_color);
            COPY_THIS(tint_color_source);
            COPY_THIS(primary_animation_period);
            COPY_THIS(primary_animation_direction);
            COPY_THIS(primary_noise_map_scale);
            COPY_THIS(primary_noise_map);
            COPY_THIS(secondary_animation_period);
            COPY_THIS(secondary_animation_direction);
            COPY_THIS(secondary_noise_map_scale);
            COPY_THIS(secondary_noise_map);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentPlasma<NativeEndian>) == 0x14C);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentWaterRipple {
        PAD(0x2);
        PAD(0x2);
        EndianType<Fraction> contribution_factor;
        PAD(0x20);
        EndianType<Angle> animation_angle;
        EndianType<float> animation_velocity;
        Vector2D<EndianType> map_offset;
        EndianType<std::uint16_t> map_repeats;
        EndianType<Index> map_index;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentWaterRipple<NewEndian>() const {
            ShaderTransparentWaterRipple<NewEndian> copy = {};
            COPY_THIS(contribution_factor);
            COPY_THIS(animation_angle);
            COPY_THIS(animation_velocity);
            COPY_THIS(map_offset);
            COPY_THIS(map_repeats);
            COPY_THIS(map_index);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentWaterRipple<NativeEndian>) == 0x4C);

    ENDIAN_TEMPLATE(EndianType) struct ShaderTransparentWater : Shader<EndianType> {
        EndianType<ShaderTransparentWaterFlags> water_flags;
        PAD(0x2);
        PAD(0x20);
        TagDependency<EndianType> base_map;
        PAD(0x10);
        EndianType<Fraction> view_perpendicular_brightness;
        ColorRGB<EndianType> view_perpendicular_tint_color;
        EndianType<Fraction> view_parallel_brightness;
        ColorRGB<EndianType> view_parallel_tint_color;
        PAD(0x10);
        TagDependency<EndianType> reflection_map;
        PAD(0x10);
        EndianType<Angle> ripple_animation_angle;
        EndianType<float> ripple_animation_velocity;
        EndianType<float> ripple_scale;
        TagDependency<EndianType> ripple_maps;
        EndianType<std::uint16_t> ripple_mipmap_levels;
        PAD(0x2);
        EndianType<Fraction> ripple_mipmap_fade_factor;
        EndianType<float> ripple_mipmap_detail_bias;
        PAD(0x40);
        TagReflexive<EndianType, ShaderTransparentWaterRipple> ripples;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator ShaderTransparentWater<NewEndian>() const {
            ShaderTransparentWater<NewEndian> copy = {};
            COPY_THIS(water_flags);
            COPY_THIS(base_map);
            COPY_THIS(view_perpendicular_brightness);
            COPY_THIS(view_perpendicular_tint_color);
            COPY_THIS(view_parallel_brightness);
            COPY_THIS(view_parallel_tint_color);
            COPY_THIS(reflection_map);
            COPY_THIS(ripple_animation_angle);
            COPY_THIS(ripple_animation_velocity);
            COPY_THIS(ripple_scale);
            COPY_THIS(ripple_maps);
            COPY_THIS(ripple_mipmap_levels);
            COPY_THIS(ripple_mipmap_fade_factor);
            COPY_THIS(ripple_mipmap_detail_bias);
            COPY_THIS(ripples);
            COPY_THIS(shader_flags);
            COPY_THIS(detail_level);
            COPY_THIS(power);
            COPY_THIS(color_of_emitted_light);
            COPY_THIS(tint_color);
            COPY_THIS(physics_flags);
            COPY_THIS(material_type);
            COPY_THIS(shader_type);
            return copy;
        }
    };
    static_assert(sizeof(ShaderTransparentWater<NativeEndian>) == 0x140);

    ENDIAN_TEMPLATE(EndianType) struct SkyFunction {
        PAD(0x4);
        TagString function_name;
        ENDIAN_TEMPLATE(NewEndian) operator SkyFunction<NewEndian>() const {
            SkyFunction<NewEndian> copy = {};
            COPY_THIS(function_name);
            return copy;
        }
    };
    static_assert(sizeof(SkyFunction<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct SkyAnimation {
        EndianType<std::int16_t> animation_index;
        PAD(0x2);
        EndianType<float> period;
        PAD(0x1C);
        ENDIAN_TEMPLATE(NewEndian) operator SkyAnimation<NewEndian>() const {
            SkyAnimation<NewEndian> copy = {};
            COPY_THIS(animation_index);
            COPY_THIS(period);
            return copy;
        }
    };
    static_assert(sizeof(SkyAnimation<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct SkyLight {
        TagDependency<EndianType> lens_flare;
        TagString lens_flare_marker_name;
        PAD(0x1C);
        EndianType<SkyLightFlags> flags;
        ColorRGB<EndianType> color;
        EndianType<float> power;
        EndianType<float> test_distance;
        PAD(0x4);
        Euler2D<EndianType> direction;
        EndianType<float> diameter;
        ENDIAN_TEMPLATE(NewEndian) operator SkyLight<NewEndian>() const {
            SkyLight<NewEndian> copy = {};
            COPY_THIS(lens_flare);
            COPY_THIS(lens_flare_marker_name);
            COPY_THIS(flags);
            COPY_THIS(color);
            COPY_THIS(power);
            COPY_THIS(test_distance);
            COPY_THIS(direction);
            COPY_THIS(diameter);
            return copy;
        }
    };
    static_assert(sizeof(SkyLight<NativeEndian>) == 0x74);

    ENDIAN_TEMPLATE(EndianType) struct Sky {
        TagDependency<EndianType> model;
        TagDependency<EndianType> animation_graph;
        PAD(0x18);
        ColorRGB<EndianType> indoor_ambient_radiosity_color;
        EndianType<float> indoor_ambient_radiosity_power;
        ColorRGB<EndianType> outdoor_ambient_radiosity_color;
        EndianType<float> outdoor_ambient_radiosity_power;
        ColorRGB<EndianType> outdoor_fog_color;
        PAD(0x8);
        EndianType<Fraction> outdoor_fog_maximum_density;
        EndianType<float> outdoor_fog_start_distance;
        EndianType<float> outdoor_fog_opaque_distance;
        ColorRGB<EndianType> indoor_fog_color;
        PAD(0x8);
        EndianType<Fraction> indoor_fog_maximum_density;
        EndianType<float> indoor_fog_start_distance;
        EndianType<float> indoor_fog_opaque_distance;
        TagDependency<EndianType> indoor_fog_screen;
        PAD(0x4);
        TagReflexive<EndianType, SkyFunction> shader_functions;
        TagReflexive<EndianType, SkyAnimation> animations;
        TagReflexive<EndianType, SkyLight> lights;
        ENDIAN_TEMPLATE(NewEndian) operator Sky<NewEndian>() const {
            Sky<NewEndian> copy = {};
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(indoor_ambient_radiosity_color);
            COPY_THIS(indoor_ambient_radiosity_power);
            COPY_THIS(outdoor_ambient_radiosity_color);
            COPY_THIS(outdoor_ambient_radiosity_power);
            COPY_THIS(outdoor_fog_color);
            COPY_THIS(outdoor_fog_maximum_density);
            COPY_THIS(outdoor_fog_start_distance);
            COPY_THIS(outdoor_fog_opaque_distance);
            COPY_THIS(indoor_fog_color);
            COPY_THIS(indoor_fog_maximum_density);
            COPY_THIS(indoor_fog_start_distance);
            COPY_THIS(indoor_fog_opaque_distance);
            COPY_THIS(indoor_fog_screen);
            COPY_THIS(shader_functions);
            COPY_THIS(animations);
            COPY_THIS(lights);
            return copy;
        }
    };
    static_assert(sizeof(Sky<NativeEndian>) == 0xD0);

    ENDIAN_TEMPLATE(EndianType) struct SoundPermutation {
        TagString name;
        EndianType<Fraction> skip_fraction;
        EndianType<Fraction> gain;
        EndianType<SoundFormat> format;
        EndianType<Index> next_permutation_index;
        LittleEndian<std::uint32_t> samples_pointer;
        PAD(0x4);
        LittleEndian<TagID> tag_id_0;
        LittleEndian<std::uint32_t> buffer_size;
        LittleEndian<TagID> tag_id_1;
        TagDataOffset<EndianType> samples;
        TagDataOffset<EndianType> mouth_data;
        TagDataOffset<EndianType> subtitle_data;
        ENDIAN_TEMPLATE(NewEndian) operator SoundPermutation<NewEndian>() const {
            SoundPermutation<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(skip_fraction);
            COPY_THIS(gain);
            COPY_THIS(format);
            COPY_THIS(next_permutation_index);
            COPY_THIS(samples_pointer);
            COPY_THIS(tag_id_0);
            COPY_THIS(buffer_size);
            COPY_THIS(tag_id_1);
            COPY_THIS(samples);
            COPY_THIS(mouth_data);
            COPY_THIS(subtitle_data);
            return copy;
        }
    };
    static_assert(sizeof(SoundPermutation<NativeEndian>) == 0x7C);

    ENDIAN_TEMPLATE(EndianType) struct SoundPitchRange {
        TagString name;
        EndianType<float> natural_pitch;
        Bounds<EndianType<float>> bend_bounds;
        EndianType<std::uint16_t> actual_permutation_count;
        PAD(0x2);
        LittleEndian<float> playback_rate;
        LittleEndian<std::uint32_t> unknown_ffffffff_0;
        LittleEndian<std::uint32_t> unknown_ffffffff_1;
        TagReflexive<EndianType, SoundPermutation> permutations;
        ENDIAN_TEMPLATE(NewEndian) operator SoundPitchRange<NewEndian>() const {
            SoundPitchRange<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(natural_pitch);
            COPY_THIS(bend_bounds);
            COPY_THIS(actual_permutation_count);
            COPY_THIS(playback_rate);
            COPY_THIS(unknown_ffffffff_0);
            COPY_THIS(unknown_ffffffff_1);
            COPY_THIS(permutations);
            return copy;
        }
    };
    static_assert(sizeof(SoundPitchRange<NativeEndian>) == 0x48);

    ENDIAN_TEMPLATE(EndianType) struct Sound {
        EndianType<SoundFlags> flags;
        EndianType<SoundClass> sound_class;
        EndianType<SoundSampleRate> sample_rate;
        EndianType<float> minimum_distance;
        EndianType<float> maximum_distance;
        EndianType<Fraction> skip_fraction;
        Bounds<EndianType<float>> random_pitch_bounds;
        EndianType<Angle> inner_cone_angle;
        EndianType<Angle> outer_cone_angle;
        EndianType<Fraction> outer_cone_gain;
        EndianType<float> random_gain_modifier;
        EndianType<float> maximum_bend_per_second;
        PAD(0xC);
        EndianType<float> zero_skip_fraction_modifier;
        EndianType<float> zero_gain_modifier;
        EndianType<float> zero_pitch_modifier;
        PAD(0xC);
        EndianType<float> one_skip_fraction_modifier;
        EndianType<float> one_gain_modifier;
        EndianType<float> one_pitch_modifier;
        PAD(0xC);
        EndianType<SoundChannelCount> channel_count;
        EndianType<SoundFormat> format;
        TagDependency<EndianType> promotion_sound;
        EndianType<std::uint16_t> promotion_count;
        PAD(0x2);
        EndianType<std::uint32_t> longest_permutation_length;
        PAD(0x8);
        LittleEndian<std::uint32_t> unknown_ffffffff_0;
        LittleEndian<std::uint32_t> unknown_ffffffff_1;
        TagReflexive<EndianType, SoundPitchRange> pitch_ranges;
        ENDIAN_TEMPLATE(NewEndian) operator Sound<NewEndian>() const {
            Sound<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(sound_class);
            COPY_THIS(sample_rate);
            COPY_THIS(minimum_distance);
            COPY_THIS(maximum_distance);
            COPY_THIS(skip_fraction);
            COPY_THIS(random_pitch_bounds);
            COPY_THIS(inner_cone_angle);
            COPY_THIS(outer_cone_angle);
            COPY_THIS(outer_cone_gain);
            COPY_THIS(random_gain_modifier);
            COPY_THIS(maximum_bend_per_second);
            COPY_THIS(zero_skip_fraction_modifier);
            COPY_THIS(zero_gain_modifier);
            COPY_THIS(zero_pitch_modifier);
            COPY_THIS(one_skip_fraction_modifier);
            COPY_THIS(one_gain_modifier);
            COPY_THIS(one_pitch_modifier);
            COPY_THIS(channel_count);
            COPY_THIS(format);
            COPY_THIS(promotion_sound);
            COPY_THIS(promotion_count);
            COPY_THIS(longest_permutation_length);
            COPY_THIS(unknown_ffffffff_0);
            COPY_THIS(unknown_ffffffff_1);
            COPY_THIS(pitch_ranges);
            return copy;
        }
    };
    static_assert(sizeof(Sound<NativeEndian>) == 0xA4);

    ENDIAN_TEMPLATE(EndianType) struct SoundEnvironment {
        EndianType<std::int32_t> unknown;
        EndianType<std::int16_t> priority;
        PAD(0x2);
        EndianType<Fraction> room_intensity;
        EndianType<Fraction> room_intensity_hf;
        EndianType<float> room_rolloff;
        EndianType<float> decay_time;
        EndianType<float> decay_hf_ratio;
        EndianType<Fraction> reflections_intensity;
        EndianType<float> reflections_delay;
        EndianType<Fraction> reverb_intensity;
        EndianType<float> reverb_delay;
        EndianType<float> diffusion;
        EndianType<float> density;
        EndianType<float> hf_reference;
        PAD(0x10);
        ENDIAN_TEMPLATE(NewEndian) operator SoundEnvironment<NewEndian>() const {
            SoundEnvironment<NewEndian> copy = {};
            COPY_THIS(unknown);
            COPY_THIS(priority);
            COPY_THIS(room_intensity);
            COPY_THIS(room_intensity_hf);
            COPY_THIS(room_rolloff);
            COPY_THIS(decay_time);
            COPY_THIS(decay_hf_ratio);
            COPY_THIS(reflections_intensity);
            COPY_THIS(reflections_delay);
            COPY_THIS(reverb_intensity);
            COPY_THIS(reverb_delay);
            COPY_THIS(diffusion);
            COPY_THIS(density);
            COPY_THIS(hf_reference);
            return copy;
        }
    };
    static_assert(sizeof(SoundEnvironment<NativeEndian>) == 0x48);

    ENDIAN_TEMPLATE(EndianType) struct SoundLoopingTrack {
        EndianType<SoundLoopingTrackFlags> flags;
        EndianType<Fraction> gain;
        EndianType<float> fade_in_duration;
        EndianType<float> fade_out_duration;
        PAD(0x20);
        TagDependency<EndianType> start;
        TagDependency<EndianType> loop;
        TagDependency<EndianType> end;
        PAD(0x20);
        TagDependency<EndianType> alternate_loop;
        TagDependency<EndianType> alternate_end;
        ENDIAN_TEMPLATE(NewEndian) operator SoundLoopingTrack<NewEndian>() const {
            SoundLoopingTrack<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(gain);
            COPY_THIS(fade_in_duration);
            COPY_THIS(fade_out_duration);
            COPY_THIS(start);
            COPY_THIS(loop);
            COPY_THIS(end);
            COPY_THIS(alternate_loop);
            COPY_THIS(alternate_end);
            return copy;
        }
    };
    static_assert(sizeof(SoundLoopingTrack<NativeEndian>) == 0xA0);

    ENDIAN_TEMPLATE(EndianType) struct SoundLoopingDetail {
        TagDependency<EndianType> sound;
        Bounds<EndianType<float>> random_period_bounds;
        EndianType<Fraction> gain;
        EndianType<SoundLoopingDetailFlags> flags;
        PAD(0x30);
        Bounds<EndianType<Angle>> yaw_bounds;
        Bounds<EndianType<Angle>> pitch_bounds;
        Bounds<EndianType<float>> distance_bounds;
        ENDIAN_TEMPLATE(NewEndian) operator SoundLoopingDetail<NewEndian>() const {
            SoundLoopingDetail<NewEndian> copy = {};
            COPY_THIS(sound);
            COPY_THIS(random_period_bounds);
            COPY_THIS(gain);
            COPY_THIS(flags);
            COPY_THIS(yaw_bounds);
            COPY_THIS(pitch_bounds);
            COPY_THIS(distance_bounds);
            return copy;
        }
    };
    static_assert(sizeof(SoundLoopingDetail<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct SoundLooping {
        EndianType<SoundLoopingFlags> flags;
        EndianType<float> zero_detail_sound_period;
        LittleEndian<float> zero_detail_unknown_floats[2];
        EndianType<float> one_detail_sound_period;
        LittleEndian<float> one_detail_unknown_floats[2];
        LittleEndian<std::uint32_t> unknown_int;
        LittleEndian<float> maximum_distance;
        PAD(0x8);
        TagDependency<EndianType> continuous_damage_effect;
        TagReflexive<EndianType, SoundLoopingTrack> tracks;
        TagReflexive<EndianType, SoundLoopingDetail> detail_sounds;
        ENDIAN_TEMPLATE(NewEndian) operator SoundLooping<NewEndian>() const {
            SoundLooping<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(zero_detail_sound_period);
            COPY_THIS_ARRAY(zero_detail_unknown_floats);
            COPY_THIS(one_detail_sound_period);
            COPY_THIS_ARRAY(one_detail_unknown_floats);
            COPY_THIS(unknown_int);
            COPY_THIS(maximum_distance);
            COPY_THIS(continuous_damage_effect);
            COPY_THIS(tracks);
            COPY_THIS(detail_sounds);
            return copy;
        }
    };
    static_assert(sizeof(SoundLooping<NativeEndian>) == 0x54);

    ENDIAN_TEMPLATE(EndianType) struct SoundScenery : BasicObject<EndianType> {
        ENDIAN_TEMPLATE(NewEndian) operator SoundScenery<NewEndian>() const {
            SoundScenery<NewEndian> copy = {};
            COPY_THIS(more_flags);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(SoundScenery<NativeEndian>) == 0x1FC);

    ENDIAN_TEMPLATE(EndianType) struct StringListString {
        TagDataOffset<EndianType> string;
        ENDIAN_TEMPLATE(NewEndian) operator StringListString<NewEndian>() const {
            StringListString<NewEndian> copy;
            COPY_THIS(string);
            return copy;
        }
    };
    static_assert(sizeof(StringListString<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct StringList {
        TagReflexive<EndianType, StringListString> strings;
        ENDIAN_TEMPLATE(NewEndian) operator StringList<NewEndian>() const {
            StringList<NewEndian> copy;
            COPY_THIS(strings);
            return copy;
        }
    };
    static_assert(sizeof(StringList<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct TagCollectionTag {
        TagDependency<EndianType> reference;
        ENDIAN_TEMPLATE(NewEndian) operator TagCollectionTag<NewEndian>() const {
            TagCollectionTag<NewEndian> copy;
            COPY_THIS(reference);
            return copy;
        }
    };
    static_assert(sizeof(TagCollectionTag<NativeEndian>) == 0x10);

    ENDIAN_TEMPLATE(EndianType) struct TagCollection {
        TagReflexive<EndianType, TagCollectionTag> tags;
        ENDIAN_TEMPLATE(NewEndian) operator TagCollection<NewEndian>() const {
            TagCollection<NewEndian> copy;
            COPY_THIS(tags);
            return copy;
        }
    };
    static_assert(sizeof(TagCollection<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct GameDataInputReference {
        EndianType<UIGameDataInputReferenceFunction> function;
        PAD(0x2);
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator GameDataInputReference<NewEndian>() const {
            GameDataInputReference<NewEndian> copy = {};
            COPY_THIS(function);
            return copy;
        }
    };
    static_assert(sizeof(GameDataInputReference<NativeEndian>) == 0x24);

    ENDIAN_TEMPLATE(EndianType) struct EventHandlerReference {
        EndianType<EventHandlerReferencesFlags> flags;
        EndianType<UIEventType> event_type;
        EndianType<UIEventHandlerReferenceFunction> function;
        TagDependency<EndianType> widget_tag;
        TagDependency<EndianType> sound_effect;
        TagString script;
        ENDIAN_TEMPLATE(NewEndian) operator EventHandlerReference<NewEndian>() const {
            EventHandlerReference<NewEndian> copy;
            COPY_THIS(flags);
            COPY_THIS(event_type);
            COPY_THIS(function);
            COPY_THIS(widget_tag);
            COPY_THIS(sound_effect);
            COPY_THIS(script);
            return copy;
        }
    };
    static_assert(sizeof(EventHandlerReference<NativeEndian>) == 0x48);

    ENDIAN_TEMPLATE(EndianType) struct SearchAndReplaceReference {
        TagString search_string;
        EndianType<UIReplaceFunction> replace_function;
        ENDIAN_TEMPLATE(NewEndian) operator SearchAndReplaceReference<NewEndian>() const {
            SearchAndReplaceReference<NewEndian> copy;
            COPY_THIS(search_string);
            COPY_THIS(replace_function);
            return copy;
        }
    };
    static_assert(sizeof(SearchAndReplaceReference<NativeEndian>) == 0x22);

    ENDIAN_TEMPLATE(EndianType) struct ConditionalWidgetReference {
        TagDependency<EndianType> widget_tag;
        TagString name;
        EndianType<ConditionalWidgetReferenceFlags> flags;
        EndianType<Index> custom_controller_index;
        PAD(0x1A);
        ENDIAN_TEMPLATE(NewEndian) operator ConditionalWidgetReference<NewEndian>() const {
            ConditionalWidgetReference<NewEndian> copy = {};
            COPY_THIS(widget_tag);
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(custom_controller_index);
            return copy;
        }
    };
    static_assert(sizeof(ConditionalWidgetReference<NativeEndian>) == 0x50);

    ENDIAN_TEMPLATE(EndianType) struct ChildWidgetReference {
        TagDependency<EndianType> widget_tag;
        TagString name;
        EndianType<ChildWidgetReferenceFlags> flags;
        EndianType<Index> custom_controller_index;
        EndianType<std::int16_t> vertical_offset;
        EndianType<std::int16_t> horizontal_offset;
        PAD(0x16);
        ENDIAN_TEMPLATE(NewEndian) operator ChildWidgetReference<NewEndian>() const {
            ChildWidgetReference<NewEndian> copy = {};
            COPY_THIS(widget_tag);
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(custom_controller_index);
            COPY_THIS(vertical_offset);
            COPY_THIS(horizontal_offset);
            return copy;
        }
    };
    static_assert(sizeof(ChildWidgetReference<NativeEndian>) == 0x50);

    ENDIAN_TEMPLATE(EndianType) struct UIWidgetDefinition {
        EndianType<UIWidgetType> widget_type;
        EndianType<UIControllerIndex> controller_index;
        TagString name;
        Rectangle2D<EndianType> bounds;
        EndianType<UIWidgetDefinitionFlags> flags;
        EndianType<std::int32_t> milliseconds_to_auto_close;
        EndianType<std::int32_t> milliseconds_auto_close_fade_time;
        TagDependency<EndianType> background_bitmap;
        TagReflexive<EndianType, GameDataInputReference> game_data_inputs;
        TagReflexive<EndianType, EventHandlerReference> event_handlers;
        TagReflexive<EndianType, SearchAndReplaceReference> search_and_replace_functions;
        PAD(0x80);
        TagDependency<EndianType> text_label_unicode_strings_list;
        TagDependency<EndianType> text_font;
        ColorARGB<EndianType> text_color;
        EndianType<UIJustification> justification;
        EndianType<UIWidgetDefinitionFlags1> flags_1;
        PAD(0xC);
        EndianType<Index> string_list_index;
        EndianType<std::int16_t> horiz_offset;
        EndianType<std::int16_t> vert_offset;
        PAD(0x1A);
        PAD(0x2);
        EndianType<UIWidgetDefinitionFlags2> flags_2;
        TagDependency<EndianType> list_header_bitmap;
        TagDependency<EndianType> list_footer_bitmap;
        Rectangle2D<EndianType> header_bounds;
        Rectangle2D<EndianType> footer_bounds;
        PAD(0x20);
        TagDependency<EndianType> extended_description_widget;
        PAD(0x20);
        PAD(0x100);
        TagReflexive<EndianType, ConditionalWidgetReference> conditional_widgets;
        PAD(0x80);
        PAD(0x80);
        TagReflexive<EndianType, ChildWidgetReference> child_widgets;
        ENDIAN_TEMPLATE(NewEndian) operator UIWidgetDefinition<NewEndian>() const {
            UIWidgetDefinition<NewEndian> copy = {};
            COPY_THIS(widget_type);
            COPY_THIS(controller_index);
            COPY_THIS(name);
            COPY_THIS(bounds);
            COPY_THIS(flags);
            COPY_THIS(milliseconds_to_auto_close);
            COPY_THIS(milliseconds_auto_close_fade_time);
            COPY_THIS(background_bitmap);
            COPY_THIS(game_data_inputs);
            COPY_THIS(event_handlers);
            COPY_THIS(search_and_replace_functions);
            COPY_THIS(text_label_unicode_strings_list);
            COPY_THIS(text_font);
            COPY_THIS(text_color);
            COPY_THIS(justification);
            COPY_THIS(flags_1);
            COPY_THIS(string_list_index);
            COPY_THIS(horiz_offset);
            COPY_THIS(vert_offset);
            COPY_THIS(flags_2);
            COPY_THIS(list_header_bitmap);
            COPY_THIS(list_footer_bitmap);
            COPY_THIS(header_bounds);
            COPY_THIS(footer_bounds);
            COPY_THIS(extended_description_widget);
            COPY_THIS(conditional_widgets);
            COPY_THIS(child_widgets);
            return copy;
        }
    };
    static_assert(sizeof(UIWidgetDefinition<NativeEndian>) == 0x3EC);

    ENDIAN_TEMPLATE(EndianType) struct UnicodeStringListString {
        TagDataOffset<EndianType> string;
        ENDIAN_TEMPLATE(NewEndian) operator UnicodeStringListString<NewEndian>() const {
            UnicodeStringListString<NewEndian> copy;
            COPY_THIS(string);
            return copy;
        }
    };
    static_assert(sizeof(UnicodeStringListString<NativeEndian>) == 0x14);

    ENDIAN_TEMPLATE(EndianType) struct UnicodeStringList {
        TagReflexive<EndianType, UnicodeStringListString> strings;
        ENDIAN_TEMPLATE(NewEndian) operator UnicodeStringList<NewEndian>() const {
            UnicodeStringList<NewEndian> copy;
            COPY_THIS(strings);
            return copy;
        }
    };
    static_assert(sizeof(UnicodeStringList<NativeEndian>) == 0xC);

    ENDIAN_TEMPLATE(EndianType) struct UnitHUDInterfaceAuxiliaryOverlay {
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> interface_bitmap;
        EndianType<ColorARGBInt> default_color;
        EndianType<ColorARGBInt> flashing_color;
        EndianType<float> flash_period;
        EndianType<float> flash_delay;
        EndianType<std::int16_t> number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> flash_flags;
        EndianType<float> flash_length;
        EndianType<ColorARGBInt> disabled_color;
        PAD(0x4);
        EndianType<Index> sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> multitexture_overlays;
        PAD(0x4);
        EndianType<UnitHUDInterfacePanelType> type;
        EndianType<UnitHUDInterfaceAuxiliaryOverlayFlags> flags;
        PAD(0x18);
        ENDIAN_TEMPLATE(NewEndian) operator UnitHUDInterfaceAuxiliaryOverlay<NewEndian>() const {
            UnitHUDInterfaceAuxiliaryOverlay<NewEndian> copy = {};
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(interface_bitmap);
            COPY_THIS(default_color);
            COPY_THIS(flashing_color);
            COPY_THIS(flash_period);
            COPY_THIS(flash_delay);
            COPY_THIS(number_of_flashes);
            COPY_THIS(flash_flags);
            COPY_THIS(flash_length);
            COPY_THIS(disabled_color);
            COPY_THIS(sequence_index);
            COPY_THIS(multitexture_overlays);
            COPY_THIS(type);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(UnitHUDInterfaceAuxiliaryOverlay<NativeEndian>) == 0x84);

    ENDIAN_TEMPLATE(EndianType) struct UnitHUDInterfaceHUDSound {
        TagDependency<EndianType> sound;
        EndianType<UnitHUDInterfaceHUDSoundLatchedTo> latched_to;
        EndianType<float> scale;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator UnitHUDInterfaceHUDSound<NewEndian>() const {
            UnitHUDInterfaceHUDSound<NewEndian> copy = {};
            COPY_THIS(sound);
            COPY_THIS(latched_to);
            COPY_THIS(scale);
            return copy;
        }
    };
    static_assert(sizeof(UnitHUDInterfaceHUDSound<NativeEndian>) == 0x38);

    ENDIAN_TEMPLATE(EndianType) struct UnitHUDInterfaceAuxiliaryPanel {
        EndianType<UnitHUDInterfacePanelType> type;
        PAD(0x2);
        PAD(0x10);
        Point2DInt<EndianType> background_anchor_offset;
        EndianType<float> background_width_scale;
        EndianType<float> background_height_scale;
        EndianType<HUDInterfaceScalingFlags> background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> background_interface_bitmap;
        EndianType<ColorARGBInt> background_default_color;
        EndianType<ColorARGBInt> background_flashing_color;
        EndianType<float> background_flash_period;
        EndianType<float> background_flash_delay;
        EndianType<std::int16_t> background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> background_flash_flags;
        EndianType<float> background_flash_length;
        EndianType<ColorARGBInt> background_disabled_color;
        PAD(0x4);
        EndianType<Index> background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> meter_anchor_offset;
        EndianType<float> meter_width_scale;
        EndianType<float> meter_height_scale;
        EndianType<HUDInterfaceScalingFlags> meter_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> meter_meter_bitmap;
        EndianType<ColorARGBInt> meter_color_at_meter_minimum;
        EndianType<ColorARGBInt> meter_color_at_meter_maximum;
        EndianType<ColorARGBInt> meter_flash_color;
        EndianType<ColorARGBInt> meter_empty_color;
        EndianType<HUDInterfaceMeterFlags> meter_flags;
        std::int8_t meter_minimum_meter_value;
        EndianType<Index> meter_sequence_index;
        std::int8_t meter_alpha_multiplier;
        std::int8_t meter_alpha_bias;
        EndianType<std::int16_t> meter_value_scale;
        EndianType<float> meter_opacity;
        EndianType<float> meter_translucency;
        EndianType<ColorARGBInt> meter_disabled_color;
        EndianType<float> meter_min_alpha;
        PAD(0xC);
        EndianType<float> meter_minimum_fraction_cutoff;
        EndianType<UnitHUDInterfaceAuxiliaryPanelMeterMoreFlags> meter_more_flags;
        PAD(0x18);
        PAD(0x40);
        ENDIAN_TEMPLATE(NewEndian) operator UnitHUDInterfaceAuxiliaryPanel<NewEndian>() const {
            UnitHUDInterfaceAuxiliaryPanel<NewEndian> copy = {};
            COPY_THIS(type);
            COPY_THIS(background_anchor_offset);
            COPY_THIS(background_width_scale);
            COPY_THIS(background_height_scale);
            COPY_THIS(background_scaling_flags);
            COPY_THIS(background_interface_bitmap);
            COPY_THIS(background_default_color);
            COPY_THIS(background_flashing_color);
            COPY_THIS(background_flash_period);
            COPY_THIS(background_flash_delay);
            COPY_THIS(background_number_of_flashes);
            COPY_THIS(background_flash_flags);
            COPY_THIS(background_flash_length);
            COPY_THIS(background_disabled_color);
            COPY_THIS(background_sequence_index);
            COPY_THIS(background_multitexture_overlays);
            COPY_THIS(meter_anchor_offset);
            COPY_THIS(meter_width_scale);
            COPY_THIS(meter_height_scale);
            COPY_THIS(meter_scaling_flags);
            COPY_THIS(meter_meter_bitmap);
            COPY_THIS(meter_color_at_meter_minimum);
            COPY_THIS(meter_color_at_meter_maximum);
            COPY_THIS(meter_flash_color);
            COPY_THIS(meter_empty_color);
            COPY_THIS(meter_flags);
            COPY_THIS(meter_minimum_meter_value);
            COPY_THIS(meter_sequence_index);
            COPY_THIS(meter_alpha_multiplier);
            COPY_THIS(meter_alpha_bias);
            COPY_THIS(meter_value_scale);
            COPY_THIS(meter_opacity);
            COPY_THIS(meter_translucency);
            COPY_THIS(meter_disabled_color);
            COPY_THIS(meter_min_alpha);
            COPY_THIS(meter_minimum_fraction_cutoff);
            COPY_THIS(meter_more_flags);
            return copy;
        }
    };
    static_assert(sizeof(UnitHUDInterfaceAuxiliaryPanel<NativeEndian>) == 0x144);

    ENDIAN_TEMPLATE(EndianType) struct UnitHUDInterface {
        EndianType<HUDInterfaceAnchor> anchor;
        PAD(0x2);
        PAD(0x20);
        Point2DInt<EndianType> hud_background_anchor_offset;
        EndianType<float> hud_background_width_scale;
        EndianType<float> hud_background_height_scale;
        EndianType<HUDInterfaceScalingFlags> hud_background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> hud_background_interface_bitmap;
        EndianType<ColorARGBInt> hud_background_default_color;
        EndianType<ColorARGBInt> hud_background_flashing_color;
        EndianType<float> hud_background_flash_period;
        EndianType<float> hud_background_flash_delay;
        EndianType<std::int16_t> hud_background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> hud_background_flash_flags;
        EndianType<float> hud_background_flash_length;
        EndianType<ColorARGBInt> hud_background_disabled_color;
        PAD(0x4);
        EndianType<Index> hud_background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> hud_background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> shield_panel_background_anchor_offset;
        EndianType<float> shield_panel_background_width_scale;
        EndianType<float> shield_panel_background_height_scale;
        EndianType<HUDInterfaceScalingFlags> shield_panel_background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> shield_panel_background_interface_bitmap;
        EndianType<ColorARGBInt> shield_panel_background_default_color;
        EndianType<ColorARGBInt> shield_panel_background_flashing_color;
        EndianType<float> shield_panel_background_flash_period;
        EndianType<float> shield_panel_background_flash_delay;
        EndianType<std::int16_t> shield_panel_background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> shield_panel_background_flash_flags;
        EndianType<float> shield_panel_background_flash_length;
        EndianType<ColorARGBInt> shield_panel_background_disabled_color;
        PAD(0x4);
        EndianType<Index> shield_panel_background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> shield_panel_background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> shield_panel_meter_anchor_offset;
        EndianType<float> shield_panel_meter_width_scale;
        EndianType<float> shield_panel_meter_height_scale;
        EndianType<HUDInterfaceScalingFlags> shield_panel_meter_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> shield_panel_meter_meter_bitmap;
        EndianType<ColorARGBInt> shield_panel_meter_color_at_meter_minimum;
        EndianType<ColorARGBInt> shield_panel_meter_color_at_meter_maximum;
        EndianType<ColorARGBInt> shield_panel_meter_flash_color;
        EndianType<ColorARGBInt> shield_panel_meter_empty_color;
        EndianType<HUDInterfaceMeterFlags> shield_panel_meter_flags;
        std::int8_t shield_panel_meter_minimum_meter_value;
        EndianType<Index> shield_panel_meter_sequence_index;
        std::int8_t shield_panel_meter_alpha_multiplier;
        std::int8_t shield_panel_meter_alpha_bias;
        EndianType<std::int16_t> shield_panel_meter_value_scale;
        EndianType<float> shield_panel_meter_opacity;
        EndianType<float> shield_panel_meter_translucency;
        EndianType<ColorARGBInt> shield_panel_meter_disabled_color;
        EndianType<float> shield_panel_meter_min_alpha;
        PAD(0xC);
        EndianType<ColorARGBInt> shield_panel_meter_overcharge_minimum_color;
        EndianType<ColorARGBInt> shield_panel_meter_overcharge_maximum_color;
        EndianType<ColorARGBInt> shield_panel_meter_overcharge_flash_color;
        EndianType<ColorARGBInt> shield_panel_meter_overcharge_empty_color;
        PAD(0x10);
        Point2DInt<EndianType> health_panel_background_anchor_offset;
        EndianType<float> health_panel_background_width_scale;
        EndianType<float> health_panel_background_height_scale;
        EndianType<HUDInterfaceScalingFlags> health_panel_background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> health_panel_background_interface_bitmap;
        EndianType<ColorARGBInt> health_panel_background_default_color;
        EndianType<ColorARGBInt> health_panel_background_flashing_color;
        EndianType<float> health_panel_background_flash_period;
        EndianType<float> health_panel_background_flash_delay;
        EndianType<std::int16_t> health_panel_background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> health_panel_background_flash_flags;
        EndianType<float> health_panel_background_flash_length;
        EndianType<ColorARGBInt> health_panel_background_disabled_color;
        PAD(0x4);
        EndianType<Index> health_panel_background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> health_panel_background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> health_panel_meter_anchor_offset;
        EndianType<float> health_panel_meter_width_scale;
        EndianType<float> health_panel_meter_height_scale;
        EndianType<HUDInterfaceScalingFlags> health_panel_meter_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> health_panel_meter_meter_bitmap;
        EndianType<ColorARGBInt> health_panel_meter_color_at_meter_minimum;
        EndianType<ColorARGBInt> health_panel_meter_color_at_meter_maximum;
        EndianType<ColorARGBInt> health_panel_meter_flash_color;
        EndianType<ColorARGBInt> health_panel_meter_empty_color;
        EndianType<HUDInterfaceMeterFlags> health_panel_meter_flags;
        std::int8_t health_panel_meter_minimum_meter_value;
        EndianType<Index> health_panel_meter_sequence_index;
        std::int8_t health_panel_meter_alpha_multiplier;
        std::int8_t health_panel_meter_alpha_bias;
        EndianType<std::int16_t> health_panel_meter_value_scale;
        EndianType<float> health_panel_meter_opacity;
        EndianType<float> health_panel_meter_translucency;
        EndianType<ColorARGBInt> health_panel_meter_disabled_color;
        EndianType<float> health_panel_meter_min_alpha;
        PAD(0xC);
        EndianType<ColorARGBInt> health_panel_meter_medium_health_left_color;
        EndianType<float> health_panel_meter_max_color_health_fraction_cutoff;
        EndianType<float> health_panel_meter_min_color_health_fraction_cutoff;
        PAD(0x14);
        Point2DInt<EndianType> motion_sensor_background_anchor_offset;
        EndianType<float> motion_sensor_background_width_scale;
        EndianType<float> motion_sensor_background_height_scale;
        EndianType<HUDInterfaceScalingFlags> motion_sensor_background_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> motion_sensor_background_interface_bitmap;
        EndianType<ColorARGBInt> motion_sensor_background_default_color;
        EndianType<ColorARGBInt> motion_sensor_background_flashing_color;
        EndianType<float> motion_sensor_background_flash_period;
        EndianType<float> motion_sensor_background_flash_delay;
        EndianType<std::int16_t> motion_sensor_background_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> motion_sensor_background_flash_flags;
        EndianType<float> motion_sensor_background_flash_length;
        EndianType<ColorARGBInt> motion_sensor_background_disabled_color;
        PAD(0x4);
        EndianType<Index> motion_sensor_background_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> motion_sensor_background_multitexture_overlays;
        PAD(0x4);
        Point2DInt<EndianType> motion_sensor_foreground_anchor_offset;
        EndianType<float> motion_sensor_foreground_width_scale;
        EndianType<float> motion_sensor_foreground_height_scale;
        EndianType<HUDInterfaceScalingFlags> motion_sensor_foreground_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> motion_sensor_foreground_interface_bitmap;
        EndianType<ColorARGBInt> motion_sensor_foreground_default_color;
        EndianType<ColorARGBInt> motion_sensor_foreground_flashing_color;
        EndianType<float> motion_sensor_foreground_flash_period;
        EndianType<float> motion_sensor_foreground_flash_delay;
        EndianType<std::int16_t> motion_sensor_foreground_number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> motion_sensor_foreground_flash_flags;
        EndianType<float> motion_sensor_foreground_flash_length;
        EndianType<ColorARGBInt> motion_sensor_foreground_disabled_color;
        PAD(0x4);
        EndianType<Index> motion_sensor_foreground_sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> motion_sensor_foreground_multitexture_overlays;
        PAD(0x4);
        PAD(0x20);
        Point2DInt<EndianType> motion_sensor_center_anchor_offset;
        EndianType<float> motion_sensor_center_width_scale;
        EndianType<float> motion_sensor_center_height_scale;
        EndianType<HUDInterfaceScalingFlags> motion_sensor_center_scaling_flags;
        PAD(0x2);
        PAD(0x14);
        EndianType<HUDInterfaceAnchor> auxiliary_overlay_anchor;
        PAD(0x2);
        PAD(0x20);
        TagReflexive<EndianType, UnitHUDInterfaceAuxiliaryOverlay> overlays;
        PAD(0x10);
        TagReflexive<EndianType, UnitHUDInterfaceHUDSound> sounds;
        TagReflexive<EndianType, UnitHUDInterfaceAuxiliaryPanel> meters;
        PAD(0x164);
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator UnitHUDInterface<NewEndian>() const {
            UnitHUDInterface<NewEndian> copy = {};
            COPY_THIS(anchor);
            COPY_THIS(hud_background_anchor_offset);
            COPY_THIS(hud_background_width_scale);
            COPY_THIS(hud_background_height_scale);
            COPY_THIS(hud_background_scaling_flags);
            COPY_THIS(hud_background_interface_bitmap);
            COPY_THIS(hud_background_default_color);
            COPY_THIS(hud_background_flashing_color);
            COPY_THIS(hud_background_flash_period);
            COPY_THIS(hud_background_flash_delay);
            COPY_THIS(hud_background_number_of_flashes);
            COPY_THIS(hud_background_flash_flags);
            COPY_THIS(hud_background_flash_length);
            COPY_THIS(hud_background_disabled_color);
            COPY_THIS(hud_background_sequence_index);
            COPY_THIS(hud_background_multitexture_overlays);
            COPY_THIS(shield_panel_background_anchor_offset);
            COPY_THIS(shield_panel_background_width_scale);
            COPY_THIS(shield_panel_background_height_scale);
            COPY_THIS(shield_panel_background_scaling_flags);
            COPY_THIS(shield_panel_background_interface_bitmap);
            COPY_THIS(shield_panel_background_default_color);
            COPY_THIS(shield_panel_background_flashing_color);
            COPY_THIS(shield_panel_background_flash_period);
            COPY_THIS(shield_panel_background_flash_delay);
            COPY_THIS(shield_panel_background_number_of_flashes);
            COPY_THIS(shield_panel_background_flash_flags);
            COPY_THIS(shield_panel_background_flash_length);
            COPY_THIS(shield_panel_background_disabled_color);
            COPY_THIS(shield_panel_background_sequence_index);
            COPY_THIS(shield_panel_background_multitexture_overlays);
            COPY_THIS(shield_panel_meter_anchor_offset);
            COPY_THIS(shield_panel_meter_width_scale);
            COPY_THIS(shield_panel_meter_height_scale);
            COPY_THIS(shield_panel_meter_scaling_flags);
            COPY_THIS(shield_panel_meter_meter_bitmap);
            COPY_THIS(shield_panel_meter_color_at_meter_minimum);
            COPY_THIS(shield_panel_meter_color_at_meter_maximum);
            COPY_THIS(shield_panel_meter_flash_color);
            COPY_THIS(shield_panel_meter_empty_color);
            COPY_THIS(shield_panel_meter_flags);
            COPY_THIS(shield_panel_meter_minimum_meter_value);
            COPY_THIS(shield_panel_meter_sequence_index);
            COPY_THIS(shield_panel_meter_alpha_multiplier);
            COPY_THIS(shield_panel_meter_alpha_bias);
            COPY_THIS(shield_panel_meter_value_scale);
            COPY_THIS(shield_panel_meter_opacity);
            COPY_THIS(shield_panel_meter_translucency);
            COPY_THIS(shield_panel_meter_disabled_color);
            COPY_THIS(shield_panel_meter_min_alpha);
            COPY_THIS(shield_panel_meter_overcharge_minimum_color);
            COPY_THIS(shield_panel_meter_overcharge_maximum_color);
            COPY_THIS(shield_panel_meter_overcharge_flash_color);
            COPY_THIS(shield_panel_meter_overcharge_empty_color);
            COPY_THIS(health_panel_background_anchor_offset);
            COPY_THIS(health_panel_background_width_scale);
            COPY_THIS(health_panel_background_height_scale);
            COPY_THIS(health_panel_background_scaling_flags);
            COPY_THIS(health_panel_background_interface_bitmap);
            COPY_THIS(health_panel_background_default_color);
            COPY_THIS(health_panel_background_flashing_color);
            COPY_THIS(health_panel_background_flash_period);
            COPY_THIS(health_panel_background_flash_delay);
            COPY_THIS(health_panel_background_number_of_flashes);
            COPY_THIS(health_panel_background_flash_flags);
            COPY_THIS(health_panel_background_flash_length);
            COPY_THIS(health_panel_background_disabled_color);
            COPY_THIS(health_panel_background_sequence_index);
            COPY_THIS(health_panel_background_multitexture_overlays);
            COPY_THIS(health_panel_meter_anchor_offset);
            COPY_THIS(health_panel_meter_width_scale);
            COPY_THIS(health_panel_meter_height_scale);
            COPY_THIS(health_panel_meter_scaling_flags);
            COPY_THIS(health_panel_meter_meter_bitmap);
            COPY_THIS(health_panel_meter_color_at_meter_minimum);
            COPY_THIS(health_panel_meter_color_at_meter_maximum);
            COPY_THIS(health_panel_meter_flash_color);
            COPY_THIS(health_panel_meter_empty_color);
            COPY_THIS(health_panel_meter_flags);
            COPY_THIS(health_panel_meter_minimum_meter_value);
            COPY_THIS(health_panel_meter_sequence_index);
            COPY_THIS(health_panel_meter_alpha_multiplier);
            COPY_THIS(health_panel_meter_alpha_bias);
            COPY_THIS(health_panel_meter_value_scale);
            COPY_THIS(health_panel_meter_opacity);
            COPY_THIS(health_panel_meter_translucency);
            COPY_THIS(health_panel_meter_disabled_color);
            COPY_THIS(health_panel_meter_min_alpha);
            COPY_THIS(health_panel_meter_medium_health_left_color);
            COPY_THIS(health_panel_meter_max_color_health_fraction_cutoff);
            COPY_THIS(health_panel_meter_min_color_health_fraction_cutoff);
            COPY_THIS(motion_sensor_background_anchor_offset);
            COPY_THIS(motion_sensor_background_width_scale);
            COPY_THIS(motion_sensor_background_height_scale);
            COPY_THIS(motion_sensor_background_scaling_flags);
            COPY_THIS(motion_sensor_background_interface_bitmap);
            COPY_THIS(motion_sensor_background_default_color);
            COPY_THIS(motion_sensor_background_flashing_color);
            COPY_THIS(motion_sensor_background_flash_period);
            COPY_THIS(motion_sensor_background_flash_delay);
            COPY_THIS(motion_sensor_background_number_of_flashes);
            COPY_THIS(motion_sensor_background_flash_flags);
            COPY_THIS(motion_sensor_background_flash_length);
            COPY_THIS(motion_sensor_background_disabled_color);
            COPY_THIS(motion_sensor_background_sequence_index);
            COPY_THIS(motion_sensor_background_multitexture_overlays);
            COPY_THIS(motion_sensor_foreground_anchor_offset);
            COPY_THIS(motion_sensor_foreground_width_scale);
            COPY_THIS(motion_sensor_foreground_height_scale);
            COPY_THIS(motion_sensor_foreground_scaling_flags);
            COPY_THIS(motion_sensor_foreground_interface_bitmap);
            COPY_THIS(motion_sensor_foreground_default_color);
            COPY_THIS(motion_sensor_foreground_flashing_color);
            COPY_THIS(motion_sensor_foreground_flash_period);
            COPY_THIS(motion_sensor_foreground_flash_delay);
            COPY_THIS(motion_sensor_foreground_number_of_flashes);
            COPY_THIS(motion_sensor_foreground_flash_flags);
            COPY_THIS(motion_sensor_foreground_flash_length);
            COPY_THIS(motion_sensor_foreground_disabled_color);
            COPY_THIS(motion_sensor_foreground_sequence_index);
            COPY_THIS(motion_sensor_foreground_multitexture_overlays);
            COPY_THIS(motion_sensor_center_anchor_offset);
            COPY_THIS(motion_sensor_center_width_scale);
            COPY_THIS(motion_sensor_center_height_scale);
            COPY_THIS(motion_sensor_center_scaling_flags);
            COPY_THIS(auxiliary_overlay_anchor);
            COPY_THIS(overlays);
            COPY_THIS(sounds);
            COPY_THIS(meters);
            return copy;
        }
    };
    static_assert(sizeof(UnitHUDInterface<NativeEndian>) == 0x56C);

    ENDIAN_TEMPLATE(EndianType) struct Vehicle : Unit<EndianType> {
        EndianType<VehicleFlags> vehicle_flags;
        EndianType<VehicleType> vehicle_type;
        PAD(0x2);
        EndianType<float> maximum_forward_speed;
        EndianType<float> maximum_reverse_speed;
        EndianType<float> speed_acceleration;
        EndianType<float> speed_deceleration;
        EndianType<float> maximum_left_turn;
        EndianType<float> maximum_right_turn;
        EndianType<float> wheel_circumference;
        EndianType<float> turn_rate;
        EndianType<float> blur_speed;
        EndianType<VehicleFunctionIn> vehicle_a_in;
        EndianType<VehicleFunctionIn> vehicle_b_in;
        EndianType<VehicleFunctionIn> vehicle_c_in;
        EndianType<VehicleFunctionIn> vehicle_d_in;
        PAD(0xC);
        EndianType<float> maximum_left_slide;
        EndianType<float> maximum_right_slide;
        EndianType<float> slide_acceleration;
        EndianType<float> slide_deceleration;
        EndianType<float> minimum_flipping_angular_velocity;
        EndianType<float> maximum_flipping_angular_velocity;
        PAD(0x18);
        EndianType<float> fixed_gun_yaw;
        EndianType<float> fixed_gun_pitch;
        PAD(0x18);
        EndianType<float> ai_sideslip_distance;
        EndianType<float> ai_destination_radius;
        EndianType<float> ai_avoidance_distance;
        EndianType<float> ai_pathfinding_radius;
        EndianType<float> ai_charge_repeat_timeout;
        EndianType<float> ai_strafing_abort_range;
        Bounds<EndianType<float>> ai_oversteering_bounds;
        EndianType<Angle> ai_steering_maximum;
        EndianType<float> ai_throttle_maximum;
        EndianType<float> ai_move_position_time;
        PAD(0x4);
        TagDependency<EndianType> suspension_sound;
        TagDependency<EndianType> crash_sound;
        TagDependency<EndianType> material_effects;
        TagDependency<EndianType> effect;
        ENDIAN_TEMPLATE(NewEndian) operator Vehicle<NewEndian>() const {
            Vehicle<NewEndian> copy = {};
            COPY_THIS(vehicle_flags);
            COPY_THIS(vehicle_type);
            COPY_THIS(maximum_forward_speed);
            COPY_THIS(maximum_reverse_speed);
            COPY_THIS(speed_acceleration);
            COPY_THIS(speed_deceleration);
            COPY_THIS(maximum_left_turn);
            COPY_THIS(maximum_right_turn);
            COPY_THIS(wheel_circumference);
            COPY_THIS(turn_rate);
            COPY_THIS(blur_speed);
            COPY_THIS(vehicle_a_in);
            COPY_THIS(vehicle_b_in);
            COPY_THIS(vehicle_c_in);
            COPY_THIS(vehicle_d_in);
            COPY_THIS(maximum_left_slide);
            COPY_THIS(maximum_right_slide);
            COPY_THIS(slide_acceleration);
            COPY_THIS(slide_deceleration);
            COPY_THIS(minimum_flipping_angular_velocity);
            COPY_THIS(maximum_flipping_angular_velocity);
            COPY_THIS(fixed_gun_yaw);
            COPY_THIS(fixed_gun_pitch);
            COPY_THIS(ai_sideslip_distance);
            COPY_THIS(ai_destination_radius);
            COPY_THIS(ai_avoidance_distance);
            COPY_THIS(ai_pathfinding_radius);
            COPY_THIS(ai_charge_repeat_timeout);
            COPY_THIS(ai_strafing_abort_range);
            COPY_THIS(ai_oversteering_bounds);
            COPY_THIS(ai_steering_maximum);
            COPY_THIS(ai_throttle_maximum);
            COPY_THIS(ai_move_position_time);
            COPY_THIS(suspension_sound);
            COPY_THIS(crash_sound);
            COPY_THIS(material_effects);
            COPY_THIS(effect);
            COPY_THIS(unit_flags);
            COPY_THIS(default_team);
            COPY_THIS(constant_sound_volume);
            COPY_THIS(rider_damage_fraction);
            COPY_THIS(integrated_light_toggle);
            COPY_THIS(unit_a_in);
            COPY_THIS(unit_b_in);
            COPY_THIS(unit_c_in);
            COPY_THIS(unit_d_in);
            COPY_THIS(camera_field_of_view);
            COPY_THIS(camera_stiffness);
            COPY_THIS(camera_marker_name);
            COPY_THIS(camera_submerged_marker_name);
            COPY_THIS(pitch_auto_level);
            COPY_THIS(pitch_range);
            COPY_THIS(camera_tracks);
            COPY_THIS(seat_acceleration_scale);
            COPY_THIS(soft_ping_threshold);
            COPY_THIS(soft_ping_interrupt_time);
            COPY_THIS(hard_ping_threshold);
            COPY_THIS(hard_ping_interrupt_time);
            COPY_THIS(hard_death_threshold);
            COPY_THIS(feign_death_threshold);
            COPY_THIS(feign_death_time);
            COPY_THIS(distance_of_evade_anim);
            COPY_THIS(distance_of_dive_anim);
            COPY_THIS(stunned_movement_threshold);
            COPY_THIS(feign_death_chance);
            COPY_THIS(feign_repeat_chance);
            COPY_THIS(spawned_actor);
            COPY_THIS(spawned_actor_count);
            COPY_THIS(spawned_velocity);
            COPY_THIS(aiming_velocity_maximum);
            COPY_THIS(aiming_acceleration_maximum);
            COPY_THIS(casual_aiming_modifier);
            COPY_THIS(looking_velocity_maximum);
            COPY_THIS(looking_acceleration_maximum);
            COPY_THIS(ai_vehicle_radius);
            COPY_THIS(ai_danger_radius);
            COPY_THIS(melee_damage);
            COPY_THIS(motion_sensor_blip_size);
            COPY_THIS(metagame_type);
            COPY_THIS(metagame_class);
            COPY_THIS(new_hud_interfaces);
            COPY_THIS(dialogue_variants);
            COPY_THIS(grenade_velocity);
            COPY_THIS(grenade_type);
            COPY_THIS(grenade_count);
            COPY_THIS(soft_ping_interrupt_ticks);
            COPY_THIS(hard_ping_interrupt_ticks);
            COPY_THIS(powered_seats);
            COPY_THIS(weapons);
            COPY_THIS(seats);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Vehicle<NativeEndian>) == 0x3F0);

    ENDIAN_TEMPLATE(EndianType) struct VirtualKeyboardVirtualKey {
        EndianType<VirtualKeyboardKeyboardKey> keyboard_key;
        EndianType<std::int16_t> lowercase_character;
        EndianType<std::int16_t> shift_character;
        EndianType<std::int16_t> caps_character;
        EndianType<std::int16_t> symbols_character;
        EndianType<std::int16_t> shift_caps_character;
        EndianType<std::int16_t> shift_symbols_character;
        EndianType<std::int16_t> caps_symbols_character;
        TagDependency<EndianType> unselected_background_bitmap;
        TagDependency<EndianType> selected_background_bitmap;
        TagDependency<EndianType> active_background_bitmap;
        TagDependency<EndianType> sticky_background_bitmap;
        ENDIAN_TEMPLATE(NewEndian) operator VirtualKeyboardVirtualKey<NewEndian>() const {
            VirtualKeyboardVirtualKey<NewEndian> copy;
            COPY_THIS(keyboard_key);
            COPY_THIS(lowercase_character);
            COPY_THIS(shift_character);
            COPY_THIS(caps_character);
            COPY_THIS(symbols_character);
            COPY_THIS(shift_caps_character);
            COPY_THIS(shift_symbols_character);
            COPY_THIS(caps_symbols_character);
            COPY_THIS(unselected_background_bitmap);
            COPY_THIS(selected_background_bitmap);
            COPY_THIS(active_background_bitmap);
            COPY_THIS(sticky_background_bitmap);
            return copy;
        }
    };
    static_assert(sizeof(VirtualKeyboardVirtualKey<NativeEndian>) == 0x50);

    ENDIAN_TEMPLATE(EndianType) struct VirtualKeyboard {
        TagDependency<EndianType> display_font;
        TagDependency<EndianType> background_bitmap;
        TagDependency<EndianType> special_key_labels_string_list;
        TagReflexive<EndianType, VirtualKeyboardVirtualKey> virtual_keys;
        ENDIAN_TEMPLATE(NewEndian) operator VirtualKeyboard<NewEndian>() const {
            VirtualKeyboard<NewEndian> copy;
            COPY_THIS(display_font);
            COPY_THIS(background_bitmap);
            COPY_THIS(special_key_labels_string_list);
            COPY_THIS(virtual_keys);
            return copy;
        }
    };
    static_assert(sizeof(VirtualKeyboard<NativeEndian>) == 0x3C);

    ENDIAN_TEMPLATE(EndianType) struct WeaponMagazineObject {
        EndianType<std::int16_t> rounds;
        PAD(0xA);
        TagDependency<EndianType> equipment;
        ENDIAN_TEMPLATE(NewEndian) operator WeaponMagazineObject<NewEndian>() const {
            WeaponMagazineObject<NewEndian> copy = {};
            COPY_THIS(rounds);
            COPY_THIS(equipment);
            return copy;
        }
    };
    static_assert(sizeof(WeaponMagazineObject<NativeEndian>) == 0x1C);

    ENDIAN_TEMPLATE(EndianType) struct WeaponMagazine {
        EndianType<WeaponMagazineFlags> flags;
        EndianType<std::int16_t> rounds_recharged;
        EndianType<std::int16_t> rounds_total_initial;
        EndianType<std::int16_t> rounds_reserved_maximum;
        EndianType<std::int16_t> rounds_loaded_maximum;
        PAD(0x8);
        EndianType<float> reload_time;
        EndianType<std::int16_t> rounds_reloaded;
        PAD(0x2);
        EndianType<float> chamber_time;
        PAD(0x8);
        PAD(0x10);
        TagDependency<EndianType> reloading_effect;
        TagDependency<EndianType> chambering_effect;
        PAD(0xC);
        TagReflexive<EndianType, WeaponMagazineObject> magazine_objects;
        ENDIAN_TEMPLATE(NewEndian) operator WeaponMagazine<NewEndian>() const {
            WeaponMagazine<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(rounds_recharged);
            COPY_THIS(rounds_total_initial);
            COPY_THIS(rounds_reserved_maximum);
            COPY_THIS(rounds_loaded_maximum);
            COPY_THIS(reload_time);
            COPY_THIS(rounds_reloaded);
            COPY_THIS(chamber_time);
            COPY_THIS(reloading_effect);
            COPY_THIS(chambering_effect);
            COPY_THIS(magazine_objects);
            return copy;
        }
    };
    static_assert(sizeof(WeaponMagazine<NativeEndian>) == 0x70);

    ENDIAN_TEMPLATE(EndianType) struct WeaponTriggerFiringEffect {
        EndianType<std::int16_t> shot_count_lower_bound;
        EndianType<std::int16_t> shot_count_upper_bound;
        PAD(0x20);
        TagDependency<EndianType> firing_effect;
        TagDependency<EndianType> misfire_effect;
        TagDependency<EndianType> empty_effect;
        TagDependency<EndianType> firing_damage;
        TagDependency<EndianType> misfire_damage;
        TagDependency<EndianType> empty_damage;
        ENDIAN_TEMPLATE(NewEndian) operator WeaponTriggerFiringEffect<NewEndian>() const {
            WeaponTriggerFiringEffect<NewEndian> copy = {};
            COPY_THIS(shot_count_lower_bound);
            COPY_THIS(shot_count_upper_bound);
            COPY_THIS(firing_effect);
            COPY_THIS(misfire_effect);
            COPY_THIS(empty_effect);
            COPY_THIS(firing_damage);
            COPY_THIS(misfire_damage);
            COPY_THIS(empty_damage);
            return copy;
        }
    };
    static_assert(sizeof(WeaponTriggerFiringEffect<NativeEndian>) == 0x84);

    ENDIAN_TEMPLATE(EndianType) struct WeaponTrigger {
        EndianType<WeaponTriggerFlags> flags;
        Bounds<EndianType<float>> maximum_rate_of_fire;
        EndianType<float> acceleration_time;
        EndianType<float> deceleration_time;
        EndianType<Fraction> blurred_rate_of_fire;
        PAD(0x8);
        EndianType<Index> magazine;
        EndianType<std::int16_t> rounds_per_shot;
        EndianType<std::int16_t> minimum_rounds_loaded;
        EndianType<std::int16_t> projectiles_between_contrails;
        PAD(0x4);
        EndianType<WeaponPredictionType> prediction_type;
        EndianType<ObjectNoise> firing_noise;
        Bounds<EndianType<float>> error;
        EndianType<float> error_acceleration_time;
        EndianType<float> error_deceleration_time;
        PAD(0x8);
        EndianType<float> charging_time;
        EndianType<float> charged_time;
        EndianType<WeaponOverchargedAction> overcharged_action;
        PAD(0x2);
        EndianType<float> charged_illumination;
        EndianType<float> spew_time;
        TagDependency<EndianType> charging_effect;
        EndianType<WeaponDistributionFunction> distribution_function;
        EndianType<std::int16_t> projectiles_per_shot;
        EndianType<Angle> distribution_angle;
        PAD(0x4);
        EndianType<Angle> minimum_error;
        Bounds<EndianType<Angle>> error_angle;
        Point3D<EndianType> first_person_offset;
        PAD(0x4);
        TagDependency<EndianType> projectile;
        EndianType<float> ejection_port_recovery_time;
        EndianType<float> illumination_recovery_time;
        PAD(0xC);
        EndianType<Fraction> heat_generated_per_round;
        EndianType<Fraction> age_generated_per_round;
        PAD(0x4);
        EndianType<float> overload_time;
        PAD(0x8);
        PAD(0x20);
        LittleEndian<float> illumination_recovery_rate;
        LittleEndian<float> ejection_port_recovery_rate;
        LittleEndian<float> firing_acceleration_rate;
        LittleEndian<float> firing_deceleration_rate;
        LittleEndian<float> error_acceleration_rate;
        LittleEndian<float> error_deceleration_rate;
        TagReflexive<EndianType, WeaponTriggerFiringEffect> firing_effects;
        ENDIAN_TEMPLATE(NewEndian) operator WeaponTrigger<NewEndian>() const {
            WeaponTrigger<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(maximum_rate_of_fire);
            COPY_THIS(acceleration_time);
            COPY_THIS(deceleration_time);
            COPY_THIS(blurred_rate_of_fire);
            COPY_THIS(magazine);
            COPY_THIS(rounds_per_shot);
            COPY_THIS(minimum_rounds_loaded);
            COPY_THIS(projectiles_between_contrails);
            COPY_THIS(prediction_type);
            COPY_THIS(firing_noise);
            COPY_THIS(error);
            COPY_THIS(error_acceleration_time);
            COPY_THIS(error_deceleration_time);
            COPY_THIS(charging_time);
            COPY_THIS(charged_time);
            COPY_THIS(overcharged_action);
            COPY_THIS(charged_illumination);
            COPY_THIS(spew_time);
            COPY_THIS(charging_effect);
            COPY_THIS(distribution_function);
            COPY_THIS(projectiles_per_shot);
            COPY_THIS(distribution_angle);
            COPY_THIS(minimum_error);
            COPY_THIS(error_angle);
            COPY_THIS(first_person_offset);
            COPY_THIS(projectile);
            COPY_THIS(ejection_port_recovery_time);
            COPY_THIS(illumination_recovery_time);
            COPY_THIS(heat_generated_per_round);
            COPY_THIS(age_generated_per_round);
            COPY_THIS(overload_time);
            COPY_THIS(illumination_recovery_rate);
            COPY_THIS(ejection_port_recovery_rate);
            COPY_THIS(firing_acceleration_rate);
            COPY_THIS(firing_deceleration_rate);
            COPY_THIS(error_acceleration_rate);
            COPY_THIS(error_deceleration_rate);
            COPY_THIS(firing_effects);
            return copy;
        }
    };
    static_assert(sizeof(WeaponTrigger<NativeEndian>) == 0x114);

    ENDIAN_TEMPLATE(EndianType) struct Weapon : Item<EndianType> {
        EndianType<WeaponFlags> weapon_flags;
        TagString label;
        EndianType<WeaponSecondaryTriggerMode> secondary_trigger_mode;
        EndianType<std::int16_t> maximum_alternate_shots_loaded;
        EndianType<WeaponFunctionIn> weapon_a_in;
        EndianType<WeaponFunctionIn> weapon_b_in;
        EndianType<WeaponFunctionIn> weapon_c_in;
        EndianType<WeaponFunctionIn> weapon_d_in;
        EndianType<float> ready_time;
        TagDependency<EndianType> ready_effect;
        EndianType<Fraction> heat_recovery_threshold;
        EndianType<Fraction> overheated_threshold;
        EndianType<Fraction> heat_detonation_threshold;
        EndianType<Fraction> heat_detonation_fraction;
        EndianType<Fraction> heat_loss_rate;
        EndianType<Fraction> heat_illumination;
        PAD(0x10);
        TagDependency<EndianType> overheated;
        TagDependency<EndianType> overheat_detonation;
        TagDependency<EndianType> player_melee_damage;
        TagDependency<EndianType> player_melee_response;
        PAD(0x8);
        TagDependency<EndianType> actor_firing_parameters;
        EndianType<float> near_reticle_range;
        EndianType<float> far_reticle_range;
        EndianType<float> intersection_reticle_range;
        PAD(0x2);
        EndianType<std::int16_t> zoom_levels;
        Bounds<EndianType<float>> zoom_magnification_range;
        EndianType<Angle> autoaim_angle;
        EndianType<float> autoaim_range;
        EndianType<Angle> magnetism_angle;
        EndianType<float> magnetism_range;
        EndianType<Angle> deviation_angle;
        PAD(0x4);
        EndianType<WeaponMovementPenalized> movement_penalized;
        PAD(0x2);
        EndianType<Fraction> forward_movement_penalty;
        EndianType<Fraction> sideways_movement_penalty;
        PAD(0x4);
        EndianType<float> minimum_target_range;
        EndianType<float> looking_time_modifier;
        PAD(0x4);
        EndianType<float> light_power_on_time;
        EndianType<float> light_power_off_time;
        TagDependency<EndianType> light_power_on_effect;
        TagDependency<EndianType> light_power_off_effect;
        EndianType<float> age_heat_recovery_penalty;
        EndianType<float> age_rate_of_fire_penalty;
        EndianType<Fraction> age_misfire_start;
        EndianType<Fraction> age_misfire_chance;
        PAD(0xC);
        TagDependency<EndianType> first_person_model;
        TagDependency<EndianType> first_person_animations;
        PAD(0x4);
        TagDependency<EndianType> hud_interface;
        TagDependency<EndianType> pickup_sound;
        TagDependency<EndianType> zoom_in_sound;
        TagDependency<EndianType> zoom_out_sound;
        PAD(0xC);
        EndianType<float> active_camo_ding;
        EndianType<float> active_camo_regrowth_rate;
        PAD(0xC);
        PAD(0x2);
        EndianType<WeaponType> weapon_type;
        TagReflexive<EndianType, PredictedResource> more_predicted_resources;
        TagReflexive<EndianType, WeaponMagazine> magazines;
        TagReflexive<EndianType, WeaponTrigger> triggers;
        ENDIAN_TEMPLATE(NewEndian) operator Weapon<NewEndian>() const {
            Weapon<NewEndian> copy = {};
            COPY_THIS(weapon_flags);
            COPY_THIS(label);
            COPY_THIS(secondary_trigger_mode);
            COPY_THIS(maximum_alternate_shots_loaded);
            COPY_THIS(weapon_a_in);
            COPY_THIS(weapon_b_in);
            COPY_THIS(weapon_c_in);
            COPY_THIS(weapon_d_in);
            COPY_THIS(ready_time);
            COPY_THIS(ready_effect);
            COPY_THIS(heat_recovery_threshold);
            COPY_THIS(overheated_threshold);
            COPY_THIS(heat_detonation_threshold);
            COPY_THIS(heat_detonation_fraction);
            COPY_THIS(heat_loss_rate);
            COPY_THIS(heat_illumination);
            COPY_THIS(overheated);
            COPY_THIS(overheat_detonation);
            COPY_THIS(player_melee_damage);
            COPY_THIS(player_melee_response);
            COPY_THIS(actor_firing_parameters);
            COPY_THIS(near_reticle_range);
            COPY_THIS(far_reticle_range);
            COPY_THIS(intersection_reticle_range);
            COPY_THIS(zoom_levels);
            COPY_THIS(zoom_magnification_range);
            COPY_THIS(autoaim_angle);
            COPY_THIS(autoaim_range);
            COPY_THIS(magnetism_angle);
            COPY_THIS(magnetism_range);
            COPY_THIS(deviation_angle);
            COPY_THIS(movement_penalized);
            COPY_THIS(forward_movement_penalty);
            COPY_THIS(sideways_movement_penalty);
            COPY_THIS(minimum_target_range);
            COPY_THIS(looking_time_modifier);
            COPY_THIS(light_power_on_time);
            COPY_THIS(light_power_off_time);
            COPY_THIS(light_power_on_effect);
            COPY_THIS(light_power_off_effect);
            COPY_THIS(age_heat_recovery_penalty);
            COPY_THIS(age_rate_of_fire_penalty);
            COPY_THIS(age_misfire_start);
            COPY_THIS(age_misfire_chance);
            COPY_THIS(first_person_model);
            COPY_THIS(first_person_animations);
            COPY_THIS(hud_interface);
            COPY_THIS(pickup_sound);
            COPY_THIS(zoom_in_sound);
            COPY_THIS(zoom_out_sound);
            COPY_THIS(active_camo_ding);
            COPY_THIS(active_camo_regrowth_rate);
            COPY_THIS(weapon_type);
            COPY_THIS(more_predicted_resources);
            COPY_THIS(magazines);
            COPY_THIS(triggers);
            COPY_THIS(item_flags);
            COPY_THIS(pickup_text_index);
            COPY_THIS(sort_order);
            COPY_THIS(scale);
            COPY_THIS(hud_message_value_scale);
            COPY_THIS(item_a_in);
            COPY_THIS(item_b_in);
            COPY_THIS(item_c_in);
            COPY_THIS(item_d_in);
            COPY_THIS(material_effects);
            COPY_THIS(collision_sound);
            COPY_THIS(detonation_delay);
            COPY_THIS(detonating_effect);
            COPY_THIS(detonation_effect);
            COPY_THIS(object_type);
            COPY_THIS(flags);
            COPY_THIS(bounding_radius);
            COPY_THIS(bounding_offset);
            COPY_THIS(origin_offset);
            COPY_THIS(acceleration_scale);
            COPY_THIS(scales_change_colors);
            COPY_THIS(model);
            COPY_THIS(animation_graph);
            COPY_THIS(collision_model);
            COPY_THIS(physics);
            COPY_THIS(modifier_shader);
            COPY_THIS(creation_effect);
            COPY_THIS(render_bounding_radius);
            COPY_THIS(a_in);
            COPY_THIS(b_in);
            COPY_THIS(c_in);
            COPY_THIS(d_in);
            COPY_THIS(hud_text_message_index);
            COPY_THIS(forced_shader_permutation_index);
            COPY_THIS(attachments);
            COPY_THIS(widgets);
            COPY_THIS(functions);
            COPY_THIS(change_colors);
            COPY_THIS(predicted_resources);
            return copy;
        }
    };
    static_assert(sizeof(Weapon<NativeEndian>) == 0x508);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceStaticElement {
        EndianType<WeaponHUDInterfaceStateAttachedTo> state_attached_to;
        PAD(0x2);
        EndianType<WeaponHUDInterfaceViewType> allowed_view_type;
        EndianType<HUDInterfaceChildAnchor> anchor;
        PAD(0x1C);
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> interface_bitmap;
        EndianType<ColorARGBInt> default_color;
        EndianType<ColorARGBInt> flashing_color;
        EndianType<float> flash_period;
        EndianType<float> flash_delay;
        EndianType<std::int16_t> number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> flash_flags;
        EndianType<float> flash_length;
        EndianType<ColorARGBInt> disabled_color;
        PAD(0x4);
        EndianType<Index> sequence_index;
        PAD(0x2);
        TagReflexive<EndianType, HUDInterfaceMultitextureOverlay> multitexture_overlays;
        PAD(0x4);
        PAD(0x28);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceStaticElement<NewEndian>() const {
            WeaponHUDInterfaceStaticElement<NewEndian> copy = {};
            COPY_THIS(state_attached_to);
            COPY_THIS(allowed_view_type);
            COPY_THIS(anchor);
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(interface_bitmap);
            COPY_THIS(default_color);
            COPY_THIS(flashing_color);
            COPY_THIS(flash_period);
            COPY_THIS(flash_delay);
            COPY_THIS(number_of_flashes);
            COPY_THIS(flash_flags);
            COPY_THIS(flash_length);
            COPY_THIS(disabled_color);
            COPY_THIS(sequence_index);
            COPY_THIS(multitexture_overlays);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceStaticElement<NativeEndian>) == 0xB4);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceMeter {
        EndianType<WeaponHUDInterfaceStateAttachedTo> state_attached_to;
        PAD(0x2);
        EndianType<WeaponHUDInterfaceViewType> allowed_view_type;
        EndianType<HUDInterfaceChildAnchor> anchor;
        PAD(0x1C);
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        TagDependency<EndianType> meter_bitmap;
        EndianType<ColorARGBInt> color_at_meter_minimum;
        EndianType<ColorARGBInt> color_at_meter_maximum;
        EndianType<ColorARGBInt> flash_color;
        EndianType<ColorARGBInt> empty_color;
        HUDInterfaceMeterFlags flags;
        std::int8_t minimum_meter_value;
        EndianType<Index> sequence_index;
        std::int8_t alpha_multiplier;
        std::int8_t alpha_bias;
        EndianType<std::int16_t> value_scale;
        EndianType<float> opacity;
        EndianType<float> translucency;
        EndianType<ColorARGBInt> disabled_color;
        EndianType<float> min_alpha;
        PAD(0xC);
        PAD(0x28);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceMeter<NewEndian>() const {
            WeaponHUDInterfaceMeter<NewEndian> copy = {};
            COPY_THIS(state_attached_to);
            COPY_THIS(allowed_view_type);
            COPY_THIS(anchor);
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(meter_bitmap);
            COPY_THIS(color_at_meter_minimum);
            COPY_THIS(color_at_meter_maximum);
            COPY_THIS(flash_color);
            COPY_THIS(empty_color);
            COPY_THIS(flags);
            COPY_THIS(minimum_meter_value);
            COPY_THIS(sequence_index);
            COPY_THIS(alpha_multiplier);
            COPY_THIS(alpha_bias);
            COPY_THIS(value_scale);
            COPY_THIS(opacity);
            COPY_THIS(translucency);
            COPY_THIS(disabled_color);
            COPY_THIS(min_alpha);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceMeter<NativeEndian>) == 0xB4);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceNumber {
        EndianType<WeaponHUDInterfaceStateAttachedTo> state_attached_to;
        PAD(0x2);
        EndianType<WeaponHUDInterfaceViewType> allowed_view_type;
        EndianType<HUDInterfaceChildAnchor> anchor;
        PAD(0x1C);
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        EndianType<ColorARGBInt> default_color;
        EndianType<ColorARGBInt> flashing_color;
        EndianType<float> flash_period;
        EndianType<float> flash_delay;
        EndianType<std::int16_t> number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> flash_flags;
        EndianType<float> flash_length;
        EndianType<ColorARGBInt> disabled_color;
        PAD(0x4);
        std::int8_t maximum_number_of_digits;
        EndianType<HUDInterfaceNumberFlags> flags;
        std::int8_t number_of_fractional_digits;
        PAD(0x1);
        PAD(0xC);
        EndianType<WeaponHUDInterfaceNumberWeaponSpecificFlags> weapon_specific_flags;
        PAD(0x2);
        PAD(0x24);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceNumber<NewEndian>() const {
            WeaponHUDInterfaceNumber<NewEndian> copy = {};
            COPY_THIS(state_attached_to);
            COPY_THIS(allowed_view_type);
            COPY_THIS(anchor);
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(default_color);
            COPY_THIS(flashing_color);
            COPY_THIS(flash_period);
            COPY_THIS(flash_delay);
            COPY_THIS(number_of_flashes);
            COPY_THIS(flash_flags);
            COPY_THIS(flash_length);
            COPY_THIS(disabled_color);
            COPY_THIS(maximum_number_of_digits);
            COPY_THIS(flags);
            COPY_THIS(number_of_fractional_digits);
            COPY_THIS(weapon_specific_flags);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceNumber<NativeEndian>) == 0xA0);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceCrosshairOverlay {
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        EndianType<ColorARGBInt> default_color;
        EndianType<ColorARGBInt> flashing_color;
        EndianType<float> flash_period;
        EndianType<float> flash_delay;
        EndianType<std::int16_t> number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> flash_flags;
        EndianType<float> flash_length;
        EndianType<ColorARGBInt> disabled_color;
        PAD(0x4);
        EndianType<std::int16_t> frame_rate;
        EndianType<Index> sequence_index;
        EndianType<WeaponHUDInterfaceCrosshairOverlayFlags> flags;
        PAD(0x20);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceCrosshairOverlay<NewEndian>() const {
            WeaponHUDInterfaceCrosshairOverlay<NewEndian> copy = {};
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(default_color);
            COPY_THIS(flashing_color);
            COPY_THIS(flash_period);
            COPY_THIS(flash_delay);
            COPY_THIS(number_of_flashes);
            COPY_THIS(flash_flags);
            COPY_THIS(flash_length);
            COPY_THIS(disabled_color);
            COPY_THIS(frame_rate);
            COPY_THIS(sequence_index);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceCrosshairOverlay<NativeEndian>) == 0x6C);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceCrosshair {
        EndianType<WeaponHUDInterfaceCrosshairType> crosshair_type;
        PAD(0x2);
        EndianType<WeaponHUDInterfaceViewType> allowed_view_type;
        PAD(0x2);
        PAD(0x1C);
        TagDependency<EndianType> crosshair_bitmap;
        TagReflexive<EndianType, WeaponHUDInterfaceCrosshairOverlay> crosshair_overlays;
        PAD(0x28);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceCrosshair<NewEndian>() const {
            WeaponHUDInterfaceCrosshair<NewEndian> copy = {};
            COPY_THIS(crosshair_type);
            COPY_THIS(allowed_view_type);
            COPY_THIS(crosshair_bitmap);
            COPY_THIS(crosshair_overlays);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceCrosshair<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceOverlay {
        Point2DInt<EndianType> anchor_offset;
        EndianType<float> width_scale;
        EndianType<float> height_scale;
        EndianType<HUDInterfaceScalingFlags> scaling_flags;
        PAD(0x2);
        PAD(0x14);
        EndianType<ColorARGBInt> default_color;
        EndianType<ColorARGBInt> flashing_color;
        EndianType<float> flash_period;
        EndianType<float> flash_delay;
        EndianType<std::int16_t> number_of_flashes;
        EndianType<HUDInterfaceFlashFlags> flash_flags;
        EndianType<float> flash_length;
        EndianType<ColorARGBInt> disabled_color;
        PAD(0x4);
        EndianType<std::int16_t> frame_rate;
        PAD(0x2);
        EndianType<Index> sequence_index;
        EndianType<WeaponHUDInterfaceOverlayType> type;
        EndianType<HUDInterfaceOverlayFlashFlags> flags;
        PAD(0x10);
        PAD(0x28);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceOverlay<NewEndian>() const {
            WeaponHUDInterfaceOverlay<NewEndian> copy = {};
            COPY_THIS(anchor_offset);
            COPY_THIS(width_scale);
            COPY_THIS(height_scale);
            COPY_THIS(scaling_flags);
            COPY_THIS(default_color);
            COPY_THIS(flashing_color);
            COPY_THIS(flash_period);
            COPY_THIS(flash_delay);
            COPY_THIS(number_of_flashes);
            COPY_THIS(flash_flags);
            COPY_THIS(flash_length);
            COPY_THIS(disabled_color);
            COPY_THIS(frame_rate);
            COPY_THIS(sequence_index);
            COPY_THIS(type);
            COPY_THIS(flags);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceOverlay<NativeEndian>) == 0x88);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceOverlayElement {
        EndianType<WeaponHUDInterfaceStateAttachedTo> state_attached_to;
        PAD(0x2);
        EndianType<WeaponHUDInterfaceViewType> allowed_view_type;
        EndianType<HUDInterfaceChildAnchor> anchor;
        PAD(0x1C);
        TagDependency<EndianType> overlay_bitmap;
        TagReflexive<EndianType, WeaponHUDInterfaceOverlay> overlays;
        PAD(0x28);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceOverlayElement<NewEndian>() const {
            WeaponHUDInterfaceOverlayElement<NewEndian> copy = {};
            COPY_THIS(state_attached_to);
            COPY_THIS(allowed_view_type);
            COPY_THIS(anchor);
            COPY_THIS(overlay_bitmap);
            COPY_THIS(overlays);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceOverlayElement<NativeEndian>) == 0x68);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterfaceScreenEffect {
        PAD(0x4);
        EndianType<WeaponHUDInterfaceScreenEffectDefinitionMaskFlags> mask_flags;
        PAD(0x2);
        PAD(0x10);
        TagDependency<EndianType> mask_fullscreen;
        TagDependency<EndianType> mask_splitscreen;
        PAD(0x8);
        EndianType<WeaponHUDInterfaceScreenEffectDefinitionMaskFlags> convolution_flags;
        PAD(0x2);
        Bounds<EndianType<Angle>> convolution_fov_in_bounds;
        Bounds<EndianType<float>> convolution_radius_out_bounds;
        PAD(0x18);
        EndianType<WeaponHUDInterfaceScreenEffectDefinitionNightVisionFlags> even_more_flags;
        EndianType<std::int16_t> night_vision_script_source;
        EndianType<Fraction> night_vision_intensity;
        PAD(0x18);
        EndianType<WeaponHUDInterfaceScreenEffectDefinitionDesaturationFlags> desaturation_flags;
        EndianType<std::int16_t> desaturation_script_source;
        EndianType<Fraction> desaturation_intensity;
        ColorRGB<EndianType> effect_tint;
        PAD(0x18);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterfaceScreenEffect<NewEndian>() const {
            WeaponHUDInterfaceScreenEffect<NewEndian> copy = {};
            COPY_THIS(mask_flags);
            COPY_THIS(mask_fullscreen);
            COPY_THIS(mask_splitscreen);
            COPY_THIS(convolution_flags);
            COPY_THIS(convolution_fov_in_bounds);
            COPY_THIS(convolution_radius_out_bounds);
            COPY_THIS(even_more_flags);
            COPY_THIS(night_vision_script_source);
            COPY_THIS(night_vision_intensity);
            COPY_THIS(desaturation_flags);
            COPY_THIS(desaturation_script_source);
            COPY_THIS(desaturation_intensity);
            COPY_THIS(effect_tint);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterfaceScreenEffect<NativeEndian>) == 0xB8);

    ENDIAN_TEMPLATE(EndianType) struct WeaponHUDInterface {
        TagDependency<EndianType> child_hud;
        EndianType<WeaponHUDInterfaceFlags> flags;
        PAD(0x2);
        EndianType<std::int16_t> total_ammo_cutoff;
        EndianType<std::int16_t> loaded_ammo_cutoff;
        EndianType<std::int16_t> heat_cutoff;
        EndianType<std::int16_t> age_cutoff;
        PAD(0x20);
        EndianType<HUDInterfaceAnchor> anchor;
        PAD(0x2);
        PAD(0x20);
        TagReflexive<EndianType, WeaponHUDInterfaceStaticElement> static_elements;
        TagReflexive<EndianType, WeaponHUDInterfaceMeter> meter_elements;
        TagReflexive<EndianType, WeaponHUDInterfaceNumber> number_elements;
        TagReflexive<EndianType, WeaponHUDInterfaceCrosshair> crosshairs;
        TagReflexive<EndianType, WeaponHUDInterfaceOverlayElement> overlay_elements;
        LittleEndian<WeaponHUDInterfaceCrosshairTypeFlags> crosshair_types;
        PAD(0xC);
        TagReflexive<EndianType, WeaponHUDInterfaceScreenEffect> screen_effect;
        PAD(0x84);
        EndianType<Index> messaging_information_sequence_index;
        EndianType<std::int16_t> messaging_information_width_offset;
        Point2DInt<EndianType> messaging_information_offset_from_reference_corner;
        EndianType<ColorARGBInt> messaging_information_override_icon_color;
        std::int8_t messaging_information_frame_rate;
        HUDInterfaceMessagingFlags messaging_information_flags;
        EndianType<Index> messaging_information_text_index;
        PAD(0x30);
        ENDIAN_TEMPLATE(NewEndian) operator WeaponHUDInterface<NewEndian>() const {
            WeaponHUDInterface<NewEndian> copy = {};
            COPY_THIS(child_hud);
            COPY_THIS(flags);
            COPY_THIS(total_ammo_cutoff);
            COPY_THIS(loaded_ammo_cutoff);
            COPY_THIS(heat_cutoff);
            COPY_THIS(age_cutoff);
            COPY_THIS(anchor);
            COPY_THIS(static_elements);
            COPY_THIS(meter_elements);
            COPY_THIS(number_elements);
            COPY_THIS(crosshairs);
            COPY_THIS(overlay_elements);
            COPY_THIS(crosshair_types);
            COPY_THIS(screen_effect);
            COPY_THIS(messaging_information_sequence_index);
            COPY_THIS(messaging_information_width_offset);
            COPY_THIS(messaging_information_offset_from_reference_corner);
            COPY_THIS(messaging_information_override_icon_color);
            COPY_THIS(messaging_information_frame_rate);
            COPY_THIS(messaging_information_flags);
            COPY_THIS(messaging_information_text_index);
            return copy;
        }
    };
    static_assert(sizeof(WeaponHUDInterface<NativeEndian>) == 0x17C);

    ENDIAN_TEMPLATE(EndianType) struct WeatherParticleSystemParticleType {
        TagString name;
        EndianType<WeatherParticleSystemParticleTypeFlags> flags;
        EndianType<float> fade_in_start_distance;
        EndianType<float> fade_in_end_distance;
        EndianType<float> fade_out_start_distance;
        EndianType<float> fade_out_end_distance;
        EndianType<float> fade_in_start_height;
        EndianType<float> fade_in_end_height;
        EndianType<float> fade_out_start_height;
        EndianType<float> fade_out_end_height;
        PAD(0x60);
        Bounds<EndianType<float>> particle_count;
        TagDependency<EndianType> physics;
        PAD(0x10);
        Bounds<EndianType<float>> acceleration_magnitude;
        EndianType<Fraction> acceleration_turning_rate;
        EndianType<float> acceleration_change_rate;
        PAD(0x20);
        Bounds<EndianType<float>> particle_radius;
        Bounds<EndianType<float>> animation_rate;
        Bounds<EndianType<Angle>> rotation_rate;
        PAD(0x20);
        ColorARGB<EndianType> color_lower_bound;
        ColorARGB<EndianType> color_upper_bound;
        LittleEndian<float> sprite_size;
        PAD(0x3C);
        TagDependency<EndianType> sprite_bitmap;
        EndianType<ParticleOrientation> render_mode;
        EndianType<WeatherParticleSystemRenderDirectionSource> render_direction_source;
        PAD(0x24);
        LittleEndian<std::uint32_t> not_broken;
        EndianType<ParticleShaderFlags> shader_flags;
        EndianType<FramebufferBlendFunction> framebuffer_blend_function;
        EndianType<FramebufferFadeMode> framebuffer_fade_mode;
        EndianType<IsUnfilteredFlag> map_flags;
        PAD(0x1C);
        TagDependency<EndianType> bitmap;
        EndianType<ParticleAnchor> anchor;
        EndianType<IsUnfilteredFlag> flags_1;
        EndianType<FunctionOut> u_animation_source;
        EndianType<WaveFunction> u_animation_function;
        EndianType<float> u_animation_period;
        EndianType<float> u_animation_phase;
        EndianType<float> u_animation_scale;
        EndianType<FunctionOut> v_animation_source;
        EndianType<WaveFunction> v_animation_function;
        EndianType<float> v_animation_period;
        EndianType<float> v_animation_phase;
        EndianType<float> v_animation_scale;
        EndianType<FunctionOut> rotation_animation_source;
        EndianType<WaveFunction> rotation_animation_function;
        EndianType<float> rotation_animation_period;
        EndianType<float> rotation_animation_phase;
        EndianType<Angle> rotation_animation_scale;
        Point2D<EndianType> rotation_animation_center;
        PAD(0x4);
        EndianType<float> zsprite_radius_scale;
        PAD(0x14);
        ENDIAN_TEMPLATE(NewEndian) operator WeatherParticleSystemParticleType<NewEndian>() const {
            WeatherParticleSystemParticleType<NewEndian> copy = {};
            COPY_THIS(name);
            COPY_THIS(flags);
            COPY_THIS(fade_in_start_distance);
            COPY_THIS(fade_in_end_distance);
            COPY_THIS(fade_out_start_distance);
            COPY_THIS(fade_out_end_distance);
            COPY_THIS(fade_in_start_height);
            COPY_THIS(fade_in_end_height);
            COPY_THIS(fade_out_start_height);
            COPY_THIS(fade_out_end_height);
            COPY_THIS(particle_count);
            COPY_THIS(physics);
            COPY_THIS(acceleration_magnitude);
            COPY_THIS(acceleration_turning_rate);
            COPY_THIS(acceleration_change_rate);
            COPY_THIS(particle_radius);
            COPY_THIS(animation_rate);
            COPY_THIS(rotation_rate);
            COPY_THIS(color_lower_bound);
            COPY_THIS(color_upper_bound);
            COPY_THIS(sprite_size);
            COPY_THIS(sprite_bitmap);
            COPY_THIS(render_mode);
            COPY_THIS(render_direction_source);
            COPY_THIS(not_broken);
            COPY_THIS(shader_flags);
            COPY_THIS(framebuffer_blend_function);
            COPY_THIS(framebuffer_fade_mode);
            COPY_THIS(map_flags);
            COPY_THIS(bitmap);
            COPY_THIS(anchor);
            COPY_THIS(flags_1);
            COPY_THIS(u_animation_source);
            COPY_THIS(u_animation_function);
            COPY_THIS(u_animation_period);
            COPY_THIS(u_animation_phase);
            COPY_THIS(u_animation_scale);
            COPY_THIS(v_animation_source);
            COPY_THIS(v_animation_function);
            COPY_THIS(v_animation_period);
            COPY_THIS(v_animation_phase);
            COPY_THIS(v_animation_scale);
            COPY_THIS(rotation_animation_source);
            COPY_THIS(rotation_animation_function);
            COPY_THIS(rotation_animation_period);
            COPY_THIS(rotation_animation_phase);
            COPY_THIS(rotation_animation_scale);
            COPY_THIS(rotation_animation_center);
            COPY_THIS(zsprite_radius_scale);
            return copy;
        }
    };
    static_assert(sizeof(WeatherParticleSystemParticleType<NativeEndian>) == 0x25C);

    ENDIAN_TEMPLATE(EndianType) struct WeatherParticleSystem {
        EndianType<IsUnusedFlag> flags;
        PAD(0x20);
        TagReflexive<EndianType, WeatherParticleSystemParticleType> particle_types;
        ENDIAN_TEMPLATE(NewEndian) operator WeatherParticleSystem<NewEndian>() const {
            WeatherParticleSystem<NewEndian> copy = {};
            COPY_THIS(flags);
            COPY_THIS(particle_types);
            return copy;
        }
    };
    static_assert(sizeof(WeatherParticleSystem<NativeEndian>) == 0x30);

    ENDIAN_TEMPLATE(EndianType) struct Wind {
        Bounds<EndianType<float>> velocity;
        Euler2D<EndianType> variation_area;
        EndianType<float> local_variation_weight;
        EndianType<float> local_variation_rate;
        EndianType<float> damping;
        PAD(0x24);
        ENDIAN_TEMPLATE(NewEndian) operator Wind<NewEndian>() const {
            Wind<NewEndian> copy = {};
            COPY_THIS(velocity);
            COPY_THIS(variation_area);
            COPY_THIS(local_variation_weight);
            COPY_THIS(local_variation_rate);
            COPY_THIS(damping);
            return copy;
        }
    };
    static_assert(sizeof(Wind<NativeEndian>) == 0x40);

}

#endif
