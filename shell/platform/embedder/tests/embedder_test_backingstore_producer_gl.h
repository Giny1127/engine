// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_EMBEDDER_TESTS_EMBEDDER_TEST_BACKINGSTORE_PRODUCER_GL_H_
#define FLUTTER_SHELL_PLATFORM_EMBEDDER_TESTS_EMBEDDER_TEST_BACKINGSTORE_PRODUCER_GL_H_

#include "flutter/shell/platform/embedder/tests/embedder_test_backingstore_producer.h"

#include <memory>

#include "flutter/testing/test_gl_surface.h"

namespace flutter::testing {

class EmbedderTestBackingStoreProducerGL
    : public EmbedderTestBackingStoreProducer {
 public:
  EmbedderTestBackingStoreProducerGL(
      sk_sp<GrDirectContext> context,
      RenderTargetType type,
      std::shared_ptr<TestEGLContext> egl_context);

  virtual ~EmbedderTestBackingStoreProducerGL();

  virtual bool Create(const FlutterBackingStoreConfig* config,
                      FlutterBackingStore* backing_store_out);

 private:
  bool CreateFramebuffer(const FlutterBackingStoreConfig* config,
                         FlutterBackingStore* renderer_out);

  bool CreateTexture(const FlutterBackingStoreConfig* config,
                     FlutterBackingStore* renderer_out);

  bool CreateSurface(const FlutterBackingStoreConfig* config,
                     FlutterBackingStore* renderer_out);

  std::shared_ptr<TestEGLContext> test_egl_context_;

  FML_DISALLOW_COPY_AND_ASSIGN(EmbedderTestBackingStoreProducerGL);
};

}  // namespace flutter::testing

#endif  // FLUTTER_SHELL_PLATFORM_EMBEDDER_TESTS_EMBEDDER_TEST_BACKINGSTORE_PRODUCER_GL_H_