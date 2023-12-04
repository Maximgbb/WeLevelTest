// Fill out your copyright notice in the Description page of Project Settings.


#include "ListenActor.h"
#include "WaitForBooleanChange.h"

AListenActor::AListenActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}
