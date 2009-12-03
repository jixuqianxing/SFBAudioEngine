/*
 *  Copyright (C) 2006, 2007, 2008, 2009 Stephen F. Booth <me@sbooth.org>
 *  All Rights Reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *    - Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    - Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    - Neither the name of Stephen F. Booth nor the names of its 
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <AudioToolbox/ExtendedAudioFile.h>
#include "AudioDecoder.h"


// ========================================
// An AudioDecoder subclass supporting all formats handled by Core Audio
// ========================================
class CoreAudioDecoder : public AudioDecoder
{
	
public:
	
	// ========================================
	// The data types handled by this class
	static bool HandlesFilesWithExtension(CFStringRef extension);
	static bool HandlesMIMEType(CFStringRef mimeType);

	// ========================================
	// Creation
	CoreAudioDecoder(CFURLRef url);
	
	// ========================================
	// Destruction
	virtual ~CoreAudioDecoder();

	// ========================================
	// Attempt to read frameCount frames of audio, returning the actual number of frames read
	virtual UInt32 ReadAudio(AudioBufferList *bufferList, UInt32 frameCount);
	
	// ========================================
	// Source audio information
	virtual SInt64 GetTotalFrames();
	virtual SInt64 GetCurrentFrame();
	
	// ========================================
	// Seeking support
	virtual inline bool SupportsSeeking()					{ return true; }
	virtual SInt64 SeekToFrame(SInt64 frame);
	
private:
	
	ExtAudioFileRef mExtAudioFile;
	
};
