
#pragma once

#include "EngineMinimal.h"
#include "SlateFwd.h"
#include "UObject/GCObject.h"
#include "SEditorViewport.h"
#include "SCommonEditorViewportToolbarBase.h"

class FIGCEditor;
class UIGC;

class SIGCViewport : public SEditorViewport, public FGCObject
{
public:
	SLATE_BEGIN_ARGS(SIGCViewport) {}//
		SLATE_ARGUMENT(TWeakPtr<FIGCEditor>, ParentIGCEditor)
		SLATE_ARGUMENT(UIGC*, ObjectToEdit)
	SLATE_END_ARGS()////�̷��� ��Ģ���� ���� Ư���� ��ũ�θ� �߰��ϸ� ������Ʈ Ŭ������ ���� ���� �߰��˴ϴ�. �Ʒ��� ���� ������ �����ϸ鼭 ������Ʈ ���� ���� �߰��ϴ� �ڵ��Դϴ�.
	//->����Ʈ ,������ , ui ���δ� �������� �Ǿ� ���� 
	void Construct(const FArguments& InArgs);
	SIGCViewport();
	~SIGCViewport();

	
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	TSharedRef<class FAdvancedPreviewScene> GetPreviewScene();

	virtual FString GetReferencerName()const override;
protected:
	virtual TSharedRef<FEditorViewportClient> MakeEditorViewportClient() override;

private:

	TWeakPtr<FIGCEditor> IGCEditorPtr;//���� /�޴� ���� ����� �������̽� 
	TSharedPtr<class FAdvancedPreviewScene> PreviewScene; //������ ���� ������ �������� ���� 
	TSharedPtr<class FIGCViewportClient> IGCViewportClient;//���� ������ ������ ������ ���� �����͸� ���� 
	UIGC* IGCObject;//iGC object


	TSharedPtr<SVerticalBox> OverlayTextVerticalBox;


	class UStaticMeshComponent* PreviewMeshComponent;//ȭ�鿡 ���̴� �Ž� ������Ʈ 
};