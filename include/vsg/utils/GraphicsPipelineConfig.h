#pragma once

/* <editor-fold desc="MIT License">

Copyright(c) 2022 Robert Osfield

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

</editor-fold> */

#include <vsg/state/ColorBlendState.h>
#include <vsg/state/DepthStencilState.h>
#include <vsg/state/DescriptorBuffer.h>
#include <vsg/state/DescriptorImage.h>
#include <vsg/state/DescriptorSetLayout.h>
#include <vsg/state/GraphicsPipeline.h>
#include <vsg/state/InputAssemblyState.h>
#include <vsg/state/MultisampleState.h>
#include <vsg/state/RasterizationState.h>
#include <vsg/state/VertexInputState.h>

#include <vsg/utils/ShaderSet.h>

namespace vsg
{

    class VSG_DECLSPEC GraphicsPipelineConfig : public vsg::Inherit<Object, GraphicsPipelineConfig>
    {
    public:
        GraphicsPipelineConfig(ref_ptr<ShaderSet> in_shaderSet = {});

        // inputs to setup of GraphicsPipeline
        ref_ptr<VertexInputState> vertexInputState;
        ref_ptr<InputAssemblyState> inputAssemblyState;
        ref_ptr<RasterizationState> rasterizationState;
        ref_ptr<ColorBlendState> colorBlendState;
        ref_ptr<MultisampleState> multisampleState;
        ref_ptr<DepthStencilState> depthStencilState;
        uint32_t subpass = 0;
        uint32_t baseAttributeBinding = 0;
        ref_ptr<ShaderSet> shaderSet;
        ref_ptr<DescriptorSetLayout> additionalDescrptorSetLayout;

        void reset();

        bool enableArray(const std::string& name, VkVertexInputRate vertexInputRate, uint32_t stride);
        bool assignArray(DataList& arrays, const std::string& name, VkVertexInputRate vertexInputRate, ref_ptr<Data> array);
        bool assignTexture(Descriptors& descriptors, const std::string& name, ref_ptr<Data> textureData = {}, ref_ptr<Sampler> sampler = {});
        bool assignUniform(Descriptors& descriptors, const std::string& name, ref_ptr<Data> data = {});

        // setup by assign calls
        ref_ptr<ShaderCompileSettings> shaderHints;
        vsg::DescriptorSetLayoutBindings descriptorBindings;

        int compare(const Object& rhs) const;

        void init();

        // setup by init()
        ref_ptr<DescriptorSetLayout> descriptorSetLayout;
        ref_ptr<PipelineLayout> layout;
        ref_ptr<GraphicsPipeline> graphicsPipeline;
        ref_ptr<BindGraphicsPipeline> bindGraphicsPipeline;
    };
    VSG_type_name(vsg::GraphicsPipelineConfig);

} // namespace vsg
