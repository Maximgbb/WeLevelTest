// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetActor.generated.h"

DECLARE_DELEGATE_OneParam(FBooleanValueChange, bool);

UCLASS()
class WELEVELTEST_API ATargetActor : public AActor
{
	GENERATED_BODY()
	
public:	

	ATargetActor();

	UFUNCTION(BlueprintCallable)
	void ToogleBool();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(ReplicatedUsing = OnRep_OnValueChange, EditAnywhere, BlueprintReadWrite)
	bool bBooleanValue = false;

	FBooleanValueChange OnBooleanValueChange;

protected:

	UFUNCTION()
	void OnRep_OnValueChange();
};
