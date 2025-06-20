PGDMP  :                    }           Library    17.4    17.4     �           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                           false            �           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                           false            �           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                           false            �           1262    16388    Library    DATABASE     o   CREATE DATABASE "Library" WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'pl-PL';
    DROP DATABASE "Library";
                     postgres    false            �           0    0    DATABASE "Library"    COMMENT     O   COMMENT ON DATABASE "Library" IS 'DB do zarządzania systemem bibliotecznym.';
                        postgres    false    4822                        2615    2200    public    SCHEMA        CREATE SCHEMA public;
    DROP SCHEMA public;
                     pg_database_owner    false            �           0    0    SCHEMA public    COMMENT     6   COMMENT ON SCHEMA public IS 'standard public schema';
                        pg_database_owner    false    4            �            1259    16399    books    TABLE     �   CREATE TABLE public.books (
    id integer NOT NULL,
    title character varying(100),
    author character varying(100),
    publisher character varying(100),
    publish_date date,
    available boolean DEFAULT true
);
    DROP TABLE public.books;
       public         heap r       postgres    false    4            �            1259    16398    books_id_seq    SEQUENCE     �   CREATE SEQUENCE public.books_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 #   DROP SEQUENCE public.books_id_seq;
       public               postgres    false    220    4            �           0    0    books_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.books_id_seq OWNED BY public.books.id;
          public               postgres    false    219            �            1259    16390    clients    TABLE     �   CREATE TABLE public.clients (
    id integer NOT NULL,
    first_name character varying(50),
    last_name character varying(50),
    birth_date date,
    email character varying(100),
    phone character varying(20)
);
    DROP TABLE public.clients;
       public         heap r       postgres    false    4            �            1259    16389    clients_id_seq    SEQUENCE     �   CREATE SEQUENCE public.clients_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.clients_id_seq;
       public               postgres    false    218    4            �           0    0    clients_id_seq    SEQUENCE OWNED BY     A   ALTER SEQUENCE public.clients_id_seq OWNED BY public.clients.id;
          public               postgres    false    217            �            1259    16407    loans    TABLE     �   CREATE TABLE public.loans (
    id integer NOT NULL,
    client_id integer,
    book_id integer,
    loan_date date NOT NULL,
    return_date date,
    returned boolean DEFAULT false
);
    DROP TABLE public.loans;
       public         heap r       postgres    false    4            �            1259    16406    loans_id_seq    SEQUENCE     �   CREATE SEQUENCE public.loans_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 #   DROP SEQUENCE public.loans_id_seq;
       public               postgres    false    4    222            �           0    0    loans_id_seq    SEQUENCE OWNED BY     =   ALTER SEQUENCE public.loans_id_seq OWNED BY public.loans.id;
          public               postgres    false    221            ,           2604    16402    books id    DEFAULT     d   ALTER TABLE ONLY public.books ALTER COLUMN id SET DEFAULT nextval('public.books_id_seq'::regclass);
 7   ALTER TABLE public.books ALTER COLUMN id DROP DEFAULT;
       public               postgres    false    220    219    220            +           2604    16393 
   clients id    DEFAULT     h   ALTER TABLE ONLY public.clients ALTER COLUMN id SET DEFAULT nextval('public.clients_id_seq'::regclass);
 9   ALTER TABLE public.clients ALTER COLUMN id DROP DEFAULT;
       public               postgres    false    217    218    218            .           2604    16410    loans id    DEFAULT     d   ALTER TABLE ONLY public.loans ALTER COLUMN id SET DEFAULT nextval('public.loans_id_seq'::regclass);
 7   ALTER TABLE public.loans ALTER COLUMN id DROP DEFAULT;
       public               postgres    false    221    222    222            �          0    16399    books 
   TABLE DATA           V   COPY public.books (id, title, author, publisher, publish_date, available) FROM stdin;
    public               postgres    false    220   �        �          0    16390    clients 
   TABLE DATA           V   COPY public.clients (id, first_name, last_name, birth_date, email, phone) FROM stdin;
    public               postgres    false    218   C'       �          0    16407    loans 
   TABLE DATA           Y   COPY public.loans (id, client_id, book_id, loan_date, return_date, returned) FROM stdin;
    public               postgres    false    222   �-       �           0    0    books_id_seq    SEQUENCE SET     <   SELECT pg_catalog.setval('public.books_id_seq', 143, true);
          public               postgres    false    219            �           0    0    clients_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.clients_id_seq', 76, true);
          public               postgres    false    217            �           0    0    loans_id_seq    SEQUENCE SET     ;   SELECT pg_catalog.setval('public.loans_id_seq', 94, true);
          public               postgres    false    221            5           2606    16405    books books_pkey 
   CONSTRAINT     N   ALTER TABLE ONLY public.books
    ADD CONSTRAINT books_pkey PRIMARY KEY (id);
 :   ALTER TABLE ONLY public.books DROP CONSTRAINT books_pkey;
       public                 postgres    false    220            1           2606    16397    clients clients_email_key 
   CONSTRAINT     U   ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_email_key UNIQUE (email);
 C   ALTER TABLE ONLY public.clients DROP CONSTRAINT clients_email_key;
       public                 postgres    false    218            3           2606    16395    clients clients_pkey 
   CONSTRAINT     R   ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (id);
 >   ALTER TABLE ONLY public.clients DROP CONSTRAINT clients_pkey;
       public                 postgres    false    218            7           2606    16413    loans loans_pkey 
   CONSTRAINT     N   ALTER TABLE ONLY public.loans
    ADD CONSTRAINT loans_pkey PRIMARY KEY (id);
 :   ALTER TABLE ONLY public.loans DROP CONSTRAINT loans_pkey;
       public                 postgres    false    222            8           2606    16419    loans loans_book_id_fkey    FK CONSTRAINT     w   ALTER TABLE ONLY public.loans
    ADD CONSTRAINT loans_book_id_fkey FOREIGN KEY (book_id) REFERENCES public.books(id);
 B   ALTER TABLE ONLY public.loans DROP CONSTRAINT loans_book_id_fkey;
       public               postgres    false    222    4661    220            9           2606    16414    loans loans_client_id_fkey    FK CONSTRAINT     }   ALTER TABLE ONLY public.loans
    ADD CONSTRAINT loans_client_id_fkey FOREIGN KEY (client_id) REFERENCES public.clients(id);
 D   ALTER TABLE ONLY public.loans DROP CONSTRAINT loans_client_id_fkey;
       public               postgres    false    222    218    4659            �   ^  x��Y�R�8]���jVӔ巳#0$���PE�Fm�Fؖ�d;{I%5ߐ�/�5�;����fBwӐ��SPT.K��s�j��Ӂ���s�RE�6��TxK��`u�rt�$�<.k��'���߳��r�%��
