// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "CameraViewerActor.generated.h"

UCLASS()
class EXAMPLEPLUGIN_API ACameraViewerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraViewerActor();

	// Equivalent of Construction Script
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1", ClampMax = "16"))
	int CameraNumber = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Height = 800;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Width = 800;

	// Change the current camera specific player is
	UFUNCTION(BlueprintCallable)
	void ChangeCamera(APlayerController* Player, int CameraId);

	// Switch on Next camera
	UFUNCTION(BlueprintCallable)
	void Next();

	// Switch on Previous camera
	UFUNCTION(BlueprintCallable)
	void Previous();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<UCameraComponent*> AllCameras;
	TArray<FTransform> Transforms;

};
