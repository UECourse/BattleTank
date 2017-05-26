// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    auto ControlledTank = GetControlledTank();
    if(!ControlledTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
    }
    UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
    UE_LOG(LogTemp, Warning, TEXT("PlayerController is Ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }
    
    FVector HitLocation; // Out parameter
    
    if (GetSightRayHitLocation(HitLocation)) // has a "side-effect", is going to line trace
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
        // TODO Tell controlled tank to aim at this point
    }
}

// Get world location if lintrace through crroshair, true if hist lanscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    OutHitLocation = FVector (1.0);
    return true;
}
