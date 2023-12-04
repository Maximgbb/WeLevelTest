// Fill out your copyright notice in the Description page of Project Settings.


#include "WaitForBooleanChange.h"
#include "ListenActor.h"
#include "TargetActor.h"

UWaitForBooleanChange* UWaitForBooleanChange::WaitForBooleanChange(UObject* InWorldContextObject, AListenActor* InListenActor, ATargetActor* InTargetActor)
{
	UWaitForBooleanChange* Proxy = NewObject<UWaitForBooleanChange>();
	Proxy->ListenActor = InListenActor;
	Proxy->TargetActor = InTargetActor;
	Proxy->RegisterWithGameInstance(InWorldContextObject);
	return Proxy;
}

void UWaitForBooleanChange::Activate()
{
	TargetActor->OnBooleanValueChange.BindUObject(this, &UWaitForBooleanChange::OnTargetBooleanValueChanged);
}

void UWaitForBooleanChange::OnTargetBooleanValueChanged(bool bNewValue)
{
	OnValueChange.Broadcast(bNewValue);
}
