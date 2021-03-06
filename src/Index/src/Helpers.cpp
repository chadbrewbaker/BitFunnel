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

#include "BitFunnel/Index/Helpers.h"
#include "BitFunnel/Index/ITermTable.h"
#include "BitFunnel/Index/Row.h"
#include "Rounding.h"
#include "Shard.h"


namespace BitFunnel
{
    size_t GetMinimumBlockSize(IDocumentDataSchema const & schema,
                               ITermTable const & termTable)
    {
        const DocIndex capacity =
            Row::DocumentsInRank0Row(1, termTable.GetMaxRankUsed());

        return Shard::InitializeDescriptors(nullptr,
                                            capacity,
                                            schema,
                                            termTable);
    }


    // TODO: this should actually be much larger when the corpus is much larger
    // for performance reasons.
    size_t GetReasonableBlockSize(IDocumentDataSchema const & schema,
                                  ITermTable const & termTable)
    {
        size_t minimumFunctionalSize = GetMinimumBlockSize(schema, termTable);
        size_t cachelineSize = c_bytesPerCacheLine * c_bitsPerByte;
        return RoundUp<size_t>(minimumFunctionalSize, cachelineSize);
    }
}
