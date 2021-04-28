// Copyright (c) 2021, NVIDIA CORPORATION. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#pragma once
#include "src/clients/c++/library/common.h"

class InferResultCApi : public nic::InferResult {
 public:  
  Error ModelName(std::string* name) const override;
  Error ModelVersion(std::string* version) const override;
  Error Id(std::string* id) const override;
  Error Shape(const std::string& output_name, std::vector<int64_t>* shape)
      const override;
  Error Datatype(
      const std::string& output_name, std::string* datatype) const override;
  Error RawData(
      const std::string& output_name, const uint8_t** buf,
      size_t* byte_size) const override;
  Error StringData(
      const std::string& output_name,
      std::vector<std::string>* string_result) const override;
  std::string DebugString() const override;
  Error RequestStatus() const override;

 private:
  InferResultCApi(std::shared_ptr<InferResultCApi> infer_request);

  std::map<std::string, triton::common::TritonJson::Value>
      output_name_to_result_map_;
  std::map<std::string, std::pair<const uint8_t*, const size_t>>
      output_name_to_buffer_map_;
std::string model_name_;
std::string model_version_;
std::string request_id_;
  nic::Error status_;
};


nic::Error
InferResultCApi::ModelName(std::string* name) const {
    *name =  model_name_;
    return nic::Status::Success;
}


nic::Error
InferResultCApi::ModelVersion(std::string* version) const{
    *version =  model_version_;
    return nic::Status::Success;
}

nic::Error
InferResultCApi::Id(std::string* id) const{
    *id =  request_id_;
    return nic::Status::Success;
}

nic::Error
InferResultCApi::Shape(
    const std::string& output_name, std::vector<int64_t>* shape) const{
        return nic::Status::Success;
    }

nic::Error
InferResultCApi::Datatype(
    const std::string& output_name, std::string* datatype) const{
        return nic::Status::Success;
    }

nic::Error
InferResultCApi::RawData(
    const std::string& output_name, const uint8_t** buf,
    size_t* byte_size) const
    {
        return nic::Status::Success;
    }

nic::Error
InferResultCApi::StringData(
    const std::string& output_name,
    std::vector<std::string>* string_result) const{
        return nic::Status::Success;
    }
std::string
InferResultCApi::DebugString() const{
    std::string err = "";
    return err;
}
nic::Error
InferResultCApi::RequestStatus() const{
    return status_;
}

InferResultCApi::InferResultCApi(
    std::shared_ptr<InferResultCApi> infer_request)
    : infer_request_(infer_request){}