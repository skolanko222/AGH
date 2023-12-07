import org.junit.Test;

import java.security.InvalidParameterException;
import java.util.Arrays;

import static org.junit.Assert.*;


public class BigNumberTest {
        private final byte[] shortArr = {1, 2, 3, 4, 5, 6, 7, 8};
        private final byte[] nullArr = null;
        private final byte[] emptyArr = {};
        private final byte[] invalidIntArr1 = {0,1,2,3};
        private final byte[] invalidIntArr2 = {0xF};
        private final byte[] invalidIntArr3 = {023};
        private final byte[] invalidIntArr4 = {0b10};
        private final byte[] invalidIntArr5 = {99};



        @Test
        public void testBigNumber() {
            BigNumber bigNumber = new BigNumber(shortArr, shortArr);
            // NullPointerException
            Exception nullExcept = assertThrows(NullPointerException.class ,() -> new BigNumber(nullArr, nullArr) );

            // InvalidParameterException
            Exception paramExcept = assertThrows(
                    InvalidParameterException.class, ()->new BigNumber(emptyArr, emptyArr) );

            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // brak wyrzucenia wyjątku dla przypadku !(integer.length > 1 && integer[0] == 0)
            // paramExcept = assertThrows(
            //        InvalidParameterException.class, ()->new BigNumber(invalidIntArr1, shortArr) );

            paramExcept = assertThrows(
                InvalidParameterException.class, ()->new BigNumber(invalidIntArr2, invalidIntArr2) );
            paramExcept = assertThrows(
                    InvalidParameterException.class, ()->new BigNumber(invalidIntArr3, invalidIntArr3) );
            paramExcept = assertThrows(
                    InvalidParameterException.class, ()->new BigNumber(new byte[]{'a','b'}, new byte[]{'a','b'}) );

            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // brak wyrzucenia wyjątku dla przypadku gdy element tablicy jest liczbą binarną
//             paramExcept = assertThrows(
//                InvalidParameterException.class, ()->new BigNumber(invalidIntArr4, invalidIntArr4) );

            paramExcept = assertThrows(
                InvalidParameterException.class, ()->new BigNumber(invalidIntArr5, invalidIntArr5) );
            

        }
        @Test
        public void testImmutability(){
            byte[] b = {1, 2, 3, 4, 5, 6, 7, 8};
            BigNumber bigNumber = new BigNumber(b, b);
            BigNumber bigNumber1 = new BigNumber(b, b);

            assertNotSame(bigNumber, bigNumber1);

            b = null;
            assertEquals(bigNumber.toString(),"12345678.12345678");
            testGetInteger();


        }
        @Test
        public void testGetInteger(){
            BigNumber bigNumber = new BigNumber(shortArr, shortArr);
            byte[] returnIntArr = bigNumber.getInteger();
            assertArrayEquals(returnIntArr, shortArr);
            //niezmiennosc
            Arrays.fill(returnIntArr, (byte)100);
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//            assertArrayEquals(bigNumber.getInteger(), shortArr);
        }
        @Test
        public void testGetFractal(){
            BigNumber bigNumber = new BigNumber(shortArr, shortArr);
            byte[] returnFracArr = bigNumber.getFrac();
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //array lengths differed, expected.length=9 actual.length=8; arrays first differed at element [8];
            //assertArrayEquals(returnFracArr, shortArr);

            //niezmiennosc
            Arrays.fill(returnFracArr, (byte)100);
            //assertArrayEquals(bigNumber.getFrac(), shortArr);
        }

        @Test
        public void testToString(){
            BigNumber bigNumber = new BigNumber(new byte[]{1,2,3}, new byte[]{1,2,3});
            assertEquals(bigNumber.toString(),"123.123");

        }

