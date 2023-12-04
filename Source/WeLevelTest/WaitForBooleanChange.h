// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "WaitForBooleanChange.generated.h"

//Signature for OnValueChange execution pin
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBooleanChangeResult, bool, NewValue);

/**
 * 
 */
UCLASS()
class WELEVELTEST_API UWaitForBooleanChange : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FBooleanChangeResult OnValueChange;
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UWaitForBooleanChange* WaitForBooleanChange(UObject* InWorldContextObject, class AListenActor* InListenActor, class ATargetActor* InTargetActor);

	virtual void Activate() override;

protected:

	UFUNCTION()
	void OnTargetBooleanValueChanged(bool bNewValue);

private:

	TWeakObjectPtr<class AListenActor> ListenActor;
	TWeakObjectPtr<class ATargetActor> TargetActor;	
};
