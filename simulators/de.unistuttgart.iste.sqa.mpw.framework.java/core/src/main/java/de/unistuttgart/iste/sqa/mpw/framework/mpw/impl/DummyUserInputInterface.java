package de.unistuttgart.iste.sqa.mpw.framework.mpw.impl;

import de.unistuttgart.iste.sqa.mpw.framework.mpw.UserInputInterface;

public class DummyUserInputInterface implements UserInputInterface {

	@Override
	public int readInteger(final String message) {
		throw new RuntimeException("Dummy IO interface does not support reading values");
	}

	@Override
	public String readString(final String message) {
		throw new RuntimeException("Dummy IO interface does not support reading values");
	}

	@Override
	public void confirmAlert(final Throwable t) {
		if (t instanceof RuntimeException) {
			throw (RuntimeException)t;
		}
		throw new RuntimeException(t);
	}

	@Override
	public void abort() {
		throw new RuntimeException("Dummy IO interface does not support aborting");
	}

}
