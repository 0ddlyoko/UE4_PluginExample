// Fill out your copyright notice in the Description page of Project Settings.


#include "HoverComponent.h"

// Sets default values for this component's properties
UHoverComponent::UHoverComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHoverComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UHoverComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult Hit;
	FVector Start = GetComponentLocation();
	FVector End = Start - (GetUpVector() * Height);
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility)) {
		// Draw debug line
		DrawDebugLine(GetWorld(), Start, Hit.ImpactPoint, FColor::Red, false, 0.1f);
		float Distance = Hit.Distance;
		FVector ImpactNormal = Hit.ImpactNormal;
		// Calculate the force to apply
		float ForceFloat = FMath::Lerp(Strengh, 0.0f, Distance / Height);
		// Calculate the direction force to apply
		const FTransform& Transform = GetComponentTransform();
		FVector Direction = Transform.TransformVector(ImpactNormal);
		FVector Force = Direction * ForceFloat;
		UPrimitiveComponent* PrimitiveComponent = GetOwner()->FindComponentByClass<UPrimitiveComponent>();
		if (PrimitiveComponent->IsSimulatingPhysics()) {
			// Apply Force at specific location
			PrimitiveComponent->AddForceAtLocation(Force, Start);
		}
	}
}

