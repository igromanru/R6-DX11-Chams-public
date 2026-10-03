/*
 *  R6 Chams by Igromanru
 *  Copyright (C) 2024 Igromanru
 *  All rights reserved.
 */
#pragma once

#include <cstdint>
#include <dxgiformat.h>

namespace Models
{
    // Renderer-independent metadata retained from the old DX11 implementation.
    // DX12 resource bindings are descriptor/root-signature based, so this type
    // deliberately contains no ID3D11ShaderResourceView references.
    struct Model
    {
        int Stride;
        int VscWidth;
        int PscWidth;
        DXGI_FORMAT ResourceFormat;
        int ResourceIndex;
        bool ResourceFormatNotEqual;

        constexpr Model(
            int stride,
            int vscWidth,
            int pscWidth,
            DXGI_FORMAT resourceFormat = DXGI_FORMAT_UNKNOWN,
            int resourceIndex = -1,
            bool resourceFormatNotEqual = false)
            : Stride(stride),
              VscWidth(vscWidth),
              PscWidth(pscWidth),
              ResourceFormat(resourceFormat),
              ResourceIndex(resourceIndex),
              ResourceFormatNotEqual(resourceFormatNotEqual)
        {
        }

        constexpr bool MatchesBasicMetadata(
            std::uint32_t stride,
            std::uint32_t vscWidth,
            std::uint32_t pscWidth) const
        {
            return (Stride < 0 || stride == static_cast<std::uint32_t>(Stride)) &&
                   (VscWidth < 0 || vscWidth == static_cast<std::uint32_t>(VscWidth)) &&
                   (PscWidth < 0 || pscWidth == static_cast<std::uint32_t>(PscWidth));
        }
    };

    // Historical metadata only. Resource-format matching needs a DX12-specific
    // descriptor/root-signature implementation before these values are useful.
    inline constexpr Model Skin1(8, 75, 4, static_cast<DXGI_FORMAT>(83), 2);
    inline constexpr Model Skin2(8, 75, 4, static_cast<DXGI_FORMAT>(77), 2);
    inline constexpr Model Body1(8, 75, 12, static_cast<DXGI_FORMAT>(39), 1, true);
    inline constexpr Model Body2(8, 75, 14, static_cast<DXGI_FORMAT>(39), 0, true);

    inline constexpr Model DroneWorldOverlay(8, 49, 3);
    inline constexpr Model WorldOverlay1(8, 49, 4);
    inline constexpr Model WorldOverlay2(8, 49, 12);
    inline constexpr Model WorldOverlay3(8, 49, 14);
    inline constexpr Model WorldOverlay4(8, 49, 49);
    inline constexpr Model Scope(8, 49, 49, static_cast<DXGI_FORMAT>(77), 2);
}
