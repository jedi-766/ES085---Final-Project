#include <stdio.h>
#include <math.h>

// functions for kinematics
double v_final(double u, double a, double t) {
	return u + a*t;
}

double calc_s(double u, double a, double t) {
	return u*t + 0.5*a*t*t;
}

// forces
double calc_F(double m, double a) {
	return m*a;
}

double calc_weight(double m) {
	return m * 9.8;  // g = 9.8 m/s^2
}

// work & energy
double calc_work(double F, double d) {
	return F * d;
}

double calc_KE(double m, double v) {
	return 0.5 * m * v * v;
}

// momentum
double calc_p(double m, double v) {
	return m * v;
}

// elastic collision (1D, same mass -> just swap velocities)
void collide(double v1, double v2, double *vf1, double *vf2) {
	*vf1 = v2;
	*vf2 = v1;
}

// circular motion
double calc_Fc(double m, double v, double r) {
	return (m * v * v) / r;
}

double calc_ac(double v, double r) {
	return (v * v) / r;
}
// main

void kinematics() {
	int ch;
	printf("\n--- Kinematics ---\n");
	printf("1. v = u + at\n");
	printf("2. s = ut + 0.5at^2\n");
	printf("Choice: ");
	scanf("%d", &ch);

	if (ch == 1) {
		double u, a, t;
		printf("u (m/s): "); scanf("%lf", &u);
		printf("a (m/s^2): "); scanf("%lf", &a);
		printf("t (s): "); scanf("%lf", &t);
		if (t < 0) {
			printf("Time can't be negative!\n");
		} else {
			printf("v = %.2f m/s\n", v_final(u, a, t));
		}
	}
	else if (ch == 2) {
		double u, a, t;
		printf("u: "); scanf("%lf", &u);
		printf("a: "); scanf("%lf", &a);
		printf("t: "); scanf("%lf", &t);
		if (t < 0) {
			printf("t must be >= 0\n");
		} else {
			printf("s = %.2f m\n", calc_s(u, a, t));
		}
	}
	else {
		printf("invalid\n");
	}
}

void forces() {
	int ch;
	printf("\n--- Forces ---\n");
	printf("1. F = ma\n");
	printf("2. W = mg\n");
	printf("Choice: ");
	scanf("%d", &ch);

	if (ch == 1) {
		double m, a;
		printf("m (kg): "); scanf("%lf", &m);
		printf("a (m/s^2): "); scanf("%lf", &a);
		if (m < 0) printf("mass can't be negative!\n");
		else printf("F = %.2f N\n", calc_F(m, a));
	}
	else if (ch == 2) {
		double m;
		printf("m (kg): "); scanf("%lf", &m);
		if (m < 0) printf("mass can't be negative!\n");
		else printf("W = %.2f N\n", calc_weight(m));
	}
	else {
		printf("wrong choice\n");
	}
}

void work_energy() {
	int ch;
	printf("\n--- Work / Energy ---\n");
	printf("1. Work = F * d\n");
	printf("2. KE = 0.5*m*v^2\n");
	printf("Choice: ");
	scanf("%d", &ch);

	if (ch == 1) {
		double F, d;
		printf("F (N): "); scanf("%lf", &F);
		printf("d (m): "); scanf("%lf", &d);
		printf("Work = %.2f J\n", calc_work(F, d));
	}
	else if (ch == 2) {
		double m, v;
		printf("m (kg): "); scanf("%lf", &m);
		printf("v (m/s): "); scanf("%lf", &v);
		if (m < 0 || v < 0) {
			printf("m and v must be positive!\n");
		} else {
			printf("KE = %.2f J\n", calc_KE(m, v));
		}
	}
	else {
		printf("huh?\n");
	}
}

void momentum() {
	int ch;
	printf("\n--- Momentum ---\n");
	printf("1. p = m*v\n");
	printf("2. Elastic collision (equal mass)\n");
	printf("Choice: ");
	scanf("%d", &ch);

	if (ch == 1) {
		double m, v;
		printf("m: "); scanf("%lf", &m);
		printf("v: "); scanf("%lf", &v);
		printf("p = %.2f kg*m/s\n", calc_p(m, v));
	}
	else if (ch == 2) {
		double v1, v2, vf1, vf2;
		printf("v1 initial: "); scanf("%lf", &v1);
		printf("v2 initial: "); scanf("%lf", &v2);
		collide(v1, v2, &vf1, &vf2);
		printf("After collision:\n");
		printf("v1 final = %.2f\n", vf1);
		printf("v2 final = %.2f\n", vf2);
	}
	else {
		printf("nope\n");
	}
}

void universal_gravitation() {
	int ch;
	printf("\n--- Universal Gravitation ---\n");
	printf("1. Fc = mv^2 / r\n");
	printf("2. ac = v^2 / r\n");
	printf("Choice: ");
	scanf("%d", &ch);

	if (ch == 1) {
		double m, v, r;
		printf("m (kg): "); scanf("%lf", &m);
		printf("v (m/s): "); scanf("%lf", &v);
		printf("r (m): "); scanf("%lf", &r);
		if (r <= 0) {
			printf("r must be > 0!\n");
		} else {
			printf("Fc = %.2f N\n", calc_Fc(m, v, r));
		}
	}
	else if (ch == 2) {
		double v, r;
		printf("v: "); scanf("%lf", &v);
		printf("r: "); scanf("%lf", &r);
		if (r <= 0) {
			printf("r > 0 plz\n");
		} else {
			printf("ac = %.2f m/s^2\n", calc_ac(v, r));
		}
	}
	else {
		printf("try again\n");
	}
}

// finally, main()
int main() {
	int option;

	printf("================================\n");
	printf("  Physics Calculator \n");
	printf("================================\n");
	printf("Made by: Jed Ivan\n");
	printf("Electrical Engineering Student");
	printf("Course: ES035 - Computer Programming 2\n\n");

	do {
		printf("\n--- MAIN MENU ---\n");
		printf("1. Kinematics\n");
		printf("2. Forces\n");
		printf("3. Work/Energy\n");
		printf("4. Momentum\n");
		printf("5. Universal Gravitation\n");
		printf("6. EXIT\n");
		printf("Choose: ");
		scanf("%d", &option);

		switch(option) {
			case 1: kinematics(); break;
			case 2: forces(); break;
			case 3: work_energy(); break;
			case 4: momentum(); break;
			case 5: universal_gravitation(); break;
			case 6:
				printf("\nThanks for using! :)\n");
				break;
			default:
				printf("Please enter 1-6 only.\n");
		}

	} while (option != 6);

	return 0;
}
