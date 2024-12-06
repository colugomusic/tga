// Aseprite TGA Library
// Copyright (C) 2020-2021  Igara Studio S.A.
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#include "tga.h"

#include <cassert>
#include <limits>

namespace tga {

ReadOnlyMemoryFileInterface::ReadOnlyMemoryFileInterface(std::span<const std::byte> bytes)
  : m_bytes(bytes)
  , m_pos(0)
  , m_ok(true)
{
}

bool ReadOnlyMemoryFileInterface::ok() const
{
  return m_ok;
}

size_t ReadOnlyMemoryFileInterface::tell()
{
  return m_pos;
}

void ReadOnlyMemoryFileInterface::seek(size_t absPos)
{
  // To detect surprises with the size_t -> long cast.
  assert(absPos < m_bytes.size());
  m_pos = absPos;
}

uint8_t ReadOnlyMemoryFileInterface::read8()
{
  if (m_pos >= m_bytes.size()) {
    return 0;
  }
  const auto value = m_bytes[m_pos++];
  if (m_pos >= m_bytes.size()) {
    m_ok = false;
  }
  return (uint8_t)(value);
}

void ReadOnlyMemoryFileInterface::write8(uint8_t value)
{
}

} // namespace tga
