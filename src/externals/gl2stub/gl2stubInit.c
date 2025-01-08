/*static*/ GLboolean gl2stubInit() {
  // We cannot call SDL_EGL_LoadLibrary, sicne SDL_GL_LoadLibrary will default to WIN_GL_LoadLibrary.
  // Therefore we partially reimplement it.

#ifdef _WIN32
  const char *d3dcompiler = SDL_GetHint(SDL_HINT_VIDEO_WIN_D3DCOMPILER);
  if (!d3dcompiler) {
    if (IsWindowsVistaOrGreater()) {
      d3dcompiler = "d3dcompiler_46.dll";
    } else {
      d3dcompiler = "d3dcompiler_43.dll";
    }
  }
  if (SDL_strcasecmp(d3dcompiler, "none") != 0) {
    if (SDL_LoadObject(d3dcompiler) == NULL) {
        SDL_ClearError();
    }
  }
#endif

  gles2handle = SDL_LoadObject(GL2STUB_GLES2_LIBRARY);

  #define FIND_PROC(s) s = SDL_LoadFunction(gles2handle, #s)
  FIND_PROC(glActiveTexture);
  FIND_PROC(glAttachShader);
  FIND_PROC(glBindAttribLocation);
  FIND_PROC(glBindBuffer);
  FIND_PROC(glBindFramebuffer);
  FIND_PROC(glBindRenderbuffer);
  FIND_PROC(glBindTexture);
  FIND_PROC(glBlendColor);
  FIND_PROC(glBlendEquation);
  FIND_PROC(glBlendEquationSeparate);
  FIND_PROC(glBlendFunc);
  FIND_PROC(glBlendFuncSeparate);
  FIND_PROC(glBufferData);
  FIND_PROC(glBufferSubData);
  FIND_PROC(glCheckFramebufferStatus);
  FIND_PROC(glClear);
  FIND_PROC(glClearColor);
  FIND_PROC(glClearDepthf);
  FIND_PROC(glClearStencil);
  FIND_PROC(glColorMask);
  FIND_PROC(glCompileShader);
  FIND_PROC(glCompressedTexImage2D);
  FIND_PROC(glCompressedTexSubImage2D);
  FIND_PROC(glCopyTexImage2D);
  FIND_PROC(glCopyTexSubImage2D);
  FIND_PROC(glCreateProgram);
  FIND_PROC(glCreateShader);
  FIND_PROC(glCullFace);
  FIND_PROC(glDeleteBuffers);
  FIND_PROC(glDeleteFramebuffers);
  FIND_PROC(glDeleteProgram);
  FIND_PROC(glDeleteRenderbuffers);
  FIND_PROC(glDeleteShader);
  FIND_PROC(glDeleteTextures);
  FIND_PROC(glDepthFunc);
  FIND_PROC(glDepthMask);
  FIND_PROC(glDepthRangef);
  FIND_PROC(glDetachShader);
  FIND_PROC(glDisable);
  FIND_PROC(glDisableVertexAttribArray);
  FIND_PROC(glDrawArrays);
  FIND_PROC(glDrawElements);
  FIND_PROC(glEnable);
  FIND_PROC(glEnableVertexAttribArray);
  FIND_PROC(glFinish);
  FIND_PROC(glFlush);
  FIND_PROC(glFramebufferRenderbuffer);
  FIND_PROC(glFramebufferTexture2D);
  FIND_PROC(glFrontFace);
  FIND_PROC(glGenBuffers);
  FIND_PROC(glGenerateMipmap);
  FIND_PROC(glGenFramebuffers);
  FIND_PROC(glGenRenderbuffers);
  FIND_PROC(glGenTextures);
  FIND_PROC(glGetActiveAttrib);
  FIND_PROC(glGetActiveUniform);
  FIND_PROC(glGetAttachedShaders);
  FIND_PROC(glGetAttribLocation);
  FIND_PROC(glGetBooleanv);
  FIND_PROC(glGetBufferParameteriv);
  FIND_PROC(glGetError);
  FIND_PROC(glGetFloatv);
  FIND_PROC(glGetFramebufferAttachmentParameteriv);
  FIND_PROC(glGetIntegerv);
  FIND_PROC(glGetProgramiv);
  FIND_PROC(glGetProgramInfoLog);
  FIND_PROC(glGetRenderbufferParameteriv);
  FIND_PROC(glGetShaderiv);
  FIND_PROC(glGetShaderInfoLog);
  FIND_PROC(glGetShaderPrecisionFormat);
  FIND_PROC(glGetShaderSource);
  FIND_PROC(glGetString);
  FIND_PROC(glGetTexParameterfv);
  FIND_PROC(glGetTexParameteriv);
  FIND_PROC(glGetUniformfv);
  FIND_PROC(glGetUniformiv);
  FIND_PROC(glGetUniformLocation);
  FIND_PROC(glGetVertexAttribfv);
  FIND_PROC(glGetVertexAttribiv);
  FIND_PROC(glGetVertexAttribPointerv);
  FIND_PROC(glHint);
  FIND_PROC(glIsBuffer);
  FIND_PROC(glIsEnabled);
  FIND_PROC(glIsFramebuffer);
  FIND_PROC(glIsProgram);
  FIND_PROC(glIsRenderbuffer);
  FIND_PROC(glIsShader);
  FIND_PROC(glIsTexture);
  FIND_PROC(glLineWidth);
  FIND_PROC(glLinkProgram);
  FIND_PROC(glPixelStorei);
  FIND_PROC(glPolygonOffset);
  FIND_PROC(glReadPixels);
  FIND_PROC(glReleaseShaderCompiler);
  FIND_PROC(glRenderbufferStorage);
  FIND_PROC(glSampleCoverage);
  FIND_PROC(glScissor);
  FIND_PROC(glShaderBinary);
  FIND_PROC(glShaderSource);
  FIND_PROC(glStencilFunc);
  FIND_PROC(glStencilFuncSeparate);
  FIND_PROC(glStencilMask);
  FIND_PROC(glStencilMaskSeparate);
  FIND_PROC(glStencilOp);
  FIND_PROC(glStencilOpSeparate);
  FIND_PROC(glTexImage2D);
  FIND_PROC(glTexParameterf);
  FIND_PROC(glTexParameterfv);
  FIND_PROC(glTexParameteri);
  FIND_PROC(glTexParameteriv);
  FIND_PROC(glTexSubImage2D);
  FIND_PROC(glUniform1f);
  FIND_PROC(glUniform1fv);
  FIND_PROC(glUniform1i);
  FIND_PROC(glUniform1iv);
  FIND_PROC(glUniform2f);
  FIND_PROC(glUniform2fv);
  FIND_PROC(glUniform2i);
  FIND_PROC(glUniform2iv);
  FIND_PROC(glUniform3f);
  FIND_PROC(glUniform3fv);
  FIND_PROC(glUniform3i);
  FIND_PROC(glUniform3iv);
  FIND_PROC(glUniform4f);
  FIND_PROC(glUniform4fv);
  FIND_PROC(glUniform4i);
  FIND_PROC(glUniform4iv);
  FIND_PROC(glUniformMatrix2fv);
  FIND_PROC(glUniformMatrix3fv);
  FIND_PROC(glUniformMatrix4fv);
  FIND_PROC(glUseProgram);
  FIND_PROC(glValidateProgram);
  FIND_PROC(glVertexAttrib1f);
  FIND_PROC(glVertexAttrib1fv);
  FIND_PROC(glVertexAttrib2f);
  FIND_PROC(glVertexAttrib2fv);
  FIND_PROC(glVertexAttrib3f);
  FIND_PROC(glVertexAttrib3fv);
  FIND_PROC(glVertexAttrib4f);
  FIND_PROC(glVertexAttrib4fv);
  FIND_PROC(glVertexAttribPointer);
  FIND_PROC(glViewport);  
  #undef FIND_PROC

  if (!glActiveTexture ||
      !glAttachShader ||
      !glBindAttribLocation ||
      !glBindBuffer ||
      !glBindFramebuffer ||
      !glBindRenderbuffer ||
      !glBindTexture ||
      !glBlendColor ||
      !glBlendEquation ||
      !glBlendEquationSeparate ||
      !glBlendFunc ||
      !glBlendFuncSeparate ||
      !glBufferData ||
      !glBufferSubData ||
      !glCheckFramebufferStatus ||
      !glClear ||
      !glClearColor ||
      !glClearDepthf ||
      !glClearStencil ||
      !glColorMask ||
      !glCompileShader ||
      !glCompressedTexImage2D ||
      !glCompressedTexSubImage2D ||
      !glCopyTexImage2D ||
      !glCopyTexSubImage2D ||
      !glCreateProgram ||
      !glCreateShader ||
      !glCullFace ||
      !glDeleteBuffers ||
      !glDeleteFramebuffers ||
      !glDeleteProgram ||
      !glDeleteRenderbuffers ||
      !glDeleteShader ||
      !glDeleteTextures ||
      !glDepthFunc ||
      !glDepthMask ||
      !glDepthRangef ||
      !glDetachShader ||
      !glDisable ||
      !glDisableVertexAttribArray ||
      !glDrawArrays ||
      !glDrawElements ||
      !glEnable ||
      !glEnableVertexAttribArray ||
      !glFinish ||
      !glFlush ||
      !glFramebufferRenderbuffer ||
      !glFramebufferTexture2D ||
      !glFrontFace ||
      !glGenBuffers ||
      !glGenerateMipmap ||
      !glGenFramebuffers ||
      !glGenRenderbuffers ||
      !glGenTextures ||
      !glGetActiveAttrib ||
      !glGetActiveUniform ||
      !glGetAttachedShaders ||
      !glGetAttribLocation ||
      !glGetBooleanv ||
      !glGetBufferParameteriv ||
      !glGetError ||
      !glGetFloatv ||
      !glGetFramebufferAttachmentParameteriv ||
      !glGetIntegerv ||
      !glGetProgramiv ||
      !glGetProgramInfoLog ||
      !glGetRenderbufferParameteriv ||
      !glGetShaderiv ||
      !glGetShaderInfoLog ||
      !glGetShaderPrecisionFormat ||
      !glGetShaderSource ||
      !glGetString ||
      !glGetTexParameterfv ||
      !glGetTexParameteriv ||
      !glGetUniformfv ||
      !glGetUniformiv ||
      !glGetUniformLocation ||
      !glGetVertexAttribfv ||
      !glGetVertexAttribiv ||
      !glGetVertexAttribPointerv ||
      !glHint ||
      !glIsBuffer ||
      !glIsEnabled ||
      !glIsFramebuffer ||
      !glIsProgram ||
      !glIsRenderbuffer ||
      !glIsShader ||
      !glIsTexture ||
      !glLineWidth ||
      !glLinkProgram ||
      !glPixelStorei ||
      !glPolygonOffset ||
      !glReadPixels ||
      !glReleaseShaderCompiler ||
      !glRenderbufferStorage ||
      !glSampleCoverage ||
      !glScissor ||
      !glShaderBinary ||
      !glShaderSource ||
      !glStencilFunc ||
      !glStencilFuncSeparate ||
      !glStencilMask ||
      !glStencilMaskSeparate ||
      !glStencilOp ||
      !glStencilOpSeparate ||
      !glTexImage2D ||
      !glTexParameterf ||
      !glTexParameterfv ||
      !glTexParameteri ||
      !glTexParameteriv ||
      !glTexSubImage2D ||
      !glUniform1f ||
      !glUniform1fv ||
      !glUniform1i ||
      !glUniform1iv ||
      !glUniform2f ||
      !glUniform2fv ||
      !glUniform2i ||
      !glUniform2iv ||
      !glUniform3f ||
      !glUniform3fv ||
      !glUniform3i ||
      !glUniform3iv ||
      !glUniform4f ||
      !glUniform4fv ||
      !glUniform4i ||
      !glUniform4iv ||
      !glUniformMatrix2fv ||
      !glUniformMatrix3fv ||
      !glUniformMatrix4fv ||
      !glUseProgram ||
      !glValidateProgram ||
      !glVertexAttrib1f ||
      !glVertexAttrib1fv ||
      !glVertexAttrib2f ||
      !glVertexAttrib2fv ||
      !glVertexAttrib3f ||
      !glVertexAttrib3fv ||
      !glVertexAttrib4f ||
      !glVertexAttrib4fv ||
      !glVertexAttribPointer ||
      !glViewport)
  {
    return GL_FALSE;
  }

  return GL_TRUE;
}
