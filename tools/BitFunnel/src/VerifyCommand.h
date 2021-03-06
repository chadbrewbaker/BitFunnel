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

#include <string>       // std::string embedded.

#include "TaskBase.h"   // TaskBase base class.


namespace BitFunnel
{
    class Verify : public TaskBase
    {
    public:
        Verify(Environment & environment,
               Id id,
               char const * parameters);

        virtual void Execute() override;
        static ICommand::Documentation GetDocumentation();

    private:
        // m_isSingleQuery means to run one query. Otherwise, a log of queries
        // is expected.
        bool m_isSingleQuery;
        // m_isOutput means output results without verification. Otherwise, the
        // verifier gets run.
        bool m_isOutput;
        std::string m_query;
    };
}
