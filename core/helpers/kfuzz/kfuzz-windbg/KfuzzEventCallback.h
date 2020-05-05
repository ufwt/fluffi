/*
Copyright 2017-2019 Siemens AG

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Author(s): Thomas Riedmaier
*/

#pragma once
namespace Debugger::DataModel::Libraries::Kfuzz
{
	// KfuzzEventCallback:
	//
	// A class to handle Events sent by the debugging engine
	class KfuzzPublisher;
	class KfuzzEventCallback : public  DebugBaseEventCallbacks
	{
	public:
		KfuzzEventCallback(KfuzzPublisher * publisher);
		virtual ~KfuzzEventCallback();

		ULONG STDMETHODCALLTYPE AddRef(void);
		ULONG STDMETHODCALLTYPE Release(void);
		HRESULT STDMETHODCALLTYPE GetInterestMask(PULONG Mask);

		HRESULT STDMETHODCALLTYPE Exception(PEXCEPTION_RECORD64 Exception, ULONG FirstChance);
		HRESULT STDMETHODCALLTYPE ExitProcess(ULONG ExitCode);

	private:
		volatile ULONG m_cRef;

		std::vector<uint64_t> m_breakpointfunctions;
		KfuzzPublisher * m_publisher;
	};
}
