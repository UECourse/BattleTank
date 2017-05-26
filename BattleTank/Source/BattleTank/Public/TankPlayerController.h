// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    ATank* GetControlledTank() const;
	
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
private:
    
    // Start the tank moving the barrel so thet a chot would hit
    //where the crosshair intersects the world
    void AimTowardsCrosshair();
    
    bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
};
