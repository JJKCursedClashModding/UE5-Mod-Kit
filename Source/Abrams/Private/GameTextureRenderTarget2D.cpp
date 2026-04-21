#include "GameTextureRenderTarget2D.h"

UGameTextureRenderTarget2D::UGameTextureRenderTarget2D() {
}

uint32 UGameTextureRenderTarget2D::CalcTextureMemorySizeEnum(ETextureMipCount Enum) const {
    // UTextureRenderTarget2D::CalcTextureMemorySizeEnum has no accessible base implementation in UE 5.1.
    // Return a basic estimate: SizeX * SizeY * bytes-per-pixel (assume 4 bytes for RGBA8).
    const uint32 BytesPerPixel = 4u;
    return static_cast<uint32>(SizeX) * static_cast<uint32>(SizeY) * BytesPerPixel;
}
