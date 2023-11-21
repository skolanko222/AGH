import java.util.Objects;
public class Vector {
    private double x = 0.0;
    private double y = 0.0;
    private double z = 0.0;
    public static final Vector ZERO = new Vector();
    public static final Vector VERSOR_X = new Vector(1.0);
    public static final Vector VERSOR_Y = new Vector(0.0, 1.0);
    public static final Vector VERSOR_Z = new Vector(0.0, 0.0, 1.0);


    public Vector(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public Vector() {
    }

    public Vector(double x) {
        this.x = x;
    }

    public Vector(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public static Vector vectorOf(double x, double y, double z) {
        return new Vector(x, y, z);
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getZ() {
        return z;
    }

    public Vector add(Vector v2) {
        return new Vector(this.x + v2.x, this.y + v2.y, this.z + v2.z);
    }

    public Vector subtract(Vector v2) {
        return new Vector(this.x - v2.x, this.y - v2.y, this.z - v2.z);
    }

    public Vector multiply(double val) {
        return new Vector(this.x * val, this.y * val, this.z * val);
    }

    public static double dotProduct(Vector v1, Vector v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    public static Vector crossProduct(Vector v1, Vector v2) {
        Vector v3 = new Vector();
        double[] a = { v1.x, v1.y, v1.z };
        double[] b = { v2.x, v2.y, v2.z };
        v3.setX(a[1] * b[2] - a[2] * b[1]);
        v3.setY(a[2] * b[0] - a[0] * b[2]);
        v3.setZ(a[0] * b[1] - a[1] * b[0]);
        return v3;
    }

    public double length() {
        return Math.sqrt(Vector.dotProduct(this, this));
    }

    public void normalize() {
        double norm = this.length();
        this.setX(this.getX() / norm);
        this.setY(this.getY() / norm);
        this.setZ(this.getZ() / norm);
    }

    public void opposite() {
        this.setX(-this.getX());
        this.setY(-this.getY());
        this.setZ(-this.getZ());
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public void setZ(double z) {
        this.z = z;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Vector vector = (Vector) o;
        return Double.compare(x, vector.x) == 0 && Double.compare(y, vector.y) == 0 && Double.compare(z, vector.z) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y, z);
    }

    @Override
    public String toString() {
        return "[" + this.x + ", " + this.y + ", " + this.z + "]";
    }
}

}
