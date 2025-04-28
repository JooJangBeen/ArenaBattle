// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ABAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLEDEMO_API AABAIController : public AAIController
{
	GENERATED_BODY()

public:
	AABAIController();

	//AI 실행 하는 함수.
	void RunAI();

	void StopAI();

protected:
	//컨트롤러가 폰에 빙의 했을때 실행되는 이벤트 함수.
	virtual void OnPossess(APawn* InPawn) override;
	

	//DAta Section.
private:
	
	UPROPERTY()
	TObjectPtr<class UBlackboardData> BBAsset;

	//Behavior Tree 애셋.
	UPROPERTY()
	TObjectPtr<class UBehaviorTree> BTAsset;
};
