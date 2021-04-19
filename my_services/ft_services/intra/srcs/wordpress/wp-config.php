<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress_sql' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql:3306' );

/* WP_SITEURL */
define( 'WP_HOME',    'http://192.168.99.100:5050/' );
define( 'WP_SITEURL', 'http://192.168.99.100:5050/' );


/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

#define('FS_METHOD', 'direct');
/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'TcC{5/w,aR8-Tzwx(T;b;<0`jFi2 ;vRR![K0+S.S@`@dfcHk:`k+?*bF@D{AhGg');
define('SECURE_AUTH_KEY',  'vyprqV?-0d>w&c,Q,7LLsjjb/U ,hv>xL8rfC7K=Ju#@~/7:}YK=piC]-jJdU.58');
define('LOGGED_IN_KEY',    '*~p<E5|5y[YSrgp%bD/@&-ok-=u_PBj-;i8uq(=4^{G/O](h->h|%s[Q$S1FhO/.');
define('NONCE_KEY',        '5>rl~sO} c]nn0R/ZsU_cs[%08k8$!QT%[NVe*/EzDr2d!zLQK28:!txGf+TE]oa');
define('AUTH_SALT',        '$#^=6-^_{k{l1E`rP~+70y5)-~%.pw<n>)x[h-o&>Vu*GO*-+(|5(^-4I.7)p;>5');
define('SECURE_AUTH_SALT', '@pLaU_r0 )K)NZh@~loj^@rhEmHv^<<+8hvqTN+?[y[A>Q]*P<QDR`wT$:? 1OtP');
define('LOGGED_IN_SALT',   'Mwm,[`1[+g19l4cE4>z|&^rPJ|uzyO!t@0d{:eF7Cl2ZUyC$&4K@d4[-)9802i4D');
define('NONCE_SALT',       'k+8m|vn*bO*g-;,zgoY<owP1vbmq-vr&>QK.V6Qc8Q8}^.+QF/OX>VG67Nl-X|!j');
/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
