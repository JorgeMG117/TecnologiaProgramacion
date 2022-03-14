class Complex implements Comparable<Complex>
{
	public double re;
	public double im;

	public Complex(double re) {
		this.re = re;
		this.im = 0;
	}
	public Complex(double re, double im) {
		this.re = re;
		this.im = im;
	}

	public static final Complex ZERO = new Complex(0, 0);
	public static final Complex ONE = new Complex(1, 0);
	public static final Complex I = new Complex(0, 1);

	public Complex add(Complex c) {
		return new Complex(re+c.re,im+c.im);
	}

	public Complex sub(Complex c) {
		return new Complex(re-c.re,im-c.im);
	}

	public Complex mul(Complex c) {
		return new Complex(re*c.re-im*c.im,re*c.im+im*c.re);
	}

	public Complex div(Complex c) {
		double tmp = c.re*c.re + c.im*c.im;
		return new Complex((re*c.re+im*c.im)/tmp,(im*c.re-re*c.im)/tmp);
	}

	public double abs() {
		return Math.sqrt(re*re + im*im);
	}

	@Override
	public int compareTo(Complex that) {
		double tm = this.abs();
		double cm = that.abs();
		if (tm<cm) return -1;
		if (tm>cm) return  1;
		return 0;
	}

	@Override
	public String toString() {
		return "(" + re + "," + im + ")";
	}
}
