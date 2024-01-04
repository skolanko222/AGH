public enum Direction {
    UP(0, -1),
    DOWN(0, 1),
    LEFT(-1, 0),
    RIGHT(1, 0);

    final int xDir;
    final int yDir;

    Direction(int xDir, int yDir) {
        this.xDir = xDir;
        this.yDir = yDir;
    }
}
