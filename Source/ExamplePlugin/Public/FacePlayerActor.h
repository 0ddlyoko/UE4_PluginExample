// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FacePlayerActor.generated.h"

/*
Spawn a cube that will always face the player
You can change the mesh
*/
UCLASS()
class EXAMPLEPLUGIN_API AFacePlayerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacePlayerActor();

	// On Construction
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* StaticMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
