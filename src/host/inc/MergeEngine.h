/**
 * ============================================================================
 *
 * Copyright (C) Huawei Technologies Co., Ltd. 2019. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1 Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   2 Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *   3 Neither the names of the copyright holders nor the names of the
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * ============================================================================
 */

#ifndef ATLASFACEDEMO_MERGEENGINE_H
#define ATLASFACEDEMO_MERGEENGINE_H
#include "stream_data.h"
#include <hiaiengine/api.h>
#define MERGE_ENGINE_INPUT_SIZE 1
#define MERGE_ENGINE_OUTPUT_SIZE 1
/*
 * Source Engine
 */
class MergeEngine : public hiai::Engine {
public:
    MergeEngine(){};

    ~MergeEngine(){};

    HIAI_StatusT Init(const hiai::AIConfig& config, const std::vector<hiai::AIModelDescription>& model_desc);

    /**
     * @ingroup SourceEngine
     * @brief SourceEngine Process 函数
     * @param [in]: SOURCE_ENGINE_INPUT_SIZE, Source Engine in端口
     * @param [in]: SOURCE_ENGINE_OUTPUT_SIZE, Source Engine out 端口
     * @param [out]: HIAI_StatusT
     */
    HIAI_DEFINE_PROCESS(MERGE_ENGINE_INPUT_SIZE, MERGE_ENGINE_OUTPUT_SIZE)
private:
    std::vector<std::shared_ptr<DeviceStreamData>> deviceStreamDataQueue;
    std::shared_ptr<DeviceStreamData> keyFrame;
};

#endif  // IMPL_ENGINE_H_