�~�iys�|��_���/q*3vq�ɜ
��Uo���q۔��OD"?�������R���K�4���kr)ʹ�l�r�	����x脳d�5��>,JZ
�����[�ІHT�.�1�r�x�Ո)!k
��uJB�W2f�VT�x���t>.�N`	�ه��eF/�qI�;��疽+R������R��[&T��c�D�Y��vn�n�o?��S�9}�����8�AOV-�Hh��y��aQȌV��L�@\�^5�;Ϋ������mYӤ��,��k%�o4�x.	����Xͬv��`����w�諪�[��K����^;M��2ҵ�>KhƥhЩ<�(���$|�$�K#�Ó���B�Н÷�Tۖ㠭����7Y��ˏEڠw��C`��7��Q�����7�~�R�p� ����������,�-��z՗!U@	}F�7@�L%MR����K�%��́>yޡ1Px�����	����V�!]�e�D�����
��n��]�6�k7�cdMS�[/.^�W�6g�fx�`P��c�/S2\��4�>A�4�^XP�O1��XZP�0����'����ٝ���ݕ���r��z9��Px�����˦��i��g�i�ά�w�1��n��G�=Q���S4ͷ��Bl���#	����>ƴ��suf�V%�C��% 3��Ae��j���::N36��
Im�ת�">����V2ۑ�����>M؉���j4� �`�I���j��Y��>Ê�Zʴ�o��-B�(D�2��Jq[s���/P
�,^�=��:��Ak�8	
އ�C٪Z9��l@���4���@�� �~���\?�F����P��FU�L<�`H&�uB�;�N�Xn�X^�X>z+^���#���eI��2&�O�����߯D={�����:���c�=_�-U�Ss���p=�Hг#�>�J�L_�g��-z����*���\e˷���Ճ�Z�EzK�X`9�-���7�?�m��m܂^w�w��A[C݈�I�1'�U��g��GdN悖�{�r��Pβ5�����N��Ѧt@E�,��iE�C0豊���]6�D�bMQ܇(�4�oC�W-�q&Q����O��{��s�305o�#o!!���7W�T͗l�� �����5:�x��F�˰��0&;�|�Q��u�e����2��b8�5����n�$���+��լC�h�	���k:���# ���| �]�%(Q&6�@�1�F՗�ު��������p��)�K�=0m�� �D�C$�ץE$0�vi����<q�Mq��*����u5[G��jb���`ZWw[�����{�Y�6K���>��U��^bᜳN��;�G�0^��-�K�o��l��^�;+Nb�e,������\cᚎ-��:Bbj4-��o��.n��c� �7�&��	��zn�a���@u1��S�>�CV��������WiV�      �   0  x�uW�n�F]��? b�$w��4m���4@��HddZ)PRqi���3�lv����9���s�޹�܇�k�E�c������]�Ld��	>������}�ve/�5�\pi�L3+�H�gE��#�uݾuĢg\̸a�L	d����ri�Ɲ��M۹�c7���~�@�$.�θ�ɔ�]5\�W�+#�4Mq_�VE���xd���CK.ə���y��󑭑�*8�#�vw�{�<��ŕoR�8���0�0"KT��N�΢��m�n۱�6�[ы�� S�v�W=2~H���$R�(e7e�t�n�-kz���㸥�q`�H3-97QƮ���e��qA�f� ��toq:�C��i�#<�jY�ŶÛ���ޑ5�	id�,Ώ���De:�<�FE��m��Zv����;�w�OgR�!����B'i�ex���U����6�搃$#�r�=
)��q6��Z�����t.�縹(OBW��L�\��:�ɐ�L[%�"ͮ];w�;͋��=i�r�j�-����x�/ �taD�y�J�9��	���]��+�͐`��v)>7MU�&��Eq��e�7�2O�QҰC�8�X*ml�f���O���C���]�bP���������xb��Td��!��4�o���62�Q � |em���"���e�����}���O�p��
؄��}O"CR_6��������ϥ&։�*�����M�Wxu#�(*�d�F��i
;�T�4{����p�\�W��b�=U��%��:R���oOO��^�uN�7�*��T�C\2&�c��T� �mG��8�T��o�!�P���	�N���H��W��t��	M���Z�*���O�]_��MIJ� �m�8�	q���lAX��>���&����Ǆxj;4�۶(��uAO���&��㱥��)>�+�P�s�̗��9�����=Cpa�,�!A�J#����~��c[���Ӹ�
BH�L�C*gw.oz5�q����b�HkM(�9��gd�*)��}5�JK�
��{��	��	7>�$�u�5]X(Է��W��36!	z0
i�ڎ*�Y�ɸ���];Ac�x1�����F��w���wo!�9ZҹOj//�'��;�4!
�0����4��9�"oLL7@��Cc�a�DƆ	��k���6L�j*-�e��E����w>.��%��*5J��Lʮ�~5�ʼ�N���9E����>�d�%H���x�t����-$~8vǉy����EҸ�6��'yS�	����q����	���8/?ͤI� G+GJz_U�6-u�� J��2��as�V��A�$��m�N��*�f�T%F#�.�����镍���H<}��X�����p��+M2�ئ�E �,:˞W�ZW�Λ�����.?��	KДM�#�6�a����y��XE%��8�%��P��o��E�Qm|��蠌D���0-�b�8����4L�N�ZI$�k1�-�!����?����2H#Qgiߖ���A_����k{S��rb��L�C���&ߖ.�FCQ�%��oz�j�&t���(��Բ!      �   �   x���]!���]4��]<���cv�8��Æo�tZB��+I�U����%��+H�?G�ߕ1�<����i^K���z�v�i�̒80�	;������>�d:�a{d.�x��6q�n��H]���5�����6�?����8�M����}
�q�=",�U�P�,p�A7���*�����S���B�!,�R^���     