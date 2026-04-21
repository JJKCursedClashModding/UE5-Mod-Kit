#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/TextureRenderTarget2D.h"
#include "GameTextureRenderTarget2D.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameTextureRenderTarget2D : public UTextureRenderTarget2D {
    GENERATED_BODY()
public:
    UGameTextureRenderTarget2D();

    // UTextureRenderTarget2D::CalcTextureMemorySizeEnum has no accessible implementation in UE 5.1
    virtual uint32 CalcTextureMemorySizeEnum(ETextureMipCount Enum) const override;
};
