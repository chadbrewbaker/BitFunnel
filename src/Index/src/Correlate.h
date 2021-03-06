// The MIT License (MIT)

// Copyright (c) 2016, Microsoft

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include <array>                                // std::arrray embedded.
#include <iosfwd>                               // std::ostream paramter.
#include <vector>                               // std::vector embedded.

#include "BitFunnel/BitFunnelTypes.h"           // DocId embedded.
#include "BitFunnel/Utilities/Accumulator.h"    // Accumulator embedded.


namespace BitFunnel
{
    class IFileManager;
    class ISimpleIndex;
    class ITermToText;

    class Correlate
    {
    public:
        Correlate (ISimpleIndex const & index,
                   std::vector<std::string> const & terms);
        void CorrelateRows(char const * outDir) const;

    private:
        void CorrelateShard(
            ShardId const & shardId,
            ITermToText const & termToText,
            std::ostream& out) const;

        ISimpleIndex const & m_index;
        std::vector<std::string> const & m_terms;
    };
}