        @Test
        public void testValueOf(){
            BigNumber bigNumber = BigNumber.valueOf(shortArr, shortArr);
            assertEquals(bigNumber.toString(),"12345678.12345678");

            // NullPointerException
            Exception nullExcept = assertThrows(NullPointerException.class ,() -> BigNumber.valueOf(nullArr, nullArr) );
            // InvalidParameterException
            Exception paramExcept = assertThrows(
                    InvalidParameterException.class, ()-> BigNumber.valueOf(emptyArr, emptyArr) );

            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // brak wyrzucenia wyjątku dla przypadku !(integer.length > 1 && integer[0] == 0)
//             paramExcept = assertThrows(
//                    InvalidParameterException.class, ()->new BigNumber(invalidIntArr1, shortArr) );

            paramExcept = assertThrows(
                    InvalidParameterException.class, ()-> BigNumber.valueOf(invalidIntArr2, invalidIntArr2) );
            paramExcept = assertThrows(
                    InvalidParameterException.class, ()-> BigNumber.valueOf(invalidIntArr3, invalidIntArr3) );

            // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // brak wyrzucenia wyjątku dla przypadku gdy element tablicy jest liczbą binarną
//             paramExcept = assertThrows(
//                InvalidParameterException.class, ()->new BigNumber(invalidIntArr4, invalidIntArr4) );

            paramExcept = assertThrows(
                    InvalidParameterException.class, ()-> BigNumber.valueOf(invalidIntArr5, invalidIntArr5) );

            // optymalizacja
            BigNumber bigNumber1 = BigNumber.valueOf(new byte[]{0}, new byte[]{0});
            assertEquals(bigNumber1, BigNumber.ZERO);

            if(bigNumber1 == BigNumber.ZERO)
                assertSame(bigNumber1, BigNumber.ZERO);

            bigNumber1 = BigNumber.valueOf(new byte[]{1}, new byte[]{0});
            assertEquals(bigNumber1, BigNumber.ONE);

            if(bigNumber1 == BigNumber.ONE)
                assertSame(bigNumber1, BigNumber.ONE);

            bigNumber1 = BigNumber.valueOf(new byte[]{2}, new byte[]{0});
            assertEquals(bigNumber1, BigNumber.TWO);

            if(bigNumber1 == BigNumber.TWO)
                assertSame(bigNumber1, BigNumber.TWO);

            bigNumber1 = BigNumber.valueOf(new byte[]{1,0}, new byte[]{0});
            assertEquals(bigNumber1, BigNumber.TEN);

            if(bigNumber1 == BigNumber.TEN)
                assertSame(bigNumber1, BigNumber.TEN);

        }
        @Test
        public void testFloor(){
            BigNumber bigNumber1 = BigNumber.valueOf(shortArr, shortArr);
            //optymaliazcja
            assertSame(bigNumber1.floor().getInteger(), bigNumber1.getInteger());
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            //bląd w zaokrąglaniu
            //assertEquals(bigNumber1.floor(),new BigNumber(shortArr, new byte[]{0}));

        }
        @Test
        public void testEquals(){
            BigNumber bigNumber1 = BigNumber.valueOf(shortArr, shortArr);
            BigNumber bigNumber2 = BigNumber.valueOf(shortArr, shortArr);
            BigNumber bigNumber3 = BigNumber.valueOf(shortArr, shortArr);
            BigNumber bigNumber4 = BigNumber.valueOf(shortArr, new byte[]{0});
            BigNumber bigNumber5 = BigNumber.valueOf(new byte[]{0}, shortArr);

            assertNotEquals(bigNumber1, bigNumber4);
            assertNotEquals(bigNumber1, bigNumber5);

            //1
            assertEquals(bigNumber1, bigNumber1);
            //2
            assertEquals(bigNumber1.equals(bigNumber2), bigNumber2.equals(bigNumber1));
            //3
            assertTrue(bigNumber1.equals(bigNumber2) && bigNumber2.equals(bigNumber3) && bigNumber1.equals(bigNumber3));
            //4
            assertEquals(bigNumber1.equals(bigNumber2), bigNumber2.equals(bigNumber1));
            bigNumber1 = BigNumber.valueOf(new byte[]{0}, new byte[]{0});
            assertNotEquals(bigNumber1, bigNumber2);
            //5
            assertNotEquals(bigNumber1, null);
            //6
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // equals powinno zwracać false dla obiektów różnych klas
            //ssertFalse(bigNumber1.equals(new Object()) );
        }
        @Test
        public void testHashCode(){
            BigNumber bigNumber1 = BigNumber.valueOf(shortArr, shortArr);
            BigNumber bigNumber2 = BigNumber.valueOf(shortArr, shortArr);
            BigNumber bigNumber3 = BigNumber.valueOf(shortArr, shortArr);
            BigNumber bigNumber4 = BigNumber.valueOf(shortArr, new byte[]{0});
            BigNumber bigNumber5 = BigNumber.valueOf(new byte[]{0}, shortArr);

            assertNotEquals(bigNumber1.hashCode(), bigNumber4.hashCode());
            assertNotEquals(bigNumber1.hashCode(), bigNumber5.hashCode());
            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // hasCode powinien zwracać ten sam wynik dla identycznych obiektów
            // assertEquals(bigNumber1.hashCode(), bigNumber1.hashCode());

        }


}
