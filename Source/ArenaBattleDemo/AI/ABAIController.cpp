// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/ABAIController.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ABAI.h"

AABAIController::AABAIController()
{
	//애셋 로드.
	//블랙 보드 애셋 로드.
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBAssetRef(TEXT("/Game/ArenaBattle/AI/BB_ABCharacter.BB_ABCharacter"));
	if (BBAssetRef.Object)
	{
		BBAsset = BBAssetRef.Object;
	}

	//비헤이비어 트리(행동 트리) 애셋.
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTDataRef(TEXT("/Game/ArenaBattle/AI/BT_ABCharacter.BT_ABCharacter"));
	if (BTDataRef.Object)
	{
		BTAsset = BTDataRef.Object;
	}
}

void AABAIController::RunAI()
{
	//블랙보드 컴포넌트 포인터 가져오기.
	//UBlackboardComponent* BlackboardPtr = Blackboard.Get(); //수업 코드.
	UBlackboardComponent* BlackboardPtr = GetBlackboardComponent();//있는거 써봄.

	//사용할 블랙보드 지정.
	if (UseBlackboard(BBAsset,BlackboardPtr))
	{
		Blackboard->SetValueAsVector(BBKEY_HOMEPOS, GetPawn()->GetActorLocation());
		//행동 트리 실행.
		bool RunResult = RunBehaviorTree(BTAsset);

		//실행에 실패하면 확인.
		ensure(RunResult);
		
	}

}

void AABAIController::StopAI()
{
	//실행 중인 BehaviorTreeComponent 가져오기.
	UBehaviorTreeComponent* BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);

	//BT 중지.
	if (BTComponent)
	{
		BTComponent->StopTree();
	}
}

void AABAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	//컨트롤러가 폰에 빙의 하면 AI를 실행.
	RunAI();
}
